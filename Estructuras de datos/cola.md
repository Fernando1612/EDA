# Cola (Queue)

Una **Cola** es una colección ordenada de datos donde la adición de nuevos datos tiene lugar en uno de los extremos, denominado "final", y la eliminación de datos existentes ocurre en el otro extremo, comúnmente llamado "frente". Un elemento ingresa a la cola por el final y espera hasta el momento que un dato sea eliminado para avanzar hacia el frente.
El dato más recientemente agregado en la cola debe esperar al final de la colección. El dato que ha permanecido más tiempo en la colección está en el frente. Este principio de ordenamiento se denomina **FIFO (first-in first-out)**, también conocido como el primero en entrar es el primero en ser salir.
En términos de programación, poner elementos en la cola se llama enqueue y eliminar elementos de la cola se llama dequeue.

<img width="946" alt="queue" src="https://user-images.githubusercontent.com/42527034/120232521-54f14100-c219-11eb-8d10-dc0b0a65fb3a.png">

## Operaciones básicas

Una cola es un objeto (una estructura de datos abstracta - TAD) que permite las siguientes operaciones:

* **Enqueue** : agrega un elemento al final de la cola
* **Dequeue** : eliminar un elemento del principio de la cola
* **IsEmpty** : comprueba si la cola está vacía
* **Size** : devuelve el número de elementos en la cola
* **Peek** : obtenga el valor del frente de la cola sin eliminarlo

## Análisis de complejidad

La operación enqueue toma un tiempo de O(1) y la operación dequeue toma un tiempo de O(n).

## Implementación de una cola en python

```python
class Cola:
  def __init__(self):
    self.datos = []

  def enqueue(self, dato):
    self.datos.append(dato)

  def dequeue(self):
    if len(self.datos) < 1:
      return None
    return self.datos.pop(0)

  def isEmpty(self):
    return self.datos == []
  
  def size(self):
    return len(self.datos)
  
  def peek(self):
    if len(self.datos) < 1:
      return None
    return self.datos[0]
```

## Referencias

* 3.10. ¿Qué es una cola? — Solución de problemas con algoritmos y estructuras de datos. (2020). runestone. https://runestone.academy/runestone/static/pythoned/BasicDS/QueEsUnaCola.html
* Queue Data Structure and Implementation in Java, Python and C/C++. (2020). Programiz. https://www.programiz.com/dsa/queue
