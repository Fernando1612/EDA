# Grafos

Una estructura de datos de grafo es una estructura de datos (V, E) que consta de:

* Una colección de vértices V
* Una colección de aristas E, representadas como pares ordenados de vértices (u, v)

<img width="730" alt="graph-vertices-edges_0" src="https://user-images.githubusercontent.com/42527034/121815936-66d1db80-cc3e-11eb-9e71-f4ce73a8d4d6.png">

````
V = {0, 1, 2, 3}
E = {(0,1), (0,2), (0,3), (1,2)}
G = {V, E}
````

## Vocabulario y definiciones

**Vértice**

Un vértice (también llamado “nodo”) es una parte fundamental de un grafo. Puede tener un nombre, que llamaremos “clave”. Un vértice también puede tener información adicional. A esta información adicional la llamaremos “carga útil”.

**Arista**

Una arista (también llamada “arco”) es otra parte fundamental de un grafo. Una arista conecta dos vértices para mostrar que hay una relación entre ellos. Las aristas pueden ser unidireccionales o bidireccionales. Si las aristas de un grafo son todas unidireccionales, decimos que el grafo es un **grafo dirigido** o un **digrafo**.

**Ponderación**

Las aristas pueden ponderarse para mostrar que hay un costo para ir de un vértice a otro. Por ejemplo, en un grafo de carreteras que conectan una ciudad con otra, la ponderación en la arista puede representar la distancia entre las dos ciudades.

**Ruta**

Una ruta en un grafo es una secuencia de aristas que le permite ir del vértice A al vértice B.

**Ciclo**

Un ciclo en un grafo dirigido es una ruta que comienza y termina en el mismo vértice. Un grafo sin ciclos se denomina **grafo acíclico**. Un grafo dirigido sin ciclos se denomina **grafo acíclico dirigido** o **GAD**.

**Adyacencia**

Se dice que un vértice es adyacente a otro vértice si hay una arista que los conecta.

## Representación de un grafo

Los grafos se representan comúnmente de dos formas:

### Matriz de adyacencia

Una matriz de adyacencia es una matriz 2D de vértices V x V. Cada fila y columna representan un vértice.

Si el valor de cualquier elemento a [ i ] [ j ] es 1, representa que hay una arista que conecta el vértice i y el vértice j

<img width="730" alt="adjacency-matrix_1" src="https://user-images.githubusercontent.com/42527034/121816448-4bb49b00-cc41-11eb-9b37-0172e6171e01.png">

### Lista de adyacencia

Una lista de adyacencia representa un grafo como una matriz de listas enlazadas.

El índice de la matriz representa un vértice y cada elemento en su lista enlazada representa los otros vértices que forman una arista con el vértice.

<img width="730" alt="adjacency-list" src="https://user-images.githubusercontent.com/42527034/121816518-c41b5c00-cc41-11eb-930c-5388ba79f26b.png">

## Referencias

Graph Data Structure. (2020). Programiz. https://www.programiz.com/dsa/graph

7.2. Vocabulario y definiciones — Solución de problemas con algoritmos y estructuras de datos. (2020). runestone. https://runestone.academy/runestone/static/pythoned/Graphs/VocabularioYDefiniciones.html


