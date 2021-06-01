# Lista enlazada

La lista enlazada (ligada o encadenada, "linked list") es una estructura de datos que es una colección de elementos (denominados nodos) dispuestos uno a continuación de otro, cada uno de ellos conectado al siguiente elemnto por un "enlace" o "referencia"

Gracias a la asignación dinámica de memoria, se pueden implementar listas de modo que la memoria física utilizada se corresponda exactamente con el número de elementos de la tabla.

La idea básica consiste en construir una lista cuyos elementos, llamados nodos.

![img1](https://sites.google.com/a/espe.edu.ec/programacion-ii/_/rsrc/1462365992585/home/listas-enlazadas/lista1.png)

Los enlaces se representan por flechas para facilitar la comprensión de la conexion entre dos nodos; ello indica que el enlace tiene la dirección de memoria del siguiente nodo. El último nodo ha de representarse de forma diferente, para significar que este nodo no se enlaza a ningún otro.

Las listas se pueden dividir en cuatro categorías:

- Listas simplemente enlazadas. Cada nodo (elemento) contiene un único enlace que conec-
ta ese nodo al nodo siguiente o nodo sucesor. La lista es eficiente en recorridos directos
(“adelante”).

![img2](https://d33wubrfki0l68.cloudfront.net/114448fd9d9af33238bf2b35ece052d6c43f1d19/8aac3/img/2015/08/lista-enlazada-simple.png)

- Listas doblemente enlazadas. Cada nodo contiene dos enlaces, uno a su nodo predecesor
y el otro a su nodo sucesor. La lista es eficiente tanto en recorrido directo (“adelante”)
como en recorrido inverso (“atrás”).

![img3](https://www.tutorialesprogramacionya.com/javaya/imagentema/foto113.jpg)

- Lista circular simplemente enlazada. Una lista simplemente enlazada en la que el último
elemento (cola) se enlaza al primer elemento (cabeza) de tal modo que la lista puede ser
recorrida de modo circular (“en anillo”).

![img4](https://codigolibre.weebly.com/uploads/5/5/8/1/55818481/1982777_orig.png)

- Lista circular doblemente enlazada. Una lista doblemente enlazada en la que el último
elemento se enlaza al primer elemento y viceversa. Esta lista se puede recorrer de modo
circular (en anillo) tanto en dirección directa (“adelante”) como inversa (“atrás”).

![img5](https://sites.google.com/site/programacionuvmcoyoacan/_/rsrc/1472871583004/listas/listas%204.png)

## Operaciones básicas

- ListaVacia(L)
  - Inicializa la lista L como lista vacía.
- EsVacia(L)    
  - Determina si la lista L está vacía.
- Insertar(L,x,p)
  - Inserta en la lista L un nodo con el campo dato x, delante del nodo de dirección p.
- Localizar(L,x)
  - Devuelve la posición/dirección donde está el campo de información x.
- Suprimir(L,x) 
  - Elimina de la lista el nodo que contiene el dato x.
- Anterior(L,p) 
  - Devuelve la posición/dirección del nodo anterior a p.
- Primero(L)    
  - Retorna la posición/dirección del primer nodo de la lista L.
- Anula(L)      
  - Vacía la lista L.

Estas operaciones son las básicas para manejar listas. En realidad, la decisión de qué operaciones son las básicas depende de las características de la aplicación que se va a realizar con
los datos de la lista.
