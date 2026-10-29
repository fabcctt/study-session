# Queue

Cola de enteros con nodos enlazados y punteros al frente y al final. `enqueue` agrega al final, `peek` consulta el primero y `dequeue` lo extrae. Sigue el orden FIFO.

## Contrato y complejidad

Inicializa con `queue_init` y libera con `queue_destroy`. Al vaciarse, ambos extremos quedan en `NULL`. Una extracción o consulta en vacío devuelve `false` y conserva el valor de salida; un fallo de reserva al encolar conserva la cola.

La estructura posee su memoria: libérala antes de reinicializarla y no la copies por valor. Modifica sus campos mediante la API y usa variables independientes para recibir resultados.

Encolar, consultar y desencolar: O(1). Liberar: O(n). Memoria: O(n).

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

Intercalan inserciones y extracciones, comprueban el orden de 1.000 valores y prueban cola vacía, consulta y reutilización.

Salida principal: `FIFO order: 10 20 30`.
