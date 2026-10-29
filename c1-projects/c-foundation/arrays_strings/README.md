# Arreglos y cadenas

Calcula la suma y el máximo de un arreglo. También cuenta vocales e invierte una cadena de caracteres.

```sh
make run
make test
```

El ejemplo suma 150 y transforma Gentoo en ootneG. Las cadenas se representan con arreglos de char terminados en NUL.

`arrays.h` declara la interfaz, `arrays.c` la implementa y `tests.c` contiene las comprobaciones.

La compilación usa C11. Los ejecutables son `build/demo` y `build/tests`. `make sanitize` ejecuta las pruebas con ASan y UBSan; `make clean` borra los archivos de compilación.
