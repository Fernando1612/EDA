# Árboles binarios de búsqueda (Binary search tree)

El **árbol de búsqueda binaria** (BST) es una estructura de datos que rápidamente nos permite mantener una lista ordenada de números.

* Se llama árbol binario porque cada nodo de árbol tiene un máximo de dos hijos.
* Se llama árbol de búsqueda porque se puede utilizar para buscar la presencia de un número en el O(log n) tiempo.

Sus propiedades son:

* Todos los nodos del subárbol izquierdo son menores que el nodo raíz
* Todos los nodos del subárbol derecho son más que el nodo raíz
* Ambos subárboles de cada nodo también son BST, es decir, tienen las dos propiedades anteriores.

![simpleBST](https://user-images.githubusercontent.com/42527034/120737184-3c03bc80-c4b3-11eb-816a-d43efc6ffbbc.png)

## Operaciones básicas

* **Put** : Agrega una nueva pareja clave-valor. Si la clave ya está en el vector asociativo, reemplaza el valor anterior por el nuevo.
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

* Complejidad en el tiempo
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

* Complejidad de espacio
La complejidad del espacio es de O(n).

## Implementación de un árbol de busqueda binaro en python

```python
```

## Referencias















