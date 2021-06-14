# Algoritmo de Bellman Ford

El algoritmo de Bellman Ford nos ayuda a encontrar el camino más corto desde un vértice a todos los demás vértices de un grafo ponderado.

Es similar al algoritmo de Dijkstra, pero puede funcionar con gráficos en los que las aristas pueden tener pesos negativos.

Los bordes de peso negativo pueden crear ciclos de peso negativos, es decir, un ciclo que reducirá la distancia total del trayecto volviendo al mismo punto.
Si hay un ciclo negativo no es posible encontrar la ruta mas corta entre dos vertices.

<img width="730" alt="negative-weight-cycle_1" src="https://user-images.githubusercontent.com/42527034/121926721-dfe73680-cd03-11eb-93ef-7db6e21e330a.png">

Los algoritmos de ruta más corta como el algoritmo de Dijkstra que no son capaces de detectar dicho ciclo pueden dar un resultado incorrecto porque pueden pasar por un ciclo de peso negativo y reducir la longitud de la ruta.

El algoritmo de Bellman Ford funciona sobreestimando la longitud de la ruta desde el vértice inicial hasta todos los demás vértices. Luego disminuye iterativamente esas estimaciones al encontrar nuevos caminos que son más cortos que los caminos previamente sobreestimados.
Al hacer esto repetidamente para todos los vértices, podemos garantizar que el resultado está optimizado.

1. Elija un vértice inicial y asigne valores de ruta infinita a todos los demás vértices.
2. Visite cada borde y disminuya las distancias del camino si son inexactas.
3. Necesitamos hacer esto V veces porque en el peor de los casos, la longitud de la ruta de un vértice podría necesitar ser reajustada V veces.
4. Después de que todos los vértices tienen sus longitudes de trayectoria, verificamos si hay un ciclo negativo 

![bellman-ford](https://user-images.githubusercontent.com/42527034/121932055-060fd500-cd0a-11eb-8d16-67fee73dec76.png)

## Análisis de complejidad

* Complejidad en el tiempo es de O(VE), donde V es el número de vertices y E el número de aristas
* Complejidad de espacio es O(V)

## Implementación del Algoritmo de Bellman Ford en python

```python
class Grafo:
  def __init__(self, vertices):
    self.V = vertices
    self.grafo = []

  def agregar_arista(self, v1, v2, p):
    self.grafo.append([v1, v2, p])

  def imprime_solucion(self, distancia):
    print("Distancia del vértice desde el origen")
    for i in range(self.V):
      print("{0}\t\t{1}".format(i, distancia[i]))

  def bellman_ford(self, origen):
    dist = [float("Inf")] * self.V
    dist[origen] = 0

    for i in range(self.V - 1):
      for v1, v2, p in self.grafo:
        if dist[v1] != float("Inf") and dist[v1] + p < dist[v2]:
          dist[v2] = dist[v1] + p

    for v1, v2, p in self.grafo:
      if dist[v1] != float("Inf") and dist[v1] + p < dist[v2]:
        print("El grafo contine un ciclo negativo")
        return
    
    self.imprime_solucion(dist)
```

## Referencias

* Bellman Ford’s Algorithm. (2020). Programiz. https://www.programiz.com/dsa/bellman-ford-algorithm
* Can Bellman Ford Algorithm have any arbitary order of edges? (2017, 20 enero). Stack Overflow. https://stackoverflow.com/questions/41758089/can-bellman-ford-algorithm-have-any-arbitary-order-of-edges
