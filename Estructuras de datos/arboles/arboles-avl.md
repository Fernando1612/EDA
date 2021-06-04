# Árbol AVL (AVL tree)

El **árbol AVL** es un árbol de búsqueda binario autoequilibrado en el que cada nodo mantiene un factor de equilibrio de **-1, 0 o +1**.

El árbol AVL recibió su nombre de su inventor Georgy Adelson-Velsky y Landis.

## Factor de quilibrio 

El factor de equilibrio de un nodo en un árbol AVL es la diferencia entre la altura del subárbol izquierdo y la del subárbol derecho de ese nodo.

Factor de equilibrio = (Altura del subárbol izquierdo - Altura del subárbol derecho) o (Altura del subárbol derecho - Altura del subárbol izquierdo)

La propiedad de autoequilibrio de un árbol avl se mantiene mediante el factor de equilibrio. El valor del factor de equilibrio siempre debe ser -1, 0 o +1.

<img width="344" alt="avl-tree-final-tree-1_0_2" src="https://user-images.githubusercontent.com/42527034/120831268-faabf500-c524-11eb-89d6-791b9843061f.png">

Dado que todas las claves nuevas se insertan en el árbol como nodos hoja y que sabemos que el factor de equilibrio para una hoja nueva es cero, no hay nuevos requisitos para el nodo que se acaba de insertar. Pero una vez que se agrega la hoja nueva, debemos actualizar el factor de equilibrio de su padre. Esto puede aplicarse recursivamente al abuelo del nuevo nodo, y posiblemente a cada antepasado hasta la raíz del árbol. Dado que se trata de un procedimiento recursivo, examinemos los dos casos base para actualizar los factores de equilibrio:

* La llamada recursiva ha llegado a la raíz del árbol.
* El factor de equilibrio del padre ha sido ajustado a cero. Usted debe convencerse de que una vez que un subárbol tiene un factor de equilibrio cero, entonces el equilibrio de sus nodos ancestrales no cambia.

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

## Análisis de complejidad

## Referencias




