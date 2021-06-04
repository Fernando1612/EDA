# Árbol AVL (AVL tree)

El **árbol AVL** es un árbol de búsqueda binario autoequilibrado en el que cada nodo mantiene un factor de equilibrio de **-1, 0 o +1**.

El árbol AVL recibió su nombre de su inventor Georgy Adelson-Velsky y Landis.

## Factor de quilibrio 

El factor de equilibrio de un nodo en un árbol AVL es la diferencia entre la altura del subárbol izquierdo y la del subárbol derecho de ese nodo.

Factor de equilibrio = (Altura del subárbol izquierdo - Altura del subárbol derecho) o (Altura del subárbol derecho - Altura del subárbol izquierdo)

La propiedad de autoequilibrio de un árbol avl se mantiene mediante el factor de equilibrio. El valor del factor de equilibrio siempre debe ser -1, 0 o +1.

<img width="344" alt="avl-tree-final-tree-1_0_2" src="https://user-images.githubusercontent.com/42527034/120831268-faabf500-c524-11eb-89d6-791b9843061f.png">

## Rotaciones

Con el fin de reequilibrar un árbol AVL vamos a realizar una o más **rotaciones** en el árbol.

En la operación de rotación, las posiciones de los nodos de un subárbol se intercambian.

Hay dos tipos de rotaciones:
* Rotación a la izquierda
* Rotación a la derecha

![rotation](https://user-images.githubusercontent.com/42527034/120833093-01d40280-c527-11eb-9066-96e2094402bb.gif)

Hay ocaciones en las que tendremos que realizar una doble rotación que se compone por:
* Rotación derecha izquierda
* Rotación izquierda derecha 

![double-rotation](https://user-images.githubusercontent.com/42527034/120834050-241a5000-c528-11eb-8379-55c5255f9a9a.PNG)

## Operaciones básicas

* **Put** : Agrega una nueva pareja clave-valor. Si la clave ya está en el árbol, reemplaza el valor anterior por el nuevo.
* **Get** : Dada una clave, devuelva el valor almacenado o None de lo contrario.
* **Delete*** : Elimina un pareja clave-valor.

Método **put**

Dado que todas las claves nuevas se insertan en el árbol como nodos hoja y que sabemos que el factor de equilibrio para una hoja nueva es cero, no hay nuevos requisitos para el nodo que se acaba de insertar. Pero una vez que se agrega la hoja nueva, debemos actualizar el factor de equilibrio de su padre. Esto puede aplicarse recursivamente al abuelo del nuevo nodo, y posiblemente a cada antepasado hasta la raíz del árbol. Dado que se trata de un procedimiento recursivo, examinemos los dos casos base para actualizar los factores de equilibrio:

* La llamada recursiva ha llegado a la raíz del árbol.
* El factor de equilibrio del padre ha sido ajustado a cero. Usted debe convencerse de que una vez que un subárbol tiene un factor de equilibrio cero, entonces el equilibrio de sus nodos ancestrales no cambia.

Método **delete**

Un nodo siempre se elimina como nodo hoja. Después de eliminar un nodo, los factores de equilibrio de los nodos cambian. Para reequilibrar el factor de equilibrio, se realizan rotaciones adecuadas.

* Localizar el nodo a eliminar utilizando recursividad.
* Hay tres casos para eliminar un nodo:
  * Si el nodo a eliminar es el nodo hoja (es decir, no tiene ningún hijo), se elimina.
  * Si el nodo a elimina tiene un hijo, se sustituya el contenido de el nodo a elimina con el de su hijo. Elimine el nodo hijo.
  * Si el nodo a elimina tiene dos hijos, encuentra el sucesor del nodo a eliminar (es decir, nodo con un valor mínimo de clave en el subárbol derecho).
  
Finalmente actualice el factor de equilibrio de forma recursiva y realicé las rotaciones correspondientes para que el árbol este equilibrado.

## Análisis de complejidad

### Complejidad en el tiempo

La complejidad en el tiempo para los diferente métodos del árbol AVL es de O(log n)

## Implementación de un árbol AVL en python

```python
class NodoArbol:
  def __init__(self, llave, valor):
    self.llave = llave
    self.valor = valor
    self.izquierdo = None
    self.derecho = None
    self.altura = 1

class ArbolAVL:
  def put(self, raiz, llave, valor):
    if not raiz:
      return NodoArbol(llave, valor)
    elif llave < raiz.llave:
      raiz.izquierdo = self.put(raiz.izquierdo, llave, valor)
    else:
      raiz.derecho = self.put(raiz.derecho, llave, valor)

    raiz.altura = 1 + max(self.getAltura(raiz.izquierdo), self.getAltura(raiz.derecho))

    factorEquilibrio = self.getEquilibrio(raiz)
    if factorEquilibrio > 1:
      if llave < raiz.izquierdo.llave:
        return self.rotacionDerecha(raiz)
      else:
        root.izquierdo = self.rotacionIzquierda(raiz.izquierdo)
        return self.rotacionDerecha(raiz)
    if factorEquilibrio < -1:
      if llave > raiz.derecho.llave:
        return self.rotacionIzquierda(raiz)
      else:
        raiz.derecho = self.rotacionDerecha(raiz.derecho)
        return self.rotacionIzquierda(raiz)

    return raiz

  def delete(self, raiz, llave):
    if not raiz:
      return raiz
    elif llave < raiz.llave:
      raiz.izquierdo = self.delete(raiz.izquierdo, llave)
    elif llave > raiz.llave:
      raiz.derecho = self.delete(raiz.derecho, llave)
    else:
      if raiz.izquierdo is None:
        temp = raiz.derecho
        raiz = None
        return temp
      elif raiz.derecho is None:
        temp = raiz.izquierdo
        raiz = None
        return temp
      temp = self.getValorMinimo(raiz.derecho)
      raiz.llave = temp.llave
      raiz.derecho = self.delete(raiz.derecho, temp.llave)
    if raiz is None:
      return None
    raiz.altura = 1 + max(self.getAltura(raiz.izquierdo), self.getAltura(raiz.derecho))
    factorEquilibrio = self.getEquilibrio(raiz)

    if factorEquilibrio > 1:
      if self.getEquilibrio(raiz.izquierdo) >= 0:
        return self.rotacionDerecha(raiz)
      else:
        raiz.izquierdo = self.rotacionIzquierda(raiz.izquierdo)
        return self.rotacionDerecha(raiz)
    if factorEquilibrio < -1:
      if self.getEquilibrio(raiz.derecho) <= 0:
        return self.rotacionIzquierda(raiz)
      else:
        raiz.derecho = self.rotacionDerecha(raiz.derecho)
        return self.rotacionIzquierda(raiz)
    return raiz

  def get(self, raiz, llave):
    if not raiz:
      return raiz
    elif llave < raiz.llave:
      raiz.izquierdo = self.get(raiz.izquierdo, llave)
    elif llave > raiz.llave:
      raiz.derecho = self.get(raiz.derecho, llave)
    else:
      print(raiz.valor)

  
  def rotacionIzquierda(self, z):
    y = z.derecho
    T2 = y.izquierdo
    y.izquierdo = z
    z.derecho = T2
    z.altura = 1 + max(self.getAltura(z.izquierdo), self.getAltura(z.derecho))
    y.altura = 1 + max(self.getAltura(y.izquierdo), self.getAltura(y.derecho))
    return y
  
  def rotacionDerecha(self, z):
    y = z.izquierdo
    T3 = y.derecho
    y.derecho = z
    z.izquierdo = T3
    z.altura = 1 + max(self.getAltura(z.izquierdo), self.getAltura(z.derecho))
    y.altura = 1 + max(self.getAltura(y.izquierdo), self.getAltura(y.derecho))
    return y

  def getAltura(self, raiz):
    if not raiz:
      return 0
    return raiz.altura

  def getEquilibrio(self, raiz):
    if not raiz:
      return 0
    return self.getAltura(raiz.izquierdo) - self.getAltura(raiz.derecho)

  def getValorMinimo(self, raiz):
    if root is None or raiz.izquierdo is None:
      return raiz
    return self.getValorMinimo(raiz.izquierdo)
```

## Referencias

* AVL Tree. (2020). Programiz. https://www.programiz.com/dsa/avl-tree
* 6.18. Implementación de un árbol AVL — Solución de problemas con algoritmos y estructuras de datos. (2020). runestone. https://runestone.academy/runestone/static/pythoned/Trees/ImplementacionDeUnArbolAVL.html



