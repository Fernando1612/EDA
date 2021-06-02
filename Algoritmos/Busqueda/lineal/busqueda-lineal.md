# Búsqueda lineal (Linear Search)

La **búsqueda lineal** es el algoritmo de búsqueda más simple que busca un elemento en una lista en orden secuencial. Comenzamos por un extremo y verificamos cada elemento hasta que no se encuentra el elemento deseado.

![seqsearch](https://user-images.githubusercontent.com/42527034/120405969-69176a00-c30f-11eb-9030-6c41c3383e74.png)

## Análisis de complejidad

* Complejidad en el tiempo es de O(N)
* Complejidad de espacio es O(1)

## Implementación del algoritmo de búsqueda lineal en python

```python
def busquedaLineal(array, dato):
  for i in range(len(array)):
    if array[i] == dato:
      return True
  return False
```

## Referencias

* 5.3. La búsqueda secuencial — Solución de problemas con algoritmos y estructuras de datos. (2020). runestone. https://runestone.academy/runestone/static/pythoned/SortSearch/LaBusquedaSecuencial.html
* Linear Search (With Code). (2020). Programiz. https://www.programiz.com/dsa/linear-search
