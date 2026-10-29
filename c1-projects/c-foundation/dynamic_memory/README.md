# Buffer dinámico

IntBuffer mantiene un arreglo de enteros con tamaño y capacidad. Al llenarse, aumenta su reserva con realloc; también permite consultar, clonar y liberar el buffer.

```sh
make run
make test
```

El ejemplo inserta 10, 20, 30, 40 y 50. La copia tiene memoria propia. Inicializa un buffer nuevo o previamente liberado y llama a buffer_free al terminar.

`dynamic_memory.h` declara la interfaz, `dynamic_memory.c` la implementa y `tests.c` contiene las comprobaciones.

La compilación usa C11. Los ejecutables son `build/demo` y `build/tests`. `make sanitize` ejecuta las pruebas con ASan y UBSan; `make clean` borra los archivos de compilación.
