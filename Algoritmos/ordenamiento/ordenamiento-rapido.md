# Ordenamiento rápido (Quick sort)

El **ordenamiento rápido** usa dividir y conquistar, primero selecciona un valor, que se denomina el valor **pivote**. El papel del valor pivote es ayudar a dividir la lista. La posición real a la que pertenece el valor pivote en la lista final ordenada, comúnmente denominado punto de división, se utilizará para dividir la lista para las llamadas posteriores a la función de ordenamiento rápido.

El particionamiento comienza localizando dos marcadores de posición al principio y al final de los datos restantes de la lista. El objetivo del proceso de partición es mover datos que están en el lado equivocado con respecto al valor pivote mientras que también se converge en el punto de división.

![Quicksort-example](https://user-images.githubusercontent.com/42527034/120588308-9857d500-c3fc-11eb-95b1-f97e991cac3a.gif)

# Análisis de complejidad

Tenga en cuenta que para una lista de longitud n, si la partición siempre ocurre en el centro de la lista, habrá de nuevo **log n** divisiones. Con el fin de encontrar el punto de división, cada uno de los n datos debe ser comparado contra el valor pivote. El resultado es **n log n**. 

Lamentablemente, en el peor de los casos, los puntos de división pueden no estar en el centro y podrían estar muy sesgados a la izquierda o a la derecha, dejando una división muy desigual. En este caso, ordenar una lista de n datos se divide en ordenar una lista de 0 datos y una lista de n−1 datos. Similarmente, ordenar una lista de tamaño n−1 se divide en una lista de tamaño 0 y una lista de tamaño n−2 y así sucesivamente. El resultado es un ordenamiento **O(n^2)** con toda la sobrecarga que requiere la recursión.

### Complejidad en el tiempo
* **Peor caso** : O(n^2)
* **Mejor caso** : O(n log n)
* **Caso promedio** : O(n log n)

### Complejidad de espacio

* La complejidad del espacio es de O(log n).

## Implementación del algoritmo de ordenamiento burbuja en python

```python
def ordenamientoRapido(array):
  primero = 0
  ultimo = len(array) - 1
  ordenamientoRapidoAux(array, primero, ultimo)

def ordenamientoRapidoAux(array, primero, ultimo):
  if primero < ultimo:
    division = particion(array, primero, ultimo)
    ordenamientoRapidoAux(array,primero, division - 1)
    ordenamientoRapidoAux(array, division + 1 , ultimo)

def particion(array, primero, ultimo):
  pivote = array[primero]
  marcaIzq = primero + 1
  marcaDer = ultimo
  hecho = False
  while not hecho:
    while marcaIzq <= marcaDer and array[marcaIzq] <= pivote:
      marcaIzq = marcaIzq + 1
    while marcaDer >= marcaIzq and array[marcaDer] >= pivote:
      marcaDer = marcaDer - 1
    if marcaDer < marcaIzq:
      hecho = True
    else:
      array[marcaIzq], array[marcaDer] = array[marcaDer], array[marcaIzq]
  array[primero], array[marcaDer] = array[marcaDer], array[primero]
  return marcaDer
```

## Referencias

* QuickSort (With Code). (2020). Programiz. https://www.programiz.com/dsa/quick-sort
* 5.12. El ordenamiento rápido — Solución de problemas con algoritmos y estructuras de datos. (2020). runestone. https://runestone.academy/runestone/static/pythoned/SortSearch/ElOrdenamientoRapido.html
