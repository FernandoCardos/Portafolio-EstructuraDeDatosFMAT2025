<<<<<<< HEAD
=======
Esta aplicación consistió en simular una Tabla de Símbolos, una parte vital de cualquier compilador, que almacena identificadores (variables, funciones, etc.). La implementación clave fue una Tabla Hash donde la clave es un string (el nombre del identificador). 
Para el manejo de colisiones, implementamos Encadenamiento (Chaining), es decir, cada índice de la tabla apunta a una Lista Ligada que contiene todos los identificadores que generaron el mismo hash. Las funcionalidades requeridas fueron agregar, buscar y eliminar identificadores y sus atributos asociados.

Reflexión Personal

Lo que Aprendí: Comprendí el rol fundamental de la Tabla Hash en la búsqueda ultra-rápida de variables en un compilador.

Problemas: El reto fue combinar dos estructuras de datos (el array principal de la tabla y las Listas Ligadas en cada índice) y asegurar que las operaciones de la Lista Ligada se ejecutaran correctamente al encontrar una colisión.


# Compilar y ejecutar (Windows)
>>>>>>> 0eec07d (Portafolio)

