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

##Implementación de una pila en python

```python
```

## Referencias

