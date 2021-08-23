# Arboles binarios (Binary tree)

Un **árbol binario** es una estructura de datos de árbol en la que cada nodo padre puede tener como máximo dos hijos.

<img width="208" alt="binary-tree_0" src="https://user-images.githubusercontent.com/42527034/120726766-8169bf00-c49e-11eb-94a4-36d321321ce0.png">

Un nodo de un árbol binario está representado por una estructura que contiene una parte de datos y dos punteros a otras estructuras del mismo tipo.

<img width="298" alt="binary-tree-representation_0" src="https://user-images.githubusercontent.com/42527034/120726822-a52d0500-c49e-11eb-88f3-efea2d7b5864.png">

## Implementación de un árbol binario en python

```python
class ArbolBinario:
  def __init__(self,objetoRaiz):
    self.clave = objetoRaiz
    self.hijoIzquierdo = None
    self.hijoDerecho = None

  def insertarIzquierdo(self, nuevoNodo):
    if self.hijoIzquierdo == None:
      self.hijoIzquierdo = ArbolBinario(nuevoNodo)
    else:
      t = ArbolBinario(nuevoNodo)
      t.hijoIzquierdo = self.hijoIzquierdo
      self.hijoIzquierdo = t

  def insertarDerecho(self, nuevoNodo):
    if self.hijoDerecho == None:
      self.hijoDerecho = ArbolBinario(nuevoNodo)
    else:
      t = ArbolBinario(nuevoNodo)
      t.hijoDerecho = self.hijoDerecho
      self.hijoDerecho = t
  
  def obtenerHijoDerecho(self):
    return self.hijoDerecho

  def obtenerHijoIzquierdo(self):
    return self.hijoIzquierdo
  
  def asignarValorRaiz(self, valor):
    self.clave = valor
  
  def obtenerValorRaiz(self):
    return self.clave
```

## Tipos de árboles binarios

### Full binary tree

Un **Full binary tree** es un tipo especial de árbol binario en el que cada nodo padre / nodo interno tiene dos hijos o ninguno.

![full-binary-tree_0](https://user-images.githubusercontent.com/42527034/120727526-60a26900-c4a0-11eb-8a0c-e0ed94ea9325.png)

### Perfect binary tree

Un **Perfect binary tree** es un tipo de árbol binario en el que cada nodo interno tiene exactamente dos nodos secundarios y todos los nodos hoja están en el mismo nivel.

<img width="288" alt="perfect-binary-tree_0" src="https://user-images.githubusercontent.com/42527034/120727756-f807bc00-c4a0-11eb-86db-f97455f3ce9d.png">

### Complete binary Tree

Un **Complete binary Tree** es un árbol binario en el que todos los niveles están completamente llenos excepto posiblemente el más bajo, que se llena desde la izquierda.
Un **complete binary Tree** es como un **full binary tree**, pero con dos diferencias principales

* Todos los elementos de la hoja deben inclinarse hacia la izquierda.
* Es posible que el último elemento de la hoja no tenga un hermano derecho, es decir, un **complete binary Tree** no tiene que ser un **full binary tree**.

![complete-binary-tree_0](https://user-images.githubusercontent.com/42527034/120728369-5e410e80-c4a2-11eb-8615-a19bda5634a9.png)

### Degenerate or Pathological Tree

Un **Degenerate or Pathological Tree** es el árbol que tiene un solo hijo a la izquierda o a la derecha.

<img width="168" alt="degenerate-binary-tree_0" src="https://user-images.githubusercontent.com/42527034/120728429-8466ae80-c4a2-11eb-86b3-f8f566b8a75c.png">

### Skewed Binary Tree

Un **Skewed Binary Tree** es un **Degenerate or Pathological Tree** en el que el árbol está dominado por los nodos de la izquierda o los nodos de la derecha. Por lo tanto, hay dos tipos de árboles binarios sesgados: árbol binario sesgado a la izquierda y árbol binario sesgado a la derecha.

<img width="328" alt="skewed-binary-tree_0" src="https://user-images.githubusercontent.com/42527034/120728544-cdb6fe00-c4a2-11eb-905e-28579020a387.png">

### Balanced binary tree

Un **Balanced binary tree**, se define como un árbol binario en el que la altura del subárbol izquierdo y derecho de cualquier nodo difiere en no más de 1.
Las condiciones para un **Balanced binary tree** son:

* La diferencia entre el subárbol izquierdo y derecho para cualquier nodo no es más de uno.
* el subárbol izquierdo está equilibrado
* el subárbol derecho está equilibrado

Las diferecencias se calculan restando la altura del hijo izquierdo con la altura del hijo derecho **df = altura hijo izquierdo - altura hijo derecho**.

<img width="298" alt="balanced-binary-tree" src="https://user-images.githubusercontent.com/42527034/120729464-d1e41b00-c4a4-11eb-9967-baf7ee49e3c6.png">

## Referencias

* Binary Tree. (2020). Programiz. https://www.programiz.com/dsa/binary-tree
* 6.6. Nodos y referencias — Solución de problemas con algoritmos y estructuras de datos. (2020). runestone. https://runestone.academy/runestone/static/pythoned/Trees/NodosYReferencias.html
