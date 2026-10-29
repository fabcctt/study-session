# Punteros a funciones

calculate recibe add o multiply como operación y escribe el resultado mediante un puntero de salida.

```sh
make run
make test
```

El ejemplo calcula 3 + 4 y 3 × 4. Las pruebas cubren ambas operaciones y el rechazo de punteros nulos.

`operations.h` declara la interfaz, `operations.c` la implementa y `tests.c` contiene las comprobaciones.

La compilación usa C11. Los ejecutables son `build/demo` y `build/tests`. `make sanitize` ejecuta las pruebas con ASan y UBSan; `make clean` borra los archivos de compilación.
