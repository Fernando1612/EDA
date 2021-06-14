# Búsqueda por anchura (Breadth first search)

La búsqueda por anchura o BFS es un algoritmo para buscar todos los vértices de un grafo o estructura de datos de árbol.

Una implementación estándar de BFS coloca cada vértice del grafo en una de dos categorías:

* Visitado
* No visitado

El propósito del algoritmo es marcar cada vértice como visitado evitando ciclos.

El algoritmo funciona de la siguiente manera:

1. Comience colocando cualquiera de los vértices del gráfico en la parte posterior de una cola.
2. Tome el elemento frontal de la cola y agréguelo a la lista de visitas.
3. Cree una lista de los nodos adyacentes de ese vértice. Agregue los que no están en la lista de visitas a la parte posterior de la cola.
4. Siga repitiendo los pasos 2 y 3 hasta que la cola esté vacía.

![BFS](https://user-images.githubusercontent.com/42527034/121826187-11b4ba80-cc7c-11eb-8d39-d00ff33046c3.jpg)

## Análisis de complejidad

* Complejidad en el tiempo es de O(V + E), donde V es el número de vertices y E el número de aristas
* Complejidad de espacio es O(V) 

## Implementación del algoritmo de búsqueda por anchura en python

```python
def bfs(grafo, inicio):
  cola = Cola()
  visitado = set()
  cola.enqueue(inicio)

  while cola.size() > 0:
    vertice = cola.dequeue()
    print(str(vertice) + " ", end="")
    for i in range(grafo.V):
      temp = grafo.grafo[i]
      visitado.add(i)
      
      while temp:
        if temp.vertice not in visitado:
          visitado.add(temp.vertice)
          cola.enqueue(temp.vertice)
        temp = temp.siguiente
```

## Referencias

* BFS Graph Algorithm(With code in C, C++, Java and Python). (2020). Programiz. https://www.programiz.com/dsa/graph-bfs
* 7.9. Implementación de la búsqueda en anchura — Solución de problemas con algoritmos y estructuras de datos. (2020). runestone. https://runestone.academy/runestone/static/pythoned/Graphs/ImplementacionDeLaBusquedaEnAnchura.html
