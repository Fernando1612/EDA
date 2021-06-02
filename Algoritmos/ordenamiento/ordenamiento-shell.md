# Ordenamiento de shell (Shell sort)

El **ordenamiento de Shell**, a veces llamado “ordenamiento de incremento decreciente”, mejora el ordenamiento por inserción al romper la lista original en varias sublistas más pequeñas, cada una de las cuales se ordena mediante un ordenamiento por inserción. La manera única en que se eligen estas sublistas es la clave del ordenamiento de Shell. En lugar de dividir la lista en sublistas de ítems contiguos, el ordenamiento de Shell usa un incremento i, a veces denominado **brecha**, para crear una sublista eligiendo todos los datos que están separados por i datos.

![shellsortA](https://user-images.githubusercontent.com/42527034/120552812-53f91480-c3bd-11eb-960a-40ecb3ac8d3b.png)

![shellsortB](https://user-images.githubusercontent.com/42527034/120552846-5fe4d680-c3bd-11eb-902a-fc30024b8b9e.png)

## Análisis de complejidad

### Complejidad en el tiempo
* **Peor caso** : menor o igual a O(n^2)
* **Mejor caso** : ocurre cuando la lista ya está ordenada O(n log n)
* **Caso promedio** : O(n log n)
* 
La complejidad depende de la brecha elegida.

### Complejidad de espacio
* La complejidad del espacio es de O(1).

## Implementación del algoritmo de ordenamiento de shell en python

```python
def ordenamientoDeShell(array):
  contadorSublistas = len(array) // 2
  while contadorSublistas > 0:
    for i in range(contadorSublistas):
      brecha(array, i, contadorSublistas)
    contadorSublistas = contadorSublistas // 2

def brecha(array, inicio, contador):
  for i in range(inicio + contador, len(array), contador):
    valorActual = array[i]
    posicion = i
    while posicion >= contador and array[posicion - contador] > valorActual:
      array[posicion] = array[posicion - contador]
      posicion = posicion - contador
    array[posicion] = valorActual
```

## Referencias

* Shell Sort (With Code). (2020). Programiz. https://www.programiz.com/dsa/shell-sort
* 5.10. El ordenamiento de Shell — Solución de problemas con algoritmos y estructuras de datos. (2020). runestone. https://runestone.academy/runestone/static/pythoned/SortSearch/ElOrdenamientoDeShell.html
