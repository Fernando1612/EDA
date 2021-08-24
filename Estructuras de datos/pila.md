# Pila (Stack)

Una **pila** es una colección ordenada de datos en la cual los datos se pueden agregar y eliminar en el extremo llamado "tope".
Este principio de ordenamiento se denomina **LIFO**: último en entrar, primero en salir (**last-in, first-out**). Este brinda un ordenamiento basado en el tiempo de permanencia en la colección. 
Los datos más nuevos están cerca al tope y los más viejos están más cerca de la base.
En términos de programación, poner un elemento en la parte superior de la pila se llama push y quitar un elemento se llama pop.

<img width="407" alt="stack" src="https://user-images.githubusercontent.com/42527034/120229121-1ad07100-c212-11eb-80d6-d9a41f040958.png">

## Operaciones básicas

Una pila es un objeto (un tipo de datos abstracto - TAD) que permite las siguientes operaciones:

* **Push** : agrega un elemento a la parte superior de una pila
* **Pop** : elimina un elemento de la parte superior de una pila
* **IsEmpty** : comprueba si la pila está vacía
* **Size** :  devuelve el número de elementos en la pila
* **Peek** : obtiene el valor del elemento superior sin eliminarlo

## Análisis de complejidad

Las operaciones de push y pop toman un tiempo constante, es decir O(1).

## Implementación de una pila en python

```python
class Pila:
  def __init__(self):
    self.datos = []

  def isEmpty(self):
    return self.datos == []

  def push(self, dato):
    self.datos.append(dato)

  def pop(self):
    return self.datos.pop()

  def peek(self):
    return self.datos[len(self.datos) - 1]

  def size(self):
    return len(self.datos)
```

## Referencias
* 3.5. Implementación de una pila en Python — Solución de problemas con algoritmos y estructuras de datos. (2020). runestone. https://runestone.academy/runestone/static/pythoned/BasicDS/ImplementacionDeUnaPilaEnPython.html
* Stack Data Structure and Implementation in Python, Java and C/C++. (2020). Programiz. https://www.programiz.com/dsa/stack
