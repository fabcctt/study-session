# Punteros y referencias

Modifica un entero por referencia, intercambia dos valores usando punteros y redirige un puntero mediante un puntero doble.

```sh
make
make run
make smoke
```

`make smoke` ejecuta la misma demostración sin entrada interactiva.

Al final, first vale 20 y second vale 99. Compara la dirección guardada en current antes y después de redirigirlo.

El módulo es `pointers.cpp` y su interfaz está en `pointers.hpp`. Se compila con C++17.

Este proyecto aún no tiene tests.cpp. `make test` lo indica y termina con un estado de error; la ejecución de ejemplo no se cuenta como prueba unitaria.

Los objetos y el ejecutable quedan en `build/`. `make clean` borra esa carpeta; `make sanitize` comprueba la ejecución de ejemplo con ASan y UBSan.
