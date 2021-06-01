# Recursividad

La **recursividad** es un método para resolver problemas que implica descomponer un problema en subproblemas más y más pequeños hasta llegar a un problema lo suficientemente pequeño que pueda resolverse trivialmente. Por lo general, la recursividad implica una función que se llama a sí misma.
Toda función recursiva debe tener una condición base que detenga la recursividad o, de lo contrario, la función se llama a sí misma infinitamente.

<img width="244" alt="python-recursion-function" src="https://user-images.githubusercontent.com/42527034/120390351-395a6900-c2f3-11eb-979f-95563a2f5679.png">

## Ejemplo

Ejemplo de una función recursiva para encontrar el factorial de un número entero.

```python
def factorial(n):
  if n < 1:
    return 0
  elif n == 1:
    return 1
  else:
    return (n * factorial(n - 1))
```

## Ventajas 

* Las funciones recursivas hacen que el código se vea limpio y elegante.
* Una tarea compleja se puede dividir en subproblemas más simples mediante la recursividad.
* La generación de secuencias es más fácil con la recursividad que con algunas iteraciones anidadas.

## Desventajas

* A veces, la lógica detrás de la recursividad es difícil de seguir.
* Las llamadas recursivas son caras (ineficaces) ya que ocupan mucha memoria y tiempo.
* Las funciones recursivas son difíciles de depurar.
* 
## Referencias 

* 4.2. ¿Qué es recursividad? — Solución de problemas con algoritmos y estructuras de datos. (2020). runestone. https://runestone.academy/runestone/static/pythoned/Recursion/QueEsRecursividad.html
* Python Recursion (Recursive Function). (2020). Programiz. https://www.programiz.com/python-programming/recursion
