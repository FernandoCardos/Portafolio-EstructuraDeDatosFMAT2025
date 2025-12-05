La tarea fue implementar una Tabla Hash para un registro eficiente de estudiantes, usando su matrícula (clave numérica) como índice.
El valor almacenado es la struct completa del estudiante. El principal desafío fue el manejo de colisiones mediante Direccionamiento Abierto (sondeo lineal o cuadrático). Esto significa que si un slot está ocupado, buscamos la siguiente celda libre en el arreglo. El sistema debía permitir agregar, buscar y eliminar estudiantes rápidamente, verificando siempre que la matrícula sea única.

Reflexión Personal

Lo que Aprendí: Entendí la complejidad del sondeo (probing) y cómo afecta el rendimiento si la tabla se llena demasiado.

Problemas: La parte más complicada fue la lógica de la eliminación en el sondeo lineal o cuadrático, ya que dejar una celda vacía puede romper la cadena de búsqueda subsiguiente.