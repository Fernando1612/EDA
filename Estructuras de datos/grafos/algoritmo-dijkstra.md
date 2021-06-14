# Algoritmo de Dijkstra

El algoritmo de Dijkstra es un algoritmo iterativo que nos proporciona la ruta más corta desde un nodo inicial particular a todos los otros nodos en el grafo. Funciona sobre la base de que cualquier subtrazado del camino más corto entre los vértices A y D es también el camino más corto entre los vértices B y D.
 
Djikstra usó esta propiedad en la dirección opuesta, es decir, sobreestimamos la distancia de cada vértice desde el vértice inicial. Luego visitamos cada nodo y sus vecinos para encontrar el subtrayecto más corto a esos vecinos.

El algoritmo utiliza un enfoque codicioso en el sentido de que encontramos la siguiente mejor solución con la esperanza de que el resultado final sea la mejor solución para todo el problema.

1. Marca el nodo inicial que elegiste con una distancia actual de 0 y el resto con infinito.
2. Establece el nodo no visitado con la menor distancia actual como el nodo actual A.
3. Para cada vecino V de tu nodo actual A: suma la distancia actual de A con el peso de la arista que conecta a A con V. Si el resultado es menor que la distancia actual de V, establécelo como la nueva distancia actual de V.
4. Marca el nodo actual A como visitado.
5. Si hay nodos no visitados, ve al paso 2.

Es importante tener en cuenta que el algoritmo de Dijkstra funciona sólo cuando todas las ponderaciones son positivas. Convénzase de que el algoritmo nunca terminaría si usted introduce una ponderacion negativa en una de las aristas del grafo.

![djikstra](https://user-images.githubusercontent.com/42527034/121945731-b89b6400-cd19-11eb-9ff2-8215ee8125de.png)

## Análisis de complejidad

* Complejidad en el tiempo es de O(E log V), donde V es el número de vertices y E el número de aristas
* Complejidad de espacio es O(V)

## Implementación del algoritmo de Dijkstra en python

```python
import collections
import math

class Grafo:
  def __init__(self):
    self.vertices = set()
    self.aristas = collections.defaultdict(list)
    self.peso = {}
  
  def agregar_vertice(self, vertice):
    self.vertices.add(vertice)

  def agregar_arista(self, de_vertice, a_vertice, distancia):
    if de_vertice == a_vertice:
      pass
    self.aristas[de_vertice].append(a_vertice)
    self.peso[(de_vertice, a_vertice)] = distancia

def dijkstra(grafo, inicio):
  s = set()
  delta = dict.fromkeys(list(grafo.vertices), math.inf)
  previo = dict.fromkeys(list(grafo.vertices), None)
  delta[inicio] = 0
  while s != grafo.vertices:
    v = min((set(delta.keys()) - s), key = delta.get)
    for vecino in set(grafo.aristas[v]) - s:
      nueva_ruta = delta[v] + grafo.peso[v, vecino]
      if nueva_ruta < delta[vecino]:
        delta[vecino] = nueva_ruta
        previo[vecino] = v
    s.add(v)
  return (delta, previo)

```


## Referencias

* 7.20. El algoritmo de Dijkstra — Solución de problemas con algoritmos y estructuras de datos. (2020). runestone. https://runestone.academy/runestone/static/pythoned/Graphs/ElAlgoritmoDeDijkstra.html
* Algoritmo de Dijkstra - Proyecto Inicio. (2020). sites. https://sites.google.com/site/grupo28upm/home/algoritmo-de-dijkstra
* Dijkstra’s Algorithm. (2020). Programiz. https://www.programiz.com/dsa/dijkstra-algorithm
* Dijkstra’s Algorithm (commented). (2020). Gist. https://gist.github.com/alexhwoods/cfa4197724a01580a68971ec25f6dbd9
