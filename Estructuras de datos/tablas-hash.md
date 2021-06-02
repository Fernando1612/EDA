# Tablas hash (Hash table)

Una **tabla hash** es una colección de datos que se almacenan de tal manera que sea más fácil encontrarlos más tarde. Cada posición de la tabla hash, a menudo llamada una **ranura** (slot), puede contener un dato y se llama por un valor entero comenzando en 0.

La estructura de datos de la tabla Hash almacena elementos en pares clave-valor donde:
* **Clave** : entero único que se utiliza para indexar los valores.
* **Valor** : datos asociados con claves.

<img width="195" alt="Hash-0" src="https://user-images.githubusercontent.com/42527034/120424733-93c6ea00-c332-11eb-84c7-2ebd948c3045.png">

La correspondencia entre un dato y la ranura a donde pertenece ese dato en la tabla hash se denomina **función hash**. La **función hash** tomará cualquier dato de la colección y devolverá un número entero en el rango de nombres de las ranuras.

## Función hash

Dada una colección de datos, una función hash que asigna cada dato en una ranura única se conoce como una función hash perfecta. Si conociéramos los datos y la colección nunca cambiara, entonces sería posible construir una función hash perfecta. Desafortunadamente, dada una colección arbitraria de datos, no existe una forma sistemática de construir una función hash perfecta. Cuando la función hash asigana la misma ranura para varios datos, habrá un conflicto (qué valor se almacenará en esa ranura). A esto se le llama **colisión**.

![Hash-2_0](https://user-images.githubusercontent.com/42527034/120425388-b3aadd80-c333-11eb-8a49-6450448c4e0c.png)

### Ejemplo de función hash

```
Método del residuo
k = llave
m = tamaño de la tabla hash
h() = función hash
h(k) = k mod m
```

Nuestro objetivo es crear una función hash que minimice el número de colisiones, sea fácil de calcular y distribuya uniformemente los datos en la tabla hash. 
Cuando a dos datos se les asigna la misma ranura, debemos contar con un método sistemático para colocar el segundo dato en la tabla hash. Este proceso se denomina **solución de colisiones**.
Existen varias tecnicas para lograr esto, por ejemplo:

* Resolución de colisiones por encadenamiento
* Direccionamiento abierto: prueba lineal / cuadrática y hash doble

## Operaciones básicas

* **Put** : Agrega una nueva pareja clave-valor a la tabla. Si la clave ya está en la tabla, reemplaza el valor anterior por el nuevo.
* **Get** : Dada una clave, devuelva el valor almacenado en la tabla o None de lo contrario.
* **Delete** : Elimina la pareja clave-valor de la tabla utilizando una clave.
* **Size** : Devuelve el número de parejas clave-valor almacenadas en la tabla.
* **Inside** : Devuelve True si la clave dada está en la tabla, False de lo contrario.

## Análisis de complejidad

En el mejor de los casos las operaciones de busqueda y agregar toman un tiempo O(1)

## Implementación de una tabla hash en python

```python
class TablaHash:
  def __init__(self):
    self.tamano = 11
    self.ranuras = [None] * self.tamano
    self.datos = [None] * self.tamano
  
  def put(self, clave, dato):
    valorHash = self.funcionHash(clave,len(self.ranuras))
    if self.ranuras[valorHash] == None:
      self.ranuras[valorHash] = clave
      self.datos[valorHash] = dato
    else:
      if self.ranuras[valorHash] == clave:
        self.datos[valorHash] = dato
      else:
        proximaRanura = self.rehash(valorHash, len(self.ranuras))
        while self.ranuras[proximaRanura] != None and self.ranuras[proximaRanura] != clave:
          proximaRanura = self.rehash(proximaRanura, len(self.ranuras))
        if self.ranuras[proximaRanura] == None:
          self.ranuras[proximaRanura] = clave
          self.datos[proximaRanura] = dato
        else:
          self.datos[proximaRanura] = dato

  def funcionHash(self, clave, tamano):
    return clave % tamano

  def rehash(self, hashViejo, tamano):
    return (hashViejo + 1) % tamano

  def get(self, clave):
    ranuraInicio = self.funcionHash(clave, len(self.ranuras))
    dato = None
    parar = False
    encontrado = False
    posicion = ranuraInicio
    while self.ranuras[posicion] != None and not encontrado and not parar:
      if self.ranuras[posicion] == clave:
        encontrado = True
        dato = self.datos[posicion]
      else:
        posicion = self.rehash(posicion, len(self.ranuras))
        if posicion == ranuraInicio:
          parar = True
    return dato

  def size(self):
    contador = 0
    for i in self.ranuras:
      if i != None:
        contador += 1
    return contador
  
  def delete(self, clave):
    ranuraInicio = self.funcionHash(clave, len(self.ranuras))
    dato = None
    parar = False
    encontrado = False
    posicion = ranuraInicio
    while self.ranuras[posicion] != None and not encontrado and not parar:
      if self.ranuras[posicion] == clave:
        encontrado = True
        self.ranuras[posicion] = dato
        self.datos[posicion] = dato
        return
      else:
        posicion = self.rehash(posicion, len(self.ranuras))
        if posicion == ranuraInicio:
          parar = True
    return -1

  def inside(self, clave):
    ranuraInicio = self.funcionHash(clave, len(self.ranuras))
    dato = None
    parar = False
    encontrado = False
    posicion = ranuraInicio
    while self.ranuras[posicion] != None and not encontrado and not parar:
      if self.ranuras[posicion] == clave:
        encontrado = True
        return True
      else:
        posicion = self.rehash(posicion, len(self.ranuras))
        if posicion == ranuraInicio:
          parar = True
    return False
```

## Referencias

* Hash Table Data Structure. (2020). Programiz. https://www.programiz.com/dsa/hash-table
* 5.5. Transformación de claves (hashing) — Solución de problemas con algoritmos y estructuras de datos. (2020). runestone. https://runestone.academy/runestone/static/pythoned/SortSearch/TransformacionDeClaves.html
