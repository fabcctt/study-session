# Binary Search

Búsqueda binaria iterativa sobre un array de enteros ordenado de menor a mayor. Usa el intervalo semiabierto `[left, right)` y devuelve la primera coincidencia, incluso con duplicados.

## Contrato y complejidad

El array debe estar ordenado; la función no lo ordena ni valida ese requisito. `values` puede ser `NULL` solamente cuando `size` es cero. `index` debe ser un puntero válido. Un resultado `false` conserva el índice de salida. El punto medio se calcula como `left + (right - left) / 2` para evitar desbordamiento.

Tiempo: O(log n). Memoria adicional: O(1).

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

Comparan los resultados con una búsqueda lineal; incluyen vacío, un elemento, duplicados, ausencias y extremos `INT_MIN`/`INT_MAX`.

Encuentra `5` en el índice `2` e informa que `7` no está presente.
