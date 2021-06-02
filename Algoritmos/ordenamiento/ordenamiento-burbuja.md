# Ordenamiento burbuja (Bubble sort)

El **ordenamiento burbuja** hace múltiples pasadas a lo largo de una lista. Compara los datos adyacentes e intercambia los que no están en orden. Cada pasada a lo largo de la lista ubica el siguiente valor más grande en su lugar apropiado. 

![bubble-sort](https://user-images.githubusercontent.com/42527034/120520258-31ed9b00-c399-11eb-86d6-c3979eed0d99.gif)

# Análisis de complejidad

Para analizar el ordenamiento burbuja, debemos tener en cuenta que independientemente de cómo están dispuestos los datos en la lista inicial, se harán **n−1** pasadas para ordenar una lista de tamaño **n**. El número total de comparaciones es la suma de los primeros **n−1** enteros. Recuerde que la suma de los primeros **n** números enteros es **(1/2)n^2 + (1/2)n**. La suma de los primeros **n-1** enteros es **(1/2)n^2 + (1/2)n - n**, que es igual a **(1/2)n^2−(1/2)n**. Esto es todavía **O(n^2)** comparaciones. En el mejor de los casos, si la lista ya está ordenada, no se realizarán intercambios. Sin embargo, en el peor de los casos, cada comparación causará un intercambio. En promedio, intercambiamos la mitad de las veces.

### Complejidad en el tiempo
* **Peor caso** : si queremos ordenar en orden ascendente y la lista está en orden descendente, entonces ocurre el peor de los casos. O(n^2)
* **Mejor caso** : si la matriz ya está ordenada, no hay necesidad de ordenarla. O(n)
* **Caso promedio** : ocurre cuando los elementos de la matriz están en orden desordenado (ni ascendente ni descendente). O(n^2)

### Complejidad de espacio
* La complejidad del espacio se O(1) ya que se debe utilizar una variable adicional para el intercambio.

## Implementación del algoritmo de ordenamiento burbuja en python

```python
def ordenamientoBurbuja(array):
  for i in range(len(array)):
    for j in range(0, len(array) - i -1):
      if array[j] > array[j + 1]:
        array[j],array[j+1] = array[j+1], array[j]

```

## Referencias

* 5.7. El ordenamiento burbuja — Solución de problemas con algoritmos y estructuras de datos. (2020). runestone. https://runestone.academy/runestone/static/pythoned/SortSearch/ElOrdenamientoBurbuja.html#tbl-bubbleanalysis
* Bubble Sort (With Code). (2020). Programiz. https://www.programiz.com/dsa/bubble-sort
