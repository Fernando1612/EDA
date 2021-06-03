# Ordenamiento por mezcla (Merge sort)

El **ordenamiento por mezcla** es un algoritmo recursivo que divide continuamente una lista por la mitad. Si la lista está vacía o tiene un solo dato, se ordena por definición (el caso base). Si la lista tiene más de un dato, dividimos la lista e invocamos recursivamente un ordenamiento por mezcla para ambas mitades. Una vez que las dos mitades están ordenadas, se realiza la operación fundamental, denominada **mezcla**. La mezcla es el proceso de tomar dos listas ordenadas más pequeñas y combinarlas en una sola lista nueva y ordenada. 

![Merge-sort](https://user-images.githubusercontent.com/42527034/120571425-b19e5880-c3df-11eb-9f0e-9563bb7c058d.gif)

## Análisis de complejidad

Debemos considerar los dos procesos distintos que conforman su implementación. En primer lugar, la lista se divide en mitades. Sabemos que podemos dividir una lista por la mitad en un tiempo **log n** donde n es la longitud de la lista. El segundo proceso es la mezcla. Cada dato de la lista se procesará y se colocará en la lista ordenada. Así que la operación de mezcla que da lugar a una lista de tamaño **n** requiere **n** operaciones. El resultado de este análisis es que se hacen **log n** divisiones, cada una de las cuales cuesta **n**  para un total de nlogn operaciones.

### Complejidad en el tiempo

* **Peor caso** : O(n log n).
* **Mejor caso** : O(n log n).
* **Caso promedio** : O(n log n).
### Complejidad de espacio

* La complejidad del espacio es de O(n).

## Implementación del algoritmo de ordenamiento por mezcla en python

```python
def ordenamientoPorMezcla(array):
  if len(array) > 1:
    mitad = len(array) // 2
    mitadIzquierda = array[:mitad]
    mitadDerecha = array[mitad:]
    ordenamientoPorMezcla(mitadIzquierda)
    ordenamientoPorMezcla(mitadDerecha)
    i = 0
    j = 0
    k = 0
    while i < len(mitadIzquierda) and j < len(mitadDerecha):
      if mitadIzquierda[i] < mitadDerecha[j]:
        array[k] = mitadIzquierda[i]
        i = i + 1
      else:
        array[k] = mitadDerecha[j]
        j = j + 1
      k = k + 1
    while i < len(mitadIzquierda):
      array[k] = mitadIzquierda[i]
      i = i + 1
      k = k + 1
    while j < len(mitadDerecha):
      array[k] = mitadDerecha[j]
      j = j + 1
      k = k + 1
```

## Referencias

* Merge Sort (With Code). (2020). Programiz. https://www.programiz.com/dsa/merge-sort
* 5.11. El ordenamiento por mezcla — Solución de problemas con algoritmos y estructuras de datos. (2020). runestone. https://runestone.academy/runestone/static/pythoned/SortSearch/ElOrdenamientoPorMezcla.html
