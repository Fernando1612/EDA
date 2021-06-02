# Búsqueda binaria (Binary search)

La **búsqueda binaria** es un algoritmo de búsqueda para encontrar la posición de un elemento en una matriz ordenada.
En este enfoque, el elemento siempre se busca en medio de una parte de una matriz.
La búsqueda binaria solo se puede implementar en una lista ordenada de elementos. Si los elementos aún no están ordenados, primero debemos ordenarlos.

![binsearch](https://user-images.githubusercontent.com/42527034/120412575-6707d800-c31c-11eb-81f8-67893f58225b.png)

El algoritmo de búsqueda binaria se puede implementar de dos formas que se describen a continuación.

* Método iterativo
* Método recursivo

## Análisis de complejidad

* Complejidad en el tiempo: 
  * Mejor de los casos O(1)
  * Caso promedio O(log N)
  * Peor caso O(log N)
* Complejidad de espacio es O(1)

## Implementación del algoritmo de búsqueda binaria en python (forma iterativa)

```python
def busquedaBinaria(array, dato):
  primero = 0
  ultimo = len(array) - 1
  while primero <= ultimo:
    medio = (primero + ultimo) // 2
    if array[medio] == dato:
      return True
    elif array[medio] < dato:
      primero = medio + 1
    else:
      ultimo = medio - 1 
  return False
```

## Implementación del algoritmo de búsqueda binaria en python (forma recursiva)

```python
def busquedaBinaria(array, dato):
  if len(array) == 0:
    return False
  else:
    medio = len(array) // 2
    if array[medio] == dato:
      return True
    elif array[medio] > dato:
      return busquedaBinaria(array[:medio], dato)
    else:
      return busquedaBinaria(array[medio + 1:], dato)
```

## Referencias

* Binary Search (With Code). (2020). Programiz. https://www.programiz.com/dsa/binary-search
* 5.4. La búsqueda binaria — Solución de problemas con algoritmos y estructuras de datos. (2020). runestone. https://runestone.academy/runestone/static/pythoned/SortSearch/LaBusquedaBinaria.html






