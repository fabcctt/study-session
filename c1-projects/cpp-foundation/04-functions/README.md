# Notas

Lee el nombre y tres notas, calcula el promedio y aplica un bono de cinco puntos a la tercera. Las funciones están separadas en `grades.cpp`.

```sh
make
make run
make smoke
```

`make run` permite usar el programa normalmente. `make smoke` ejecuta la entrada de `example.in`.

Las notas deben estar entre 0 y 100. El bono no puede llevar la tercera nota por encima de 100.

El módulo es `grades.cpp` y su interfaz está en `grades.hpp`. Se compila con C++17.

Este proyecto aún no tiene tests.cpp. `make test` lo indica y termina con un estado de error; la ejecución de ejemplo no se cuenta como prueba unitaria.

Los objetos y el ejecutable quedan en `build/`. `make clean` borra esa carpeta; `make sanitize` comprueba la ejecución de ejemplo con ASan y UBSan.
