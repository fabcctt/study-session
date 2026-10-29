# Registros de estudiantes

Guarda estudiantes, busca por ID, cambia notas y calcula el promedio.

```sh
make run
make test
```

El ejemplo actualiza la nota de Maria a 90 y obtiene un promedio de 90.00.

`structs.h` declara la interfaz, `structs.c` la implementa y `tests.c` contiene las comprobaciones.

La compilación usa C11. Los ejecutables son `build/demo` y `build/tests`. `make sanitize` ejecuta las pruebas con ASan y UBSan; `make clean` borra los archivos de compilación.
