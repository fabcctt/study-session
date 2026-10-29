# Heap Sort

Ordenación ascendente de enteros en el mismo array. Construye un max-heap de abajo hacia arriba y coloca repetidamente el máximo al final del tramo pendiente. La implementación es independiente del proyecto `max-heap`.

## Contrato y complejidad

`values` debe apuntar a `size` enteros modificables. `NULL` está permitido solamente cuando `size` es cero. No reserva memoria dinámica y no depende de otros proyectos.

Construir el heap: O(n). Ordenar: O(n log n). Memoria adicional: O(1). No es un algoritmo estable.

## Compilar y ejecutar

```sh
make run
make test
make sanitize
```

Se usa C11. `build/demo` ejecuta el ejemplo y `build/tests` las pruebas.
`make clean` borra `build/`. Los módulos están enumerados en el Makefile;
las reglas comunes están en `../topic.mk`.

## Verificación

Comparan con `qsort` todas las longitudes entre 0 y 257, con datos repetidos, ordenados, inversos, iguales y extremos de `int`.

Transforma `15 4 30 8 30 -2` en `-2 4 8 15 30 30`.
