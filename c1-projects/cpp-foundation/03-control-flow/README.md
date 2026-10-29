# Adivinar el número

Un menú permite iniciar una partida o salir. Cada partida elige un número entre 1 y 100 y admite siete intentos válidos.

```sh
make
make run
make smoke
```

`make run` permite usar el programa normalmente. `make smoke` ejecuta la entrada de `example.in`.

La entrada de ejemplo entra al juego, prueba dos valores fuera de rango y termina por fin de entrada. El número es aleatorio; esta ejecución no comprueba una victoria.

El módulo es `game.cpp` y su interfaz está en `game.hpp`. Se compila con C++17.

Este proyecto aún no tiene tests.cpp. `make test` lo indica y termina con un estado de error; la ejecución de ejemplo no se cuenta como prueba unitaria.

Los objetos y el ejecutable quedan en `build/`. `make clean` borra esa carpeta; `make sanitize` comprueba la ejecución de ejemplo con ASan y UBSan.
