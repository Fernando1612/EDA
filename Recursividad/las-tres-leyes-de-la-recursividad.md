# Las tres leyes de la recursividad

Todos los algoritmos recursivos deben obedecer tres leyes importantes:

* Un algoritmo recursivo debe tener un **caso base**.
* Un algoritmo recursivo debe cambiar su estado y moverse hacia el caso base.
* Un algoritmo recursivo debe llamarse a sí mismo, recursivamente.

Un caso base es la condición que permite que el algoritmo detenga la recursividad. Un caso base es típicamente un problema que es lo suficientemente pequeño como para resolverlo directamente.
Para obedecer la segunda ley, debemos organizar un cambio de estado que mueva el algoritmo hacia el caso base. Un cambio de estado significa que se modifican algunos datos que el algoritmo está usando. Por lo general, los datos que representan nuestro problema se hacen más pequeños de alguna manera.
La última ley es que el algoritmo debe llamarse a sí mismo. Esta es la definición misma de la recursividad.
Cuando hablamos de recursividad, puede parecer que estamos hablando en círculos. Tenemos un problema que resolver con una función, ¡pero esa función resuelve el problema llamándose a sí misma! Pero la lógica no es circular en absoluto; la lógica de la recursividad es una expresión elegante de resolver un problema al descomponerlo en problemas más pequeños y más fáciles.

## Referencias

* 4.4. Las tres leyes de la recursividad — Solución de problemas con algoritmos y estructuras de datos. (2020). runestone. https://runestone.academy/runestone/static/pythoned/Recursion/LasTresLeyesDeLaRecursividad.html
