# Stack

Pila de enteros implementada con nodos enlazados. `push` agrega en la cima, `peek` consulta sin quitar y `pop` extrae. Sigue el orden LIFO: último en entrar, primero en salir.

## Contrato y complejidad

Inicializa con `stack_init` y libera con `stack_destroy`. `pop` y `peek` devuelven `false` si la pila está vacía y conservan el valor de salida. `push` devuelve `false` si no puede reservar memoria.

La estructura posee su memoria: libérala antes de reinicializarla y no la copies por valor. Modifica sus campos mediante la API y usa variables independientes para recibir resultados.

`push`, `peek` y `pop`: O(1). Liberar la pila: O(n). Memoria: O(n).

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

Verifican 1.000 extracciones en orden inverso, consulta sin extracción, duplicados, valores negativos y reutilización.

Salida principal: `LIFO order: 30 20 10`.
