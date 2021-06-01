# Lista enlazada simple (Simple Linked List)

Las listas enlazadas son estructuras de datos semejantes a los array salvo que el acceso a un elemento no se hace mediante un indice sino mediante un puntero.
La asignación de memoria es hecha durante la ejecución.

Las listas enlazadas pueden ser utilizadas cuando se necesitan hacer varias operaciones de inserción y eliminación de elementos. 

<img width="630" alt="linked-list-concept_0" src="https://user-images.githubusercontent.com/42527034/120256163-285a1b00-c253-11eb-8f22-d4fd004a370b.png">

## Lista no ordenada

Es una colección de datos en la que cada ítem mantiene una posición relativa con respecto a los demás donde el orden no importa.

![linkedlistunorder](https://user-images.githubusercontent.com/42527034/120277763-150e7600-c27a-11eb-99c2-20bb02e1f9e9.png)

### Operaciones básicas

Una Lista enlazada es un objeto (un tipo de datos abstracto - TAD) que permite las siguientes operaciones:

* **Add** : agrega un nuevo ítem a la lista
* **Remove** : elimina el ítem de la lista
* **IsEmpty** : comprueba si la lista está vacía
* **Size** : devuelve el número de ítems en la lista
* **Search** : busca el ítem en la lista
* **Append** : agrega un nuevo ítem al final de la lista
* **Insert** : agrega un nuevo ítem a la lista en la posición pos
* **Index** :  devuelve la posición del ítem en la lista
* **Pop** : elimina el último ítem de la lista

### Implementación de una lista enlazada simple no ordenada en python

```python
class Nodo:
  def __init__(self, dato_inicial):
    self.dato = dato_inicial
    self.siguiente = None

  def getData(self):
    return self.dato
  
  def setData(self, nuevo_dato):
    self.dato = nuevo_dato

  def getNext(self):
    return self.siguiente

  def setNext(self, nuevo_siguiente):
    self.siguiente = nuevo_siguiente

class UnorderedLinkedList:
  def __init__(self):
    self.head = None 

  def add(self, dato):
    temp = Nodo(dato)
    temp.setNext(self.head)
    self.head = temp

  def remove(self, dato):
    actual = self.head
    prev = None
    encontrado = False

    while not encontrado:
      if actual.getData() == dato:
        encontrado = True
      else:
        prev = actual
        actual = actual.getNext()

    if prev == None:
      self.head = actual.getNext()
    else:
      prev.setNext(actual.getNext())

  def isEmpy(self):
    return self.head == None

  def size(self):
    actual = self.head
    contador = 0
    while actual != None:
      contador += 1
      actual = actual.getNext()
    return contador

  def search(self, dato):
    actual = self.head
    encontrado = False
    while actual != None and not encontrado:
      if actual.getData() == dato:
        encontrado = True
      else:
        actual = actual.getNext()
    return encontrado

  def appendEnd(self, dato):
    actual = self.head
    temp = Nodo(dato)
    if self.head == None:
      temp.setNext(self.head)
      self.head = temp
      return
    while actual.getNext() != None:
      actual = actual.getNext()
    actual.setNext(temp)
    
  def insert(self, pos, dato):
    actual = self.head
    encontrado = False
    temp = Nodo(dato)
    while actual != None and not encontrado:
      if actual.getData() == pos:
        encontrado = True
        temp.setNext(actual.getNext())
        actual.setNext(temp)
        return
      else:
        actual = actual.getNext()
    print("Elemento no encontrado")

  def index(self, dato):
    actual = self.head
    # index = 0 si queremos que empieze en 0
    index = 1
    encontrado = False
    while actual != None and not encontrado:
      if actual.getData() == dato:
        encontrado = True
        return index
      else:
        actual = actual.getNext()
        index += 1
    return

  def pop(self):
    actual = self.head
    prev = None
    while actual.getNext() != None:
      prev = actual
      actual = actual.getNext()

    if prev == None:
      self.head = actual.getNext()
    else:
      prev.setNext(actual.getNext())
```

## Lista ordenada

Es una colección de datos en la que cada ítem mantiene una posición relativa con respecto a los demás donde el orden importa.
El orden es típicamente ascendente o descendente y asumimos que los datos de la lista tienen una operación de comparación significativa que ya está definida.

![orderlinkedlist](https://user-images.githubusercontent.com/42527034/120277821-28b9dc80-c27a-11eb-8344-23b36bc09c39.png)

### Operaciones básicas

* **Add** : agrega un nuevo ítem a la lista, asegurando que el orden se preserve
* **Remove** : elimina el ítem de la lista
* **Search** : busca el ítem en la lista
* **isEmpty** : comprueba si la lista está vacía
* **Size** : devuelve el número de ítems en la lista
* **Index** : devuelve la posición del ítem en la lista
* **Pop** : elimina y el último dato de la lista

### Implementación de una lista enlazada simple ordenada en python

```python
class Nodo:
    def __init__(self,datoInicial):
        self.dato = datoInicial
        self.siguiente = None

    def getData(self):
        return self.dato

    def getNext(self):
        return self.siguiente

    def setData(self,nuevodato):
        self.dato = nuevodato

    def setNext(self,nuevosiguiente):
        self.siguiente = nuevosiguiente


class OrderedLinkedList:
    def __init__(self):
        self.head = None

    def add(self,dato):
        actual = self.head
        previo = None
        detenerse = False
        while actual != None and not detenerse:
            if actual.getData() > dato:
                detenerse = True
            else:
                previo = actual
                actual = actual.getNext()

        temp = Nodo(dato)
        if previo == None:
            temp.setNext(self.head)
            self.head = temp
        else:
            temp.setNext(actual)
            previo.setNext(temp)

    def search(self,dato):
        actual = self.head
        encontrado = False
        detenerse = False
        while actual != None and not encontrado and not detenerse:
            if actual.getData() == dato:
                encontrado = True
            else:
                if actual.getData() > dato:
                    detenerse = True
                else:
                    actual = actual.getNext()

        return encontrado

    def isEmpty(self):
        return self.head == None

    def size(self):
        actual = self.head
        contador = 0
        while actual != None:
            contador += 1
            actual = actual.getNext()

        return contador
    
    """ remove, index, pop """

    def remove(self, dato):
        actual = self.head
        encontrado = False
        while actual != None and not encontrado:
            if actual.getData() == dato:
                encontrado = True
            else:
              prev = actual
              actual = actual.getNext()
        if prev == None:
          self.head = actual.getNext()
        else:
          prev.setNext(actual.getNext())
      
    def index(self, dato):
        actual = self.head
        encontrado = False
        #contador = 0
        contador = 1
        while actual != None and not encontrado:
            if actual.getData() == dato:
                encontrado = True
                return contador
            else:
              contador += 1
              actual = actual.getNext()
        return    
      
    def pop(self):
      actual = self.head
      prev = None
      while actual.getNext() != None:
        prev = actual
        actual = actual.getNext()

      if prev == None:
        self.head = actual.getNext()
      else:
        prev.setNext(actual.getNext())
```

## Análisis de complejidad

El método **isEmpty** es O(1) ya que requiere un paso para comprobar si la referencia de la cabeza es None. **size**, por otro lado, siempre requerirá n pasos ya que no hay forma de saber cuántos nodos hay en la lista enlazada sin recorrerla desde la cabeza hasta el final. Por lo tanto, **size** es O(n). Agregar un dato a una lista no ordenada siempre será O(1) ya que simplemente colocamos el nuevo nodo en la cabeza de la lista enlazada. Sin embargo, **search** y **remove** , así como **add** para una lista ordenada, requieren el proceso de recorrido. Aunque en promedio pueden necesitar recorrer sólo la mitad de los nodos, estos métodos son todos O(n) ya que en el peor de los casos procesarán cada nodo de la lista.

## Referencias

* 3.21. Implementación de una lista no ordenada: Listas enlazadas — Solución de problemas con algoritmos y estructuras de datos. (2020). runestone. https://runestone.academy/runestone/static/pythoned/BasicDS/ImplementacionDeUnaListaNoOrdenadaListasEnlazadas.html
* 3.23. Implementación de una lista ordenada — Solución de problemas con algoritmos y estructuras de datos. (2020). runestone. https://runestone.academy/runestone/static/pythoned/BasicDS/ImplementacionDeUnaListaOrdenada.html
* Linked List Operations: Traverse, Insert and Delete. (2020). Programiz. https://www.programiz.com/dsa/linked-list-operations
