La tarea principal era construir un programa que actuara como un analizador sintáctico (parser) sencillo. Teníamos que leer expresiones matemáticas normales (infijas) de un archivo y resolverlas.

Para esto, la solución tenía que ser obligatoriamente en dos pasos:

Convertir la expresión de infija a postfija (Notación Polaca Inversa), manejando bien la precedencia y los paréntesis usando una Pila (Stack).

Evaluar la expresión postfija para obtener el resultado.

Al final, teníamos que generar un archivo de salida con la postfija y su resultado final.

Reflexión Personal 

Lo que Aprendí: Entendí por fin la utilidad real de la Pila; antes solo era teoría. Fue clave para reordenar operadores y para calcular el resultado.

Problemas: Lo más difícil fue la lógica de precedencia de operadores en la conversión. Un pequeño error ahí y toda la expresión salía mal. Pasé bastante tiempo depurando cómo trataba los paréntesis y los diferentes niveles de prioridad.