# Arboles binarios de búsqueda (Binary search tree)

El **árbol de búsqueda binaria** (BST) es una estructura de datos que rápidamente nos permite mantener una lista ordenada de números.

* Se llama árbol binario porque cada nodo de árbol tiene un máximo de dos hijos.
* Se llama árbol de búsqueda porque se puede utilizar para buscar la presencia de un número en el O(log n) tiempo.

Sus propiedades son:

* Todos los nodos del subárbol izquierdo son menores que el nodo raíz
* Todos los nodos del subárbol derecho son más que el nodo raíz
* Ambos subárboles de cada nodo también son BST, es decir, tienen las dos propiedades anteriores.

![simpleBST](https://user-images.githubusercontent.com/42527034/120737184-3c03bc80-c4b3-11eb-816a-d43efc6ffbbc.png)

## Operaciones básicas

* **Put** : Agrega una nueva pareja clave-valor. Si la clave ya está en el árbol, reemplaza el valor anterior por el nuevo.
* **Get** : Dada una clave, devuelva el valor almacenado o None de lo contrario.
* **Delete** : Elimina un pareja clave-valor.
* **Size** : Devuelve el número de parejas clave-valor almacenadas.
* **Inside** : Devuelve True si la clave dada está se encuentra de otra forma devuelve None.

El método **Put** comprobará si el árbol ya tiene una raíz. Si no hay una raíz entonces **Put** creará un nuevo NodoArbol y lo instalará como la raíz del árbol. Si ya existe un nodo raíz, entonces se busca en el árbol de acuerdo con el siguiente algoritmo:

* Comenzando en la raíz del árbol, buscar en el árbol binario comparando la nueva clave con la clave del nodo actual. Si la nueva clave es menor que el nodo actual, buscar en el subárbol izquierdo. Si la nueva clave es mayor que el nodo actual, buscar en el subárbol derecho.
* Cuando no hay hijo izquierdo (o derecho) para buscar, hemos encontrado la posición en el árbol donde se debe instalar el nuevo nodo.
* Para agregar un nodo al árbol, crear un nuevo objeto NodoArbol e insertar el objeto en el punto descubierto en el paso anterior.

El método **Delete** encontrara el nodo que se va a eliminar buscándolo en el árbol. Si el árbol tiene más de un nodo, buscamos el nodo que debe ser eliminado. Si el árbol tiene un solo nodo, significa que estamos eliminando la raíz del árbol, pero debemos comprobar que la clave de la raíz coincida con la clave que se va a eliminar. 

Una vez que hemos encontrado el nodo que contiene la clave que queremos eliminar, hay tres casos que debemos considerar:

* El nodo a eliminar no tiene hijos.
* El nodo a eliminar tiene un solo hijo.
* El nodo a eliminar tiene dos hijos.

### Caso 1

Si el nodo actual no tiene hijos, todo lo que debemos hacer es borrar el nodo y eliminar la referencia a ese nodo en el padre.

### Caso 2

Si un nodo tiene un solo hijo, entonces podemos simplemente promover al hijo para que tome el lugar de su padre.
Hay seis casos a considerar. Dado que los casos son simétricos con respecto a tener un hijo izquierdo o un hijo derecho, simplemente discutiremos el caso en que el nodo actual tiene un hijo izquierdo. La decisión se hace de la siguiente manera:

* Si el nodo actual es un hijo izquierdo, solo necesitamos actualizar la referencia al padre del hijo izquierdo para que apunte al padre del nodo actual y luego actualizar la referencia al hijo izquierdo del padre para que apunte al nodo izquierdo del nodo actual.
* Si el nodo actual es un hijo derecho, solo necesitamos actualizar la referencia al padre del hijo izquierdo para que apunte al padre del nodo actual y luego actualizar la referencia al hijo derecho del padre para que apunte al hijo izquierdo del nodo actual.
* Si el nodo actual no tiene padre, debe ser la raíz. En este caso solo debemos borrar el nodo.

### Caso 3

En el tercer caso, el nodo que se va a eliminar tiene dos hijos. En tal caso, siga los pasos a continuación:

* Obtenga el sucesor en orden de ese nodo.
* Reemplace el nodo con el sucesor en orden.
* Retire el sucesor del orden de su posición original.

![bstdel3](https://user-images.githubusercontent.com/42527034/120744204-1af59880-c4c0-11eb-94d1-5d95de74f1a2.png)

## Análisis de complejidad

### Complejidad en el tiempo
 * Get
    Peor caso : O(n)
    Mejor caso : O(log n)
    Caso promedio : O(log n)
    
 * Put
    Peor caso : O(n)
    Mejor caso : O(log n)
    Caso promedio : O(log n)
    
 * Delete
    Peor caso : O(n)
    Mejor caso : O(log n)
    Caso promedio : O(log n)

### Complejidad de espacio
La complejidad del espacio es de O(n).

## Implementación de un árbol de busqueda binaro en python

```python
class NodoArbol:
  def __init__(self, clave, valor, izquierdo = None, derecho = None, padre = None):
    self.clave = clave
    self.valor = valor
    self.hijoIzquierdo = izquierdo
    self.hijoDerecho = derecho
    self.padre = padre

  def tieneHijoIzquierdo(self):
    return self.hijoIzquierdo
  
  def tieneHijoDerecho(self):
    return self.hijoDerecho
  
  def esHijoIzquierdo(self):
    return self.padre and self.padre.hijoIzquierdo == self

  def esHijoDerecho(self):
    return self.padre and self.padre.hijoDerecho == self

  def esRaiz(self):
    return not self.padre

  def esHoja(self):
    return not (self.hijoDerecho or self.hijoIzquierdo)

  def tieneAlgunHijo(self):
    return self.hijoDerecho or self.hijoIzquierdo
  
  def tieneAmbosHijos(self):
    return self.hijoDerecho and self.hijoIzquierdo

  def reemplazarDatoDeNodo(self, clave, valor, hizq, hder):
    self.clave = clave
    self.valor = valor
    self.hijoIzquierdo = hizq
    self.hijoDerecho = hijoDerecho
    if self.tieneHijoIzquierdo():
      self.hijoIzquierdo.padre = self
    if self.tieneHijoDerecho():
      self.hijoDerecho.padre = self

  def encontrarSucesor(self):
    suc = None
    if self.tieneHijoDerecho():
      suc = self.hijoDerecho.encontrarMin()
    else:
      if self.padre:
        if self.esHijoIzquierdo():
          suc = self.padre
        else:
          self.padre.hijoDerecho = None
          suc = self.padre.encontrarSucesor()
          self.padre.hijoDerecho = self
    return suc

  def encontrarMin(self):
    actual = self
    while actual.tieneHijoIzquierdo():
      actual = actual.hijoIzquierdo
    return actual 
  
  def empalmar(self):
    if self.esHoja():
      if self.esHijoIzquierdo():
        self.padre.hijoIzquierdo = None
      else:
        self.padre.hijoDerecho = None
    elif self.tieneAlgunHijo():
      if self.tieneHijoIzquierdo():
        if self.esHijoIzquierdo():
          self.padre.hijoIzquierdo = self.hijoIzquierdo
        else:
          self.padre.hijoDerecho = self.hijoIzquierdo
        self.hijoIzquierdo.padre = self.padre
      else:
        if self.esHijoIzquierdo():
          self.padre.hijoIzquierdo = self.hijoDerecho
        else:
          self.padre.hijoDerecho = self.hijoDerecho
        self.hijoDerecho.padre = self.padre


class ArbolBinarioBusqueda:
  def __init__ (self):
    self.raiz = None
    self.tamano = 0

  def size(self):
    return self.tamano
  
  def put(self, clave, valor):
    if self.raiz:
      self._put(clave, valor, self.raiz)
    else:
      self.raiz = NodoArbol(clave, valor)
      self.tamano = self.tamano + 1

  def _put(self, clave, valor, nodoActual):
    if clave < nodoActual.clave:
      if nodoActual.tieneHijoIzquierdo():
        self._put(clave, valor, nodoActual.esHijoIzquierdo)
      else:
        nodoActual.hijoIzquierdo = NodoArbol(clave, valor,padre = nodoActual)
        self.tamano = self.tamano + 1 
    elif clave == nodoActual.clave:
      nodoActual.valor = valor
    else:
      if nodoActual.tieneHijoDerecho():
        self._put(clave, valor, nodoActual.hijoDerecho)
      else:
        nodoActual.hijoDerecho = NodoArbol(clave, valor, padre = nodoActual)
        self.tamano = self.tamano + 1 

  def get(self, clave):
    if self.raiz:
      res = self._get(clave, self.raiz)
      if res:
        return res.valor
      else:
        return None
    else:
      return None

  def _get(self, clave, nodoActual):
    if not nodoActual:
      return None
    elif clave == nodoActual.clave:
      return nodoActual
    elif clave < nodoActual.clave:
      return self._get(clave, nodoActual.hijoIzquierdo)
    else:
      return self._get(clave, nodoActual.hijoDerecho)

  def inside(self, clave):
    if self._get(clave, self.raiz):
      return True
    else:
      return False

  def delete(self, clave):
    if self.tamano > 1:
      nodoAEliminar = self._get(clave, self.raiz)
      if nodoAEliminar:
        self.remover(nodoAEliminar)
        self.tamano = self.tamano - 1
      else:
        raise KeyError('Error, la clave no está en el árbol')
    elif self.tamano == 1 and self.raiz.clave == clave:
      self.raiz = None
      self.tamano = self.tamano - 1
    else:
      raise KeyError('Error, la clave no está en el árbol')

  def remover(self, nodoActual):
    if nodoActual.esHoja():
      if nodoActual == nodoActual.padre.hijoIzquierdo:
        nodoActual.padre.hijoIzquierdo = None
      else:
        nodoActual.padre.hijoDerecho = None
    elif nodoActual.tieneAmbosHijos():
      suc = nodoActual.encontrarSucesor()
      suc.empalmar()
      nodoActual.clave = suc.clave
      nodoActual.valor = suc.valor
    else:
      if nodoActual.tieneHijoIzquierdo():
        if nodoActual.esHijoIzquierdo():
          nodoActual.hijoIzquierdo.padre = nodoActual.padre
          nodoActual.padre.hijoIzquierdo = nodoActual.hijoIzquierdo
        elif nodoActual.esHijoDerecho():
          nodoActual.hijoDerecho.padre = nodoActual.padre
          nodoActual.padre.hijoDerecho = nodoActual.hijoIzquierdo
        else:
          nodoActual.reemplazarDatoDeNodo(nodoActual.hijoIzquierdo.clave,
                                          nodoActual.hijoIzquierdo.valor,
                                          nodoActual.hijoIzquierdo.hijoIzquierdo,
                                          nodoActual.hijoDerecho.hijoDerecho)
      else:
        if nodoActual.esHijoIzquierdo():
          nodoActual.hijoDerecho.padre = nodoActual.padre
          nodoActual.padre.hijoIzquierdo = nodoActual.hijoDerecho
        elif nodoActual.esHijoDerecho():
          nodoActual.hijoDerecho.padre = nodoActual.padre
          nodoActual.padre.hijoDerecho = nodoActual.hijoDerecho
        else:
          nodoActual.reemplazarDatoDeNodo(nodoActual.hijoDerecho.clave,
                                          nodoActual.hijoDerecho.valor,
                                          nodoActual.hijoDerecho.hijoIzquierdo,
                                          nodoActual.hijoDerecho.hijoDerecho)

```

## Referencias

* Binary Search Tree. (2020). Programiz. https://www.programiz.com/dsa/binary-search-tree
* 6.14. Implementación de un árbol de búsqueda — Solución de problemas con algoritmos y estructuras de datos. (2020). runestone. https://runestone.academy/runestone/static/pythoned/Trees/ImplementacionArbolBusqueda.html












