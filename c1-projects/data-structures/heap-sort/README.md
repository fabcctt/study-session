# Heap Sort

Reconstrucción educativa de un proyecto estudiado anteriormente. No son archivos originales recuperados.

Ordenación ascendente de enteros en el mismo array. Construye un max-heap de abajo hacia arriba y coloca repetidamente el máximo al final del tramo pendiente. La implementación es independiente del proyecto `max-heap`.

## Organización

- `heap_sort.h`: interfaz pública y tipos.
- `heap_sort.c`: implementación.
- `main.c`: demostración reproducible sin entrada interactiva.
- `tests.c`: pruebas automáticas de comportamiento.

## Contrato y complejidad

`values` debe apuntar a `size` enteros modificables. `NULL` está permitido solamente cuando `size` es cero. No reserva memoria dinámica y no depende de otros proyectos.

Construir el heap: O(n). Ordenar: O(n log n). Memoria adicional: O(1). No es un algoritmo estable.

## Compilar y ejecutar

Desde esta carpeta, con GCC compatible con C11:

```powershell
gcc -std=c11 -Wall -Wextra -Wpedantic -Werror heap_sort.c main.c -o heap-sort.exe
.\heap-sort.exe
gcc -std=c11 -Wall -Wextra -Wpedantic -Werror heap_sort.c tests.c -o tests.exe
.\tests.exe
```

En Linux usa los mismos comandos de GCC y ejecuta `./heap-sort.exe` y `./tests.exe`. La extensión es solamente un nombre; GCC genera ejecutables para el sistema donde se utiliza. Compila la demostración y las pruebas por separado, ya que ambas tienen `main`. Mantén las aserciones habilitadas: no uses `-DNDEBUG` en las pruebas.

## Verificación

Comparan con `qsort` todas las longitudes entre 0 y 257, con datos repetidos, ordenados, inversos, iguales y extremos de `int`.

Transforma `15 4 30 8 30 -2` en `-2 4 8 15 30 30`.

