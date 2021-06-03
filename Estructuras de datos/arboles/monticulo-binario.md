# Montículo binario (Binary heap)

La estructura de datos del **montículo binario** es un árbol binario completo que satisface la propiedad del montículo.

Un árbol binario completo es un árbol binario especial en el que

* todos los niveles, excepto posiblemente el último, se llenan
* todos los nodos están lo más a la izquierda posible

La propiedad del montículo es la propiedad de un nodo en el que

* (para max heap) la clave de cada nodo es siempre mayor que sus nodos secundarios y la clave del nodo raíz es la más grande entre todos los demás nodos;
* (para min heap) la clave de cada nodo es siempre más pequeña que los nodos secundarios y la clave del nodo raíz es la más pequeña entre todos los demás nodos.

Debido a que el árbol está completo, el hijo izquierdo de un padre (en la posición **p**) es el nodo que se encuentra en la posición **2p** en la lista. Del mismo modo, el hijo derecho del padre está en la posición **2p+1** en la lista. Para encontrar el padre de cualquier nodo en el árbol, podemos simplemente usar una división. Dado que un nodo esté en la posición **n** en la lista, el padre está en la posición **n/2**.

![heapOrder](https://user-images.githubusercontent.com/42527034/120699501-11dfd980-c476-11eb-8e5a-b2ff3723331d.png)

## Operaciones básicas

* **Insert** : agrega un nuevo ítem al montículo.
* **GetMin** : devuelve el dato con la menor clave.
* **GetMax** : devuelve el dato con la mayor clave.
* **DeleteMin** : elimina el dato con la menor clave.
* **DeleteMax** : elimina el dato con la mayor clave.
* **IsEmpty** : comprueba si el montículo está vacío.
* **Size** : devuelve el número de ítems en el montículo.
* **Heapify** : construye un montículo nuevo a partir de una lista de claves.

## Análisis de complejidad

Anadir un nuevo dato:
* **Mejor caso** : O(1)
* **Peor caso** : O(log n)

## Implementación del montículo binario en python (Max heap)

```python
class MonticuloBinario:
  def __init__(self):
    self.listaMonticulo = [0]
    self.tamanoActual = 0

  def insert(self, k):
    self.listaMonticulo.append(k)
    self.tamanoActual = self.tamanoActual + 1
    self.infiltArriba(self.tamanoActual)

  def getMax(self):
    if self.tamanoActual >= 1:
      return self.listaMonticulo[1]
    else:
      return None

  def deleteMax(self):
    valorSacado = self.listaMonticulo[1]
    self.listaMonticulo[1] = self.listaMonticulo[self.tamanoActual]
    self.tamanoActual = self.tamanoActual - 1 
    self.listaMonticulo.pop()
    self.infiltAbajo(1)
    return valorSacado

  def isEmpty(self):
    return self.tamanoActual == 0

  def size(self):
    return self.tamanoActual

  def heapify(self, lista):
    i = len(lista) // 2
    self.tamanoActual = len(lista)
    self.listaMonticulo = [0] + lista[:]
    while i > 0:
      self.infiltAbajo(i)
      i = i - 1

  def infiltArriba(self, i):
    while i // 2 > 0:
      if self.listaMonticulo[i] > self.listaMonticulo[i // 2]:
        temp = self.listaMonticulo[i // 2]
        self.listaMonticulo[i // 2] = self.listaMonticulo[i]
        self.listaMonticulo[i] = temp
      i = i // 2
  
  def infiltAbajo(self, i):
    while (i * 2) <= self.tamanoActual:
      hm = self.hijoMax(i)
      if self.listaMonticulo[i] < self.listaMonticulo[hm]:
        temp = self.listaMonticulo[i]
        self.listaMonticulo[i] = self.listaMonticulo[hm]
        self.listaMonticulo[hm] = temp
      i = hm 
  
  def hijoMax(self, i):
    if i * 2 + 1 > self.tamanoActual:
      return i * 2
    else:
      if self.listaMonticulo[i * 2] > self.listaMonticulo[i * 2 + 1]:
        return i * 2
      else:
        return i * 2 + 1
```

## Implementación del montículo binario en python (Min heap)

```python
class MonticuloBinario:
  def __init__(self):
    self.listaMonticulo = [0]
    self.tamanoActual = 0

  def insert(self, k):
    self.listaMonticulo.append(k)
    self.tamanoActual = self.tamanoActual + 1
    self.infiltArriba(self.tamanoActual)

  def getMin(self):
    if self.tamanoActual >= 1:
      return self.listaMonticulo[1]
    else:
      return None

  def deleteMin(self):
    valorSacado = self.listaMonticulo[1]
    self.listaMonticulo[1] = self.listaMonticulo[self.tamanoActual]
    self.tamanoActual = self.tamanoActual - 1 
    self.listaMonticulo.pop()
    self.infiltAbajo(1)
    return valorSacado

  def isEmpty(self):
    return self.tamanoActual == 0

  def size(self):
    return self.tamanoActual

  def heapify(self, lista):
    i = len(lista) // 2
    self.tamanoActual = len(lista)
    self.listaMonticulo = [0] + lista[:]
    while i > 0:
      self.infiltAbajo(i)
      i = i - 1

  def infiltArriba(self, i):
    while i // 2 > 0:
      if self.listaMonticulo[i] < self.listaMonticulo[i // 2]:
        temp = self.listaMonticulo[i // 2]
        self.listaMonticulo[i // 2] = self.listaMonticulo[i]
        self.listaMonticulo[i] = temp
      i = i // 2
  
  def infiltAbajo(self, i):
    while (i * 2) <= self.tamanoActual:
      hm = self.hijoMin(i)
      if self.listaMonticulo[i] > self.listaMonticulo[hm]:
        temp = self.listaMonticulo[i]
        self.listaMonticulo[i] = self.listaMonticulo[hm]
        self.listaMonticulo[hm] = temp
      i = hm 
  
  def hijoMin(self, i):
    if i * 2 + 1 > self.tamanoActual:
      return i * 2
    else:
      if self.listaMonticulo[i * 2] < self.listaMonticulo[i * 2 + 1]:
        return i * 2
      else:
        return i * 2 + 1
```

## Referencias

* Heap Data Structure. (2020). Programiz. https://www.programiz.com/dsa/heap-data-structure
* 6.11. Implementación de un montículo binario — Solución de problemas con algoritmos y estructuras de datos. (2020). runestone. https://runestone.academy/runestone/static/pythoned/Trees/ImplementacionDeUnMonticuloBinario.html
