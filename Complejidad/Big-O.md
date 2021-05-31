# Notación Big-O

La notación de uso más común para especificar la complejidad asintótica es la notación "O Grande (Big-O)" introducida en 1894 por Paul Bachman. Es el lenguaje y la métrica que usamos para describir la eficiencia de los algoritmos. 

<img width="443" alt="big0" src="https://user-images.githubusercontent.com/42527034/120142296-b5de3200-c1a3-11eb-96b1-37cdb1c60299.png">

**Definición:** f(n) es O(g(n)) si existen los números positivos c y N tales que f(n) =< c*g(n) para todo n >= N

La razón de crecimiento de un algoritmo (de una función matemática) es dominada por el término más grande de la función, eso implica que los otros términos pueden ser despreciados.

**Ejemplos**

* O(2N) se convierte en O(N)
* O(N^2 + N) se convierte en O(N^2)
* O(N + log N) se convierte en O(N)
* O(5*2^N + 1000N^100) se convierte en O(2^N)

De manera creciente, la clasificación de la categoría de complejidad de notacion big-O es la siguiente: 

![Tabla](https://camo.githubusercontent.com/36b05ad8bf1ab0931d60a7cb7ddc60623b353c4278a5d1538b8f5252dc25155f/68747470733a2f2f696d616765732e73717561726573706163652d63646e2e636f6d2f636f6e74656e742f3531653937363232653462303031666430613662626137312f313532313932383136383532352d514d384638375137365456594b4c4f333341304e2f4269672532424f2532424e6f746174696f6e25324253756d6d6172792e6a70673f636f6e74656e742d747970653d696d6167652532466a706567)

Tiempos de ejecución por categoría

![graficaBigO](https://user-images.githubusercontent.com/42527034/120144139-07d48700-c1a7-11eb-89f6-dc1df0174160.png)

## Suma y multiplicación de tiempos de ejecución

Suponga que tiene un algoritmo que tiene dos pasos. ¿Cuándo multiplicas los tiempos de ejecución y cuándo los sumas?

* Si su algoritmo está en la forma **haz esto, entonces, cuando hayas terminado, haz eso**, entonces sume los tiempos de ejecución.
* Si su algoritmo tiene el formato **haga esto cada vez que haga aquello**, entonces multiplique los tiempos de ejecución.

**Ejemplos**

**Suma de tiempos de ejecución O(A + B)**

```python
for a in arrayA:
  print(a)
  
for b in arrayB:
  print(b)
```

**Multiplicación de tiempos de ejecución O(A * B)**

```python
for a in arrayA:
  for b in arrayB:
    print(a + "," + b)
```

## Tiempos de ejecución recursivos

cuando tiene una función recursiva que realiza múltiples llamadas, el tiempo de ejecución a menudo (pero no siempre) se verá como O(ramas^profundidad), donde ramas es el número de veces que cada llamada recursiva se ramifica. 

```python
def f(n):
  if (n <= 1):
    return 1
  return f(n - 1) + f(n - 1)
```

![ffunction](https://user-images.githubusercontent.com/42527034/120214050-8bb75f00-c1f9-11eb-93ec-6c647716676c.PNG)

Por lo tanto su tiempo de ejcución es O(2^N).

## Teorema maestro

El teorema maestro se utiliza para calcular la complejidad temporal de las relaciones de recurrencia (algoritmos de divide y vencerás) de una manera simple y rápida de la forma:

```
T(n) = aT(n/b) + f(n)
donde,
n = tamaño de la entrada
a = número de llamadas recursivas
b = tamaño de cada subproblema. Se asumen todos los subproblemas tener el mismo tamaño.
f(n) = costo del trabajo realizado fuera de la llamada recursiva, que incluye el costo de dividir el problema y costo de fusionar las soluciones

Aqui. a >= 1 y b > 1 son constantes, y f(n) es una función asintóticamente positiva.

Si f(n) = O( n^log_b(a) ), entonces T(n) = O( n^log_b (a) * log n )
```

**Ejemplo**

```
T(n) = 2T(n / 2) + n
Aqui,
a = 3
n/b = n/2
f(n) = n

log_2 (2) = 1 = n
T(n) = O(n log n)
```

**Limitaciones**

El teorema maestro no se puede utlizar si:
* T(n) no es monótona
* f(n) no es un polinomio
* a no es una constante
* a < 1


## Ejemplos

**Ejemplo 1**

```python
def foo(array):
  sum = 0
  product = 1

  for i in range(len(array)):
    sum += array[i]

  for i in range(len(array)):
    product *= array[i]

  print(str(sum) + ", " + str(product))
```
Tiene un tiempo de ejecución de O(N)

**Ejemplo 2**

```python
def imprimirPares(array):
  for i in range(len(array)):
    for j in range(len(array)):
      print(str(array[i]) + ", " + str(array[j]))
```
Tiene un tiempo de ejecución de O(N^2)

**Ejemplo 3**

```python
def imprimirParesDesordenaados(arrayA, arrayB):
  for i in range(len(arrayA)):
    for j in range(len(arrayB)):
      if (arrayA[i] < arrayB[j]):
        print(str(arrayA[i]) + ", " + str(arrayB[i]))
```
Tiene un tiempo de ejecución de O(AB)

**Ejemplo 4**

```python
def esPrimo(n):
  for i in range(2,n):
    if(n % i == 0):
      return False
  return True
```
Tiene un tiempo de ejecución de O(sqrt(N))

**Ejemplo 5**

```python
def fib(n):
  if (n <= 0):
    return 0
  elif (n == 1):
    return 1
  return fib(n - 1) + fib(n - 2)
```
Tiene un tiempo de ejecución de O(2^N)

**Ejemplo 6**

```python
def potenciasDe2(n):
  if (n < 1):
    return 0
  elif (n == 1):
    print(1)
    return 1
  else:
    prev = potenciasDe2(n // 2)
    curr = prev * 2
    print(curr)
    return curr
```
Tiene un tiempo de ejecución de O(log n)

## Referenacias
* Master Theorem (With Examples). (2020). Programiz. https://www.programiz.com/dsa/master-theorem
* McDowell, G. L. (2015). Cracking the Coding Interview: 189 Programming Questions and Solutions (189 Preguntas y soluciones de programación) (6th ed.). Careercup.
* Solución de problemas con algoritmos y estructuras de datos usando Python — Solución de problemas con algoritmos y estructuras de datos. (2020). runestone. https://runestone.academy/runestone/static/pythoned/index.html
