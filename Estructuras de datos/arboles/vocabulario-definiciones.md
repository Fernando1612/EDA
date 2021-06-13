# Árboles

Un **árbol** es una estructura de datos jerárquica no lineal que consta de nodos conectados por aristas.

Otras estructuras de datos como matrices, listas enlazadas, pilas y colas son estructuras de datos lineales que almacenan datos de forma secuencial. Para realizar cualquier operación en una estructura de datos lineal, la complejidad del tiempo aumenta con el aumento del tamaño de los datos.

Las diferentes estructuras de datos de árbol permiten un acceso más rápido y sencillo a los datos, ya que es una estructura de datos no lineal. Un árbol tiene las siguientes propiedades:

* Un nodo del árbol se designa como el nodo raíz.
* Cada nodo n, excepto el nodo raíz, está conectado por una arista que proviene exactamente de otro nodo p, donde p es el padre de n.
* Se recorre una ruta única desde la raíz hasta cada nodo.
* Si cada nodo en el árbol tiene un máximo de dos hijos, decimos que el árbol es un **árbol binario**.

<img width="228" alt="tree_0" src="https://user-images.githubusercontent.com/42527034/120590859-cf2fea00-c400-11eb-9e86-e169e7362ba2.png">

## Vocabulario y definiciones

**Nodo**

Un nodo es una parte fundamental de un árbol. Puede tener un nombre, que llamamos la “clave” y apunta a sus nodos secundarios. Un nodo también puede tener información adicional. Llamamos a esta información adicional la “carga útil”. Aunque la información de carga útil no es central para muchos algoritmos de árboles, a menudo es crítica en aplicaciones que usan árboles.

**Arista**

Una arista es otra parte fundamental de un árbol. Una arista conecta dos nodos para mostrar que hay una relación entre ellos. Cada nodo (excepto la raíz) está conectado por exactamente una arista entrante desde otro nodo. Cada nodo puede tener varias aristas salientes.

**Raíz**

La raíz del árbol es el único nodo en el árbol que no tiene aristas entrantes.

**Ruta**

Una ruta es una lista ordenada de nodos que están conectados por aristas. 

**Hijos**

El conjunto de h nodos que tienen aristas entrantes desde el mismo nodo se dice que son hijos de ese nodo.

**Padre**

Un nodo es el padre de todos los nodos con los que se conecta mediante aristas salientes.

**Hermanos**

Se dice que los nodos del árbol que son hijos del mismo padre son hermanos.

**Subárbol**

Un subárbol es un conjunto de nodos y aristas compuesto por un padre y todos los descendientes de ese padre.

**Nodo hoja**

Un nodo hoja es un nodo que no tiene hijos.

**Nivel o profundidad**

El nivel de un nodo n es el número de aristas en la ruta desde el nodo raíz hasta n. 

**Altura**

La altura de un árbol es igual al máximo nivel de cualquier nodo en el árbol.

## Recorridos de árboles

Hay tres patrones de uso común para visitar todos los nodos de un árbol. La diferencia entre estos patrones es el orden en que es visitado cada nodo. Llamamos a estas visitas de los nodos un “recorrido”. Los tres recorridos se llaman **preorden**, **inorden** y **postorden**. 

**preorden**

En un recorrido en preorden, visitamos primero el nodo raíz, luego recursivamente realizamos un recorrido en preorden del subárbol izquierdo, seguido de un recorrido recursivo en preorden del subárbol derecho.

```python
def preorden(arbol):
  if arbol:
    print(arbol.raiz())
    preorden(arbol.hijoIzquierdo())
    preorden(arbol.hijoDerecho())
```

**inorden**

En un recorrido en inorden, realizamos recursivamente un recorrido en inorden en el subárbol izquierdo, visitamos el nodo raíz, y finalmente hacemos un recorrido recursivo en inorden del subárbol derecho.

```python
def inorden(arbol):
  if arbol:
    inorden(arbol.hijoIzquierdo())
    print(arbol.raiz())
    inorden(arbol.hijoDerecho())
```

**postorden**

En un recorrido en postorden, realizamos recursivamente recorridos en postorden del subárbol izquierdo y del subárbol derecho seguidos de una visita al nodo raíz

```python
def postorden(arbol):
  if arbol:
    postorden(arbol.hijoIzquierdo())
    postorden(arbol.hijoDerecho())
    print(arbol.raiz()
```

## Referencias

* Tree Data Structure. (2020). Programiz. https://www.programiz.com/dsa/trees
* 6.3. Vocabulario y definiciones — Solución de problemas con algoritmos y estructuras de datos. (2020). runestone. https://runestone.academy/runestone/static/pythoned/Trees/VocabularioYDefiniciones.html
