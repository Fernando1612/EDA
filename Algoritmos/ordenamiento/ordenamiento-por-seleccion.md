# Ordenamiento por selección (Selection sort)

El **ordenamiento por selección** mejora el ordenamiento burbuja haciendo un sólo intercambio por cada pasada a través de la lista. Para hacer esto, un ordenamiento por selección busca el valor menor a medida que hace una pasada y, después de completar la pasada, lo pone en la ubicación correcta.

![selction-sort](https://user-images.githubusercontent.com/42527034/120527066-885dd800-c39f-11eb-97de-ee6691f67e30.gif)

## Análisis de complejidad

### Complejidad en el tiempo
* **Peor caso** : si queremos ordenar en orden ascendente y la lista está en orden descendente, entonces ocurre el peor de los casos. O(n^2)
* **Mejor caso** : ocurre cuando la lista ya está ordenada O(n^2)
* **Caso promedio** : ocurre cuando los elementos de la lista están en orden desordenado (ni ascendente ni descendente). O(n^2)

### Complejidad de espacio
* La complejidad del espacio se O(1) ya que se debe utilizar una variable adicional para el intercambio.

## Implementación del algoritmo de ordenamiento por selección en python

```python
def ordenamienroPorSeleccion(array):
  longitud = len(array)
  for i in range(longitud):
    minimo = i
    for j in range(i + 1, longitud):
      if array[j] < array[minimo]:
        minimo = j
    array[i], array[minimo] = array[minimo], array[i]
```

## Referencias

* Selection Sort (With Code). (2020). Programiz. https://www.programiz.com/dsa/selection-sort
* 5.8. El ordenamiento por selección — Solución de problemas con algoritmos y estructuras de datos. (2020). runestone. https://runestone.academy/runestone/static/pythoned/SortSearch/ElOrdenamientoPorSeleccion.html
