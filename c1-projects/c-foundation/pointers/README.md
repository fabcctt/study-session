# Punteros

Modifica valores a través de punteros, intercambia enteros y recorre un arreglo con aritmética de punteros.

```sh
make run
make test
```

Las pruebas cubren valores, arreglos y punteros nulos.

`pointers.h` declara la interfaz, `pointers.c` la implementa y `tests.c` contiene las comprobaciones.

La compilación usa C11. Los ejecutables son `build/demo` y `build/tests`. `make sanitize` ejecuta las pruebas con ASan y UBSan; `make clean` borra los archivos de compilación.
