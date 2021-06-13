# Lista de adyacencia

Una lista de adyacencia representa un grafo como una matriz de listas enlazadas.

El índice de la matriz representa un vértice y cada elemento de su lista enlazada representa los otros vértices que forman una arista con el vértice.

<img width="730" alt="adjacency-list" src="https://user-images.githubusercontent.com/42527034/121818505-478e7a80-cc4d-11eb-83e0-517a74b868ae.png">

Una lista de adyacencia es eficiente en términos de almacenamiento porque solo necesitamos almacenar los valores de las aristas. Para un grafo disperso con millones de vértices y aristas, esto puede significar mucho espacio ahorrado. La lista de adyacencia también nos permite encontrar fácilmente todos los enlaces que están directamente conectados a un vértice particular.

La lista de adyacencia más simple necesita una estructura de datos de nodo para almacenar un vértice y una estructura de datos de grafo para organizar los nodos.

## Implementación de una lista de adyacencia en python

```python
class Nodo:
  def __init__(self, vertice):
    self.vertice = vertice
    self.siguiente = None

class Grafo:
  def __init__(self, size):
    self.V = size
    self.grafo = [None] * self.V

  def agregar_arista(self, v1, v2):
    nodo = Nodo(v2)
    nodo.siguiente = self.grafo[v1]
    self.grafo[v1] = nodo 

    nodo = Nodo(v1)
    nodo.siguiente = self.grafo[v2]
    self.grafo[v2] = nodo 

  def imprimir_grafo(self):
    for i in range(self.V):
      print("Vertice " + str(i) + ":", end="")
      temp = self.grafo[i]
      while temp:
        print(" -> {}".format(temp.vertice), end="")
        temp = temp.siguiente
      print(" \n")
```

## Referencias

* Adjacency List (With Code in C, C++, Java and Python). (2020). Programiz. https://www.programiz.com/dsa/graph-adjacency-list
* 7.5. Una lista de adyacencia — Solución de problemas con algoritmos y estructuras de datos. (2020). runestone. https://runestone.academy/runestone/static/pythoned/Graphs/UnaListaDeAdyacencia.html
