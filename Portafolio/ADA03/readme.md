Esta actividad se centró en implementar una Lista Doblemente Ligada usando structs en C para administrar la data de películas del archivo Movie.csv. La lista almacenó los atributos seleccionados de cada película.

Lo crucial fue el desarrollo de las funciones de gestión: la importación inicial de los datos y, sobre todo, las operaciones de búsqueda (por título o por actor). También implementamos las funciones básicas de mantenimiento (CRUD): insertar nuevas películas, eliminar películas por título (con mensaje de confirmación) y actualizar datos específicos de una película después de encontrarla.

🧠 Reflexión Personal (Guía Rápida)

Lo que Aprendí: Finalmente entendí la diferencia práctica de la Lista Doblemente Ligada y cómo usar el puntero prev. Me obligó a dominar el manejo de punteros y structs en C.

Problemas: El reto más grande fue la función de búsqueda que permitía matching parcial, especialmente al buscar por nombre de actor dentro de una cadena de texto (cast), y mantener todos los punteros correctos durante las operaciones de inserción y eliminación.