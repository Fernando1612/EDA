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

