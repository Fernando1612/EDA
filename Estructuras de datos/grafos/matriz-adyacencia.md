# Matriz de adyacencia

Una de las maneras más fáciles de implementar un grafo es usar una matriz bidimensional. En esta implementación de matriz, cada una de las filas y columnas representa un vértice en el grafo. 

El tamaño de la matriz es VxV donde V es el número de vértices en el gráfico y el valor de una entrada A [ i ] [ j ] es 1 o 0 dependiendo de si hay una arista desde el vértice i al vértice j. 

<img width="730" alt="adjacency-matrix_1" src="https://user-images.githubusercontent.com/42527034/121817567-c7b1e180-cc47-11eb-93ea-972a4d0f6ee7.png">

La ventaja de la matriz de adyacencia es que es simple, y que para grafos pequeños es fácil ver qué nodos están conectados a otros nodos.

La matriz de adyacencia es una buena implementación para un grafo cuando el número de aristas es grande.

## Implementación de una matriz de adyacencia en python

```python
class Grafo():
  def __init__(self, size):
    self.adjMatriz = []
    for i in range(size):
      self.adjMatriz.append([0 for i in range(size)])
    self.size = size

  def agregar_arista(self, v1, v2):
    if v1 == v2:
      print("Son el mismo vertice")
    self.adjMatriz[v1][v2] = 1
    self.adjMatriz[v2][v1] = 1

  def eliminar_arista(self, v1, v2):
    if self.adjMatriz[v1][v2] == 0:
      print("No hay arista entre esos vertices")
      return
    self.adjMatriz[v1][v2] = 0
    self.adjMatriz[v2][v1] = 0

  def imprimir_matriz(self):
    for i in self.adjMatriz:
      for j in i:
        print("\t", j, end=" ")
      print()
```

## Referencias 

* Graph Adjacency Matrix (With code examples in C++, Java and Python). (2020). Programiz. https://www.programiz.com/dsa/graph-adjacency-matrix
* 7.4. Una matriz de adyacencia — Solución de problemas con algoritmos y estructuras de datos. (2020). runestone. https://runestone.academy/runestone/static/pythoned/Graphs/UnaMatrizDeAdyacencia.html

