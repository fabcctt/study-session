# Max-Heap

Montículo máximo de enteros almacenado en un array dinámico. Cada padre es mayor o igual que sus hijos. `push` restaura el orden ascendiendo; `pop` extrae el máximo y restaura el orden descendiendo.

## Contrato y complejidad

Inicializa con `heap_init` y libera con `heap_destroy`. No se garantiza que el array interno esté completamente ordenado. `pop` y `peek` devuelven `false` en vacío sin modificar la salida. Un fallo de reserva conserva el heap. No uses punteros a su almacenamiento como salidas.

La estructura posee su memoria: libérala antes de reinicializarla y no la copies por valor. Modifica sus campos mediante la API y usa variables independientes para recibir resultados.

Consultar máximo: O(1). Extraer: O(log n). Insertar: O(log n) amortizado, con O(n) cuando hay que mover el array durante su crecimiento. Memoria: O(n).

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

Comparan 1.000 extracciones con `qsort`, verifican la propiedad padre-hijos después de cada cambio y cubren duplicados, extremos, vacío e inserciones intercaladas.

Salida principal: `Maximum-first order: 30 30 15 8 4 -2`.
