# Ordenamiento por inserción (Insertion sort)

El **ordenamiento por inserción** consta de tomar uno por uno los elementos de una lista y recorrerla hacia su posición con respecto a los anteriormente ordenados. Así empieza con el segundo elemento y lo ordena con respecto al primero. Luego sigue con el tercero y lo coloca en su posición ordenada con respecto a los dos anteriores, así sucesivamente hasta recorrer todas las posiciones del arreglo.

![insertion-sprt](https://user-images.githubusercontent.com/42527034/120535323-792f5800-c3a8-11eb-8255-4e19f2905f79.gif)

## Análisis de complejidad

### Complejidad en el tiempo

* **Peor caso** : suponga que una lista está en orden descendente y desea ordenarla en orden ascendente. En este caso, ocurre la complejidad del peor de los casos. Cada elemento debe compararse con cada uno de los otros elementos, por lo que, para cada enésimo elemento, se realiza un número de comparaciones. Por tanto, el número total de comparaciones  O(n2)
* **Mejor caso** : cuando la matriz ya está ordenada, el bucle externo se ejecuta nvarias veces, mientras que el bucle interno no se ejecuta en absoluto. Entonces, solo hay un nnúmero de comparaciones. Por tanto, la complejidad es lineal. O(n)
* **Caso promedio** : ocurre cuando los elementos de una matriz están en orden desordenado (ni ascendente ni descendente). O(n^2)

### Complejidad de espacio

La complejidad de espacio es de O(1) debido a que **llave** se utiliza como una variable adicional.

## Implementación del algoritmo de ordenamiento por inserción en python

```python
def ordenamientoPorInsercion(array):
  for i in range(1, len(array)):
    llave = array[i]
    posicion = i - 1
    while posicion >= 0 and llave < array[posicion]:
      array[posicion + 1] = array[posicion]
      posicion = posicion - 1
    array[posicion + 1] = llave 
```

## Referencias

* 5.9. El ordenamiento por inserción — Solución de problemas con algoritmos y estructuras de datos. (2020). runestone. https://runestone.academy/runestone/static/pythoned/SortSearch/ElOrdenamientoPorInsercion.html
* Insertion Sort (With Code). (2020). Programiz. https://www.programiz.com/dsa/insertion-sort
