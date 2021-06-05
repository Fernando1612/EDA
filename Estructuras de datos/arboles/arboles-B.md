# Árbol B (B-tree)

El **árbol b** es un tipo especial de árbol de búsqueda autoequilibrado en el que cada nodo puede contener más de una clave y puede tener más de dos hijos. Es una forma generalizada del árbol de búsqueda binaria .

También se lo conoce como árbol de altura equilibrada en **m**.

<img width="588" alt="b-tree" src="https://user-images.githubusercontent.com/42527034/120852405-c72a9400-c53f-11eb-94d8-182781917dcb.png">

La necesidad de B-tree surgió con el aumento de la necesidad de menos tiempo para acceder a los medios de almacenamiento físicos como un disco duro. Los dispositivos de almacenamiento secundarios son más lentos y tienen una mayor capacidad. Era necesario contar con este tipo de estructuras de datos que minimizaran los accesos al disco.

Otras estructuras de datos, como un árbol de búsqueda binario, un árbol avl, un árbol rojo-negro, etc., pueden almacenar solo una clave en un nodo. Si tiene que almacenar una gran cantidad de llaves, entonces la altura de dichos árboles se vuelve muy grande y el tiempo de acceso aumenta.

Sin embargo, B-tree puede almacenar muchas claves en un solo nodo y puede tener varios nodos secundarios. Esto disminuye la altura significativamente permitiendo accesos al disco más rápidos.

## Propiedades 
Un árbol-B de orden M (el máximo número de hijos que puede tener cada nodo) es un árbol que satisface las siguientes propiedades:

* Cada nodo tiene como máximo M hijos.
* Cada nodo (excepto raíz) tiene como mínimo (M/2) claves.
* La raíz tiene al menos 2 hijos si no es un nodo hoja. (según M)
* Todos los nodos hoja aparecen al mismo nivel
* Un nodo no hoja con k hijos contiene k-1 elementos almacenados.
* Los hijos que cuelgan de la raíz (r1, ···, rm) tienen que cumplir ciertas condiciones:
   * El primero tiene valor menor que r1.
   * El segundo tiene valor mayor que r1 y menor que r2, etc.
   * El último hijo tiene valor mayor que rm.

## Operaciones básicas
* **Put** : Agrega una nueva clave. Si la clave ya está en el árbol, reemplaza el valor anterior por el nuevo.
* **Get** : Dada una clave, devuelva True si la clave existe o False de lo contrario.
* **Delete** : Elimina la clave.

### Método Put

La inserción de un elemento en un árbol B consta de dos eventos: buscar el nodo apropiado para insertar el elemento y dividir el nodo si es necesario. La operación de inserción siempre tiene lugar en el enfoque de abajo hacia arriba.

* Realizando una búsqueda en el árbol, se halla el nodo hoja en el cual debería ubicarse el nuevo elemento.
* Si el nodo hoja tiene menos elementos que el máximo número de elementos legales, entonces hay lugar para uno más. Inserte el nuevo elemento en el nodo, respetando el orden de los elementos.
* De otra forma, el nodo debe ser dividido en dos nodos. La división se realiza de la siguiente manera:
  * Se escoge el valor medio entre los elementos del nodo y el nuevo elemento.
  * Los valores menores que el valor medio se colocan en el nuevo nodo izquierdo, y los valores mayores que el valor medio se colocan en el nuevo nodo derecho; el valor medio        actúa como valor separador.
  * El valor separador se debe colocar en el nodo padre, lo que puede provocar que el padre sea dividido en dos, y así sucesivamente.

<img width="718" alt="insertion" src="https://user-images.githubusercontent.com/42527034/120870192-e6d0b500-c55d-11eb-8132-d9f85fe298ff.png">

### Método Get

La búsqueda de un elemento en un árbol B es la forma generalizada de buscar un elemento en un árbol de búsqueda binaria. Se siguen los siguientes pasos.

* Comenzando desde el nodo raíz, compare k con la primera clave del nodo.
* Si k = primer clave del nodo, devuelve el nodo y el índice.
* Si k.hoja = true, regresa NULO (es decir, no encontrado).
* Si k < primer clave del nodo, busque el hijo izquierdo de esta clave de forma recursiva.
* Si hay más de una clave en el nodo actual y k > primer clave del nodo, compare k con la siguiente clave en el nodo.
* Si k < siguiente clave, busque el hijo izquierdo de esta clave (es decir, k se encuentra entre la primera y la segunda clave).
* De lo contrario, busque el hijo correcto de la clave.
* Repita los pasos 1 a 4 hasta alcanzar la hoja.

### Método Delete

La eliminación de un elemento en un árbol B consta de tres eventos principales: buscar el nodo donde existe la clave a eliminar , eliminar la clave y equilibrar el árbol si es necesario.

Al eliminar un nodo de un árbol, puede ocurrir una condición llamada subdesbordamiento . El subdesbordamiento se produce cuando un nodo contiene menos de la cantidad mínima de claves que debería contener.

* **Predecesor de orden** : 
La clave más grande en el hijo izquierdo de un nodo se llama su predecesor de orden.
* **Sucesor de orden** : 
La clave más pequeña del hijo derecho de un nodo se denomina sucesora de orden.

Hay tres casos principales para la operación de eliminación en un árbol B.

#### Caso I

La clave a eliminar está en la hoja. Hay dos casos para ello.

* La eliminación de la clave no viola la propiedad del número mínimo de claves que debe tener un nodo y solo se elimina.

<img width="588" alt="delete-leaf-1" src="https://user-images.githubusercontent.com/42527034/120877843-53f44280-c57e-11eb-8c51-a7f808c12fa7.png">

* La eliminación de la clave viola la propiedad del número mínimo de claves que debe tener un nodo. En este caso, tomamos prestada una clave de su nodo hermano vecino inmediato   en el orden de izquierda a derecha.
  Primero, visite al hermano izquierdo inmediato. Si el nodo hermano izquierdo tiene más de un número mínimo de claves, entonces tome prestada una clave de este nodo.
  De lo contrario, marque para pedir prestado del nodo hermano derecho inmediato.
  
  <img width="588" alt="delete-leaf-2" src="https://user-images.githubusercontent.com/42527034/120877878-7be3a600-c57e-11eb-84f1-708c6eb9a2e9.png">
  
  Si ambos nodos hermanos inmediatos ya tienen un número mínimo de claves, fusionar el nodo con el nodo hermano izquierdo o el nodo hermano derecho. Esta fusión se realiza a       través del nodo padre.
  
  <img width="588" alt="delete-leaf-3" src="https://user-images.githubusercontent.com/42527034/120877885-89009500-c57e-11eb-9cc5-8a7e94d3c601.png">

#### Caso II

Si la clave a eliminar se encuentra en el nodo interno, ocurren los siguientes casos.

* El nodo interno, que se elimina, se reemplaza por un predecesor en orden si el hijo izquierdo tiene más de la cantidad mínima de claves.

<img width="588" alt="delete-internal-1" src="https://user-images.githubusercontent.com/42527034/120877801-20b1b380-c57e-11eb-8293-1b6291ae13b1.png">

* El nodo interno, que se elimina, se reemplaza por un sucesor en orden si el hijo correcto tiene más de la cantidad mínima de claves.
* Si alguno de los hijos tiene exactamente un número mínimo de llaves, combine los hijos izquierdo y derecho.

<img width="588" alt="delete-internal-2" src="https://user-images.githubusercontent.com/42527034/120877812-2c9d7580-c57e-11eb-9ed3-6b1d545795b6.png">

Después de fusionar, si el nodo padre tiene menos del número mínimo de claves, busque los hermanos como en el Caso I.

#### Caso III

En este caso, la altura del árbol se reduce. Si la clave de destino se encuentra en un nodo interno, y la eliminación de la clave conduce a un número menor de claves en el nodo (es decir, menos del mínimo requerido), busque el predecesor en orden y el sucesor en orden. Si ambos hijos contienen un número mínimo de llaves, no se podrá realizar el préstamo. Esto conduce al caso II (3), es decir, la fusión de los hijos.

Nuevamente, busque al hermano para que le preste una llave. Pero, si el hermano también tiene solo un número mínimo de claves, combine el nodo con el hermano junto con el padre. Organice a los hijos en consecuencia (orden creciente).

<img width="584" alt="delete-internal_3" src="https://user-images.githubusercontent.com/42527034/120877791-11326a80-c57e-11eb-9d8a-0ed9b45265c2.png">

## Análisis de complejidad

#### Get
* **Complejidad en el timepo** : O(log n)

* **Complejidad de espacio** : O(n)

#### Put
* **Complejidad en el timepo** : O(log n)

* **Complejidad de espacio** : O(n)

#### Delete
* **Complejidad en el timepo** : O(log n)

* **Complejidad de espacio** : O(n)

#### Implementación de árbol b en python

```python
class BTreeNode:
    def __init__(self, leaf=False):
        self.leaf = leaf
        self.keys = []
        self.child = []

class BTree:
    def __init__(self, t):
        self.root = BTreeNode(True)
        self.t = t

    def insert(self, k):
        root = self.root
        if len(root.keys) == (2 * self.t) - 1:
            temp = BTreeNode()
            self.root = temp
            temp.child.insert(0, root)
            self.split_child(temp, 0)
            self.insert_non_full(temp, k)
        else:
            self.insert_non_full(root, k)

    def insert_non_full(self, x, k):
        i = len(x.keys) - 1
        if x.leaf:
            x.keys.append((None, None))
            while i >= 0 and k[0] < x.keys[i][0]:
                x.keys[i + 1] = x.keys[i]
                i -= 1
            x.keys[i + 1] = k
        else:
            while i >= 0 and k[0] < x.keys[i][0]:
                i -= 1
            i += 1
            if len(x.child[i].keys) == (2 * self.t) - 1:
                self.split_child(x, i)
                if k[0] > x.keys[i][0]:
                    i += 1
            self.insert_non_full(x.child[i], k)

    def split_child(self, x, i):
        t = self.t
        y = x.child[i]
        z = BTreeNode(y.leaf)
        x.child.insert(i + 1, z)
        x.keys.insert(i, y.keys[t - 1])
        z.keys = y.keys[t: (2 * t) - 1]
        y.keys = y.keys[0: t - 1]
        if not y.leaf:
            z.child = y.child[t: 2 * t]
            y.child = y.child[0: t - 1]

    def search_key(self, k, x=None):
        if x is not None:
            i = 0
            while i < len(x.keys) and k > x.keys[i][0]:
                i += 1
            if i < len(x.keys) and k == x.keys[i][0]:
                return (x, i)
            elif x.leaf:
                return None
            else:
                return self.search_key(k, x.child[i])
        else:
            return self.search_key(k, self.root)

    def delete(self, x, k):
        t = self.t
        i = 0
        while i < len(x.keys) and k[0] > x.keys[i][0]:
            i += 1
        if x.leaf:
            if i < len(x.keys) and x.keys[i][0] == k[0]:
                x.keys.pop(i)
                return
            return

        if i < len(x.keys) and x.keys[i][0] == k[0]:
            return self.delete_internal_node(x, k, i)
        elif len(x.child[i].keys) >= t:
            self.delete(x.child[i], k)
        else:
            if i != 0 and i + 2 < len(x.child):
                if len(x.child[i - 1].keys) >= t:
                    self.delete_sibling(x, i, i - 1)
                elif len(x.child[i + 1].keys) >= t:
                    self.delete_sibling(x, i, i + 1)
                else:
                    self.delete_merge(x, i, i + 1)
            elif i == 0:
                if len(x.child[i + 1].keys) >= t:
                    self.delete_sibling(x, i, i + 1)
                else:
                    self.delete_merge(x, i, i + 1)
            elif i + 1 == len(x.child):
                if len(x.child[i - 1].keys) >= t:
                    self.delete_sibling(x, i, i - 1)
                else:
                    self.delete_merge(x, i, i - 1)
            self.delete(x.child[i], k)

    def delete_internal_node(self, x, k, i):
        t = self.t
        if x.leaf:
            if x.keys[i][0] == k[0]:
                x.keys.pop(i)
                return
            return

        if len(x.child[i].keys) >= t:
            x.keys[i] = self.delete_predecessor(x.child[i])
            return
        elif len(x.child[i + 1].keys) >= t:
            x.keys[i] = self.delete_successor(x.child[i + 1])
            return
        else:
            self.delete_merge(x, i, i + 1)
            self.delete_internal_node(x.child[i], k, self.t - 1)

    def delete_predecessor(self, x):
        if x.leaf:
            return x.pop()
        n = len(x.keys) - 1
        if len(x.child[n].keys) >= self.t:
            self.delete_sibling(x, n + 1, n)
        else:
            self.delete_merge(x, n, n + 1)
        self.delete_predecessor(x.child[n])

    def delete_successor(self, x):
        if x.leaf:
            return x.keys.pop(0)
        if len(x.child[1].keys) >= self.t:
            self.delete_sibling(x, 0, 1)
        else:
            self.delete_merge(x, 0, 1)
        self.delete_successor(x.child[0])

    def delete_merge(self, x, i, j):
        cnode = x.child[i]

        if j > i:
            rsnode = x.child[j]
            cnode.keys.append(x.keys[i])
            for k in range(len(rsnode.keys)):
                cnode.keys.append(rsnode.keys[k])
                if len(rsnode.child) > 0:
                    cnode.child.append(rsnode.child[k])
            if len(rsnode.child) > 0:
                cnode.child.append(rsnode.child.pop())
            new = cnode
            x.keys.pop(i)
            x.child.pop(j)
        else:
            lsnode = x.child[j]
            lsnode.keys.append(x.keys[j])
            for i in range(len(cnode.keys)):
                lsnode.keys.append(cnode.keys[i])
                if len(lsnode.child) > 0:
                    lsnode.child.append(cnode.child[i])
            if len(lsnode.child) > 0:
                lsnode.child.append(cnode.child.pop())
            new = lsnode
            x.keys.pop(j)
            x.child.pop(i)

        if x == self.root and len(x.keys) == 0:
            self.root = new

    def delete_sibling(self, x, i, j):
        cnode = x.child[i]
        if i < j:
            rsnode = x.child[j]
            cnode.keys.append(x.keys[i])
            x.keys[i] = rsnode.keys[0]
            if len(rsnode.child) > 0:
                cnode.child.append(rsnode.child[0])
                rsnode.child.pop(0)
            rsnode.keys.pop(0)
        else:
            lsnode = x.child[j]
            cnode.keys.insert(0, x.keys[i - 1])
            x.keys[i - 1] = lsnode.keys.pop()
            if len(lsnode.child) > 0:
                cnode.child.insert(0, lsnode.child.pop())
```

## Referencias 

* B-tree. (2020). Programiz. https://www.programiz.com/dsa/b-tree
* Insertion into a B-tree. (2020). Programiz. https://www.programiz.com/dsa/insertion-into-a-b-tree
* Deletion from a B-tree. (2020). Programiz. https://www.programiz.com/dsa/deletion-from-a-b-tree
* colaboradores de Wikipedia. (2021, 11 enero). Árbol-B. Wikipedia, la enciclopedia libre. https://es.wikipedia.org/wiki/%C3%81rbol-B
