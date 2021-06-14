# Búsqueda por profundidad (Depth First Search)

La búsqueda por anchura o BFS es un algoritmo recursivo para buscar todos los vértices de un grafo o estructura de datos de árbol.

Una implementación DFS estándar coloca cada vértice del gráfico en una de dos categorías:

* Visitado
* No visitado

El propósito del algoritmo es marcar cada vértice como visitado evitando ciclos.

El algoritmo DFS funciona como sigue:

1. Comience por colocar cualquiera de los vértices del grafo en la parte superior de una pila.
2. Tome el elemento superior de la pila y agréguelo a la lista de visitas.
3. Cree una lista de los nodos adyacentes de ese vértice. Agregue los que no están en la lista de visitas a la parte superior de la pila.
4. Siga repitiendo los pasos 2 y 3 hasta que la pila esté vacía.

![DFS](https://user-images.githubusercontent.com/42527034/121834190-bee6fd00-cc93-11eb-8ec4-6f7b3b767ee0.jpg)

## Análisis de complejidad

* Complejidad en el tiempo es de O(V + E), donde V es el número de vertices y E el número de aristas
* Complejidad de espacio es O(V)

## Implementación del algoritmo de búsqueda por profundidad en python

## Referencias
