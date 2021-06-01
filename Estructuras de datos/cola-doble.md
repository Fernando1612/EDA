# Cola doble (Deque)

Una **cola doble**, es una colección ordenada de datos similar a la cola. Tiene dos extremos, 
frente y final, y los datos permanecen posicionados en la colección. Lo que hace a una cola doble diferente es la naturaleza no restringida de las operaciones 
de agregar y remover datos. Los ítems nuevos se pueden agregar en el frente o en el final. Del mismo modo, los datos existentes se pueden eliminar de cualquier extremo. 
En cierto sentido, esta estructura lineal híbrida proporciona todas las capacidades de las pilas y las colas en una única estructura de datos. 
Es importante tener en cuenta que a pesar que las colas dobles pueden asumir muchas de las características de las pilas y de las colas, ellas no requieren 
los ordenamientos **LIFO** y **FIFO** que son respetados por esas estructuras de datos.

<img width="637" alt="deque" src="https://user-images.githubusercontent.com/42527034/120251881-7e759100-c248-11eb-8b51-dec3a114d3df.png">

## Operaciones básicas

Una cola doble es un objeto (un tipo de datos abstracto - TAD) que permite las siguientes operaciones:

* **addFront** : añade un nuevo elemento al frente de la cola doble.
* **addRear** : añade un nuevo elemento al final de la cola doble. 
* **removeFront** : elimina el elemento que está al frente de la cola doble.
* **removeRear** : elimina el elemento que está al final de la cola doble.
* **isEmpty** : comprueba si la cola doble está vacía.
* **Size** : devuelve el número de elementos en la cola doble.

## Análisis de complejidad

Las operaciones de addRear y removeRear toman un tiempo constante, es decir O(1) mientras que addFront y removeFront toman un tiempo de O(n).

## Implementación de una cola doble en python

```python
class ColaDoble:
  def __init__(self):
    self.datos = []

  def addFront(self, dato):
    self.datos.insert(0, dato)
  
  def addRear(self, dato):
    self.datos.append(dato)

  def removeFront(self):
    return self.datos.pop(0)
  
  def removeRear(self):
    return self.datos.pop()

  def isEmpty(self):
    return self.datos == []

  def size(self):
    return len(self.datos)
```

## Referencias

* 3.15. ¿Qué es una cola doble? — Solución de problemas con algoritmos y estructuras de datos. (2020). runestone. https://runestone.academy/runestone/static/pythoned/BasicDS/QueEsUnaColaDoble.html
* Deque Data Structure. (2020). Programiz. https://www.programiz.com/dsa/deque
