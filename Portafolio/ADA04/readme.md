Esta ADA se enfocó en crear un Sistema de Gestión de Estudiantes usando un Árbol Binario de Búsqueda (ABB) implementado en C. La matrícula numérica fue la clave para ordenar y buscar en el árbol, y usamos structs con arreglos dinámicos para las calificaciones de cada alumno.

El objetivo fue implementar un CRUD completo (insertar, eliminar y actualizar una nota) y varias funciones de reporte. Estas incluían listar por matrícula, filtrar por promedio de calificación (≥70 o <70) y operaciones avanzadas del árbol, como mostrar los nodos de un nivel específico y generar una representación gráfica.

Reflexión Personal

Lo que Aprendí: Profundicé en la recursividad necesaria para recorrer y mantener el ordenamiento en el ABB. Entendí la utilidad de los arreglos dinámicos dentro de structs para datos variables.

Problemas: El mayor desafío fue la función de eliminación de nodos (el caso del nodo con dos hijos me tomó mucho tiempo) y también realizar los reportes basados en el promedio, ya que implicaba un cálculo dentro del recorrido.