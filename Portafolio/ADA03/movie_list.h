#ifndef MOVIE_LIST_H
#define MOVIE_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_STRING_LENGTH 256
#define FILE_NAME "Movie.csv"

typedef struct Movie {
    char id[20];
    char title[MAX_STRING_LENGTH];
} Movie;

typedef struct Node {
    Movie data;
    struct Node* next;
    struct Node* prev;
} Node;

static void to_lower_case(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

static Node* create_node(Movie movie) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) return NULL;
    new_node->data = movie;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

int import_data(Node** head, const char* filename);
void insert_movie_at_head(Node** head, Movie movie);
void search_by_title(Node* head, const char* title);
int delete_movie(Node** head, const char* title, Movie* deleted_movie);
int update_movie_data(Node* head, const char* title);
void print_movie_info(Movie movie);
void print_list(Node* head);
void free_list(Node* head);

// --- Implementaciones ---

int import_data(Node** head, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) return -1;
    char line[MAX_LINE_LENGTH];
    int imported_count = 0;
    
    if (fgets(line, sizeof(line), file) == NULL) { fclose(file); return 0; }
    
    while (fgets(line, sizeof(line), file)) {
        Movie new_movie = {0};
        char* token;
        char temp_line[MAX_LINE_LENGTH];
        strncpy(temp_line, line, MAX_LINE_LENGTH);
        temp_line[MAX_LINE_LENGTH - 1] = '\0';
        temp_line[strcspn(temp_line, "\n")] = 0;
        
        token = strtok(temp_line, ",");
        int field_index = 0;
        
        // El bucle lee solo hasta el índice 1 (el título)
        while (token != NULL && field_index < 2) {
            switch (field_index) {
                case 0: strncpy(new_movie.id, token, sizeof(new_movie.id) - 1); break;
                case 1: strncpy(new_movie.title, token, sizeof(new_movie.title) - 1); break;
                default: break;
            }
            token = strtok(NULL, ",");
            field_index++;
        }
        
        if (strlen(new_movie.title) > 0) {
            Node* new_node = create_node(new_movie);
            if (!new_node) { fclose(file); return -1; }
            if (*head == NULL) { *head = new_node; } 
            else { new_node->next = *head; (*head)->prev = new_node; *head = new_node; }
            imported_count++;
        }
    }
    fclose(file);
    return imported_count;
}

void insert_movie_at_head(Node** head, Movie movie) {
    Node* new_node = create_node(movie);
    if (!new_node) return;
    if (*head == NULL) { *head = new_node; } 
    else { new_node->next = *head; (*head)->prev = new_node; *head = new_node; }
}

void print_movie_info(Movie movie) {
    printf("\n--- Informacion de la Pelicula ---\n");
    printf("  ID: %s\n", movie.id);
    printf("  Titulo: %s\n", movie.title);
    printf("-----------------------------------\n");
}

void print_list(Node* head) {
    if (head == NULL) { printf("La lista de peliculas esta vacia.\n"); return; }
    printf("\n*** LISTA COMPLETA DE PELICULAS ***\n");
    Node* current = head;
    int count = 0;
    while (current != NULL) {
        printf("[%d] ID: %s | Titulo: %s\n", 
               ++count, current->data.id, current->data.title);
        current = current->next;
    }
    printf("*********************************\n");
}

void search_by_title(Node* head, const char* title) {
    char lower_search_term[MAX_STRING_LENGTH];
    char lower_current_title[MAX_STRING_LENGTH];
    strncpy(lower_search_term, title, MAX_STRING_LENGTH - 1); lower_search_term[MAX_STRING_LENGTH - 1] = '\0'; to_lower_case(lower_search_term);
    Node* current = head;
    int found_count = 0;
    printf("\nBuscando peliculas con titulo que contiene: '%s'...\n", title);
    while (current != NULL) {
        strncpy(lower_current_title, current->data.title, MAX_STRING_LENGTH - 1); lower_current_title[MAX_STRING_LENGTH - 1] = '\0'; to_lower_case(lower_current_title);
        if (strstr(lower_current_title, lower_search_term) != NULL) { print_movie_info(current->data); found_count++; }
        current = current->next;
    }
    if (found_count == 0) printf("No se encontro ninguna pelicula con ese titulo o coincidencia parcial.\n");
    else printf("Busqueda finalizada. Encontradas %d pelicula(s).\n", found_count);
}

int delete_movie(Node** head, const char* title, Movie* deleted_movie) {
    char lower_search_term[MAX_STRING_LENGTH];
    char lower_current_title[MAX_STRING_LENGTH];
    strncpy(lower_search_term, title, MAX_STRING_LENGTH - 1); lower_search_term[MAX_STRING_LENGTH - 1] = '\0'; to_lower_case(lower_search_term);
    Node* current = *head;
    Node* node_to_delete = NULL;
    while (current != NULL) {
        strncpy(lower_current_title, current->data.title, MAX_STRING_LENGTH - 1); lower_current_title[MAX_STRING_LENGTH - 1] = '\0'; to_lower_case(lower_current_title);
        if (strstr(lower_current_title, lower_search_term) != NULL) { node_to_delete = current; break; }
        current = current->next;
    }
    if (node_to_delete == NULL) return 0;
    *deleted_movie = node_to_delete->data;
    if (node_to_delete->prev != NULL) { node_to_delete->prev->next = node_to_delete->next; } 
    else { *head = node_to_delete->next; }
    if (node_to_delete->next != NULL) { node_to_delete->next->prev = node_to_delete->prev; }
    free(node_to_delete);
    return 1;
}

int update_movie_data(Node* head, const char* title) {
    char lower_search_term[MAX_STRING_LENGTH];
    char lower_current_title[MAX_STRING_LENGTH];
    strncpy(lower_search_term, title, MAX_STRING_LENGTH - 1); lower_search_term[MAX_STRING_LENGTH - 1] = '\0'; to_lower_case(lower_search_term);
    Node* current = head;
    Node* node_to_update = NULL;
    while (current != NULL) {
        strncpy(lower_current_title, current->data.title, MAX_STRING_LENGTH - 1); lower_current_title[MAX_STRING_LENGTH - 1] = '\0'; to_lower_case(lower_current_title);
        if (strstr(lower_current_title, lower_search_term) != NULL) { node_to_update = current; break; }
        current = current->next;
    }
    if (node_to_update == NULL) return 0;
    printf("\nPelicula encontrada: %s. Informacion actual:\n", node_to_update->data.title);
    print_movie_info(node_to_update->data);
    int choice;
    printf("Que dato de '%s' desea modificar?\n", node_to_update->data.title);
    printf("1. Titulo\nIngrese su opcion: ");
    if (scanf("%d", &choice) != 1) return 0;
    char new_string[MAX_STRING_LENGTH];
    while (getchar() != '\n');
    switch (choice) {
        case 1: printf("Ingrese el nuevo Titulo: "); if (fgets(new_string, sizeof(new_string), stdin) == NULL) return 0; new_string[strcspn(new_string, "\n")] = 0; strncpy(node_to_update->data.title, new_string, MAX_STRING_LENGTH - 1); printf("Titulo actualizado.\n"); break;
        default: printf("Opcion no valida.\n"); return 0;
    }
    return 1;
}

void free_list(Node* head) {
    Node* current = head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

#endif