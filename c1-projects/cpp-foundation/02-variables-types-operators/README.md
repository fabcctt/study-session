# Duraciones

Convierte segundos en horas, minutos y segundos. También muestra los minutos como decimal y clasifica las duraciones de una hora o más.

```sh
make
make run
make smoke
```

`make run` permite usar el programa normalmente. `make smoke` ejecuta la entrada de `example.in`.

Con 3661 segundos se obtiene 1 hora, 1 minuto y 1 segundo. El programa rechaza entradas negativas.

El módulo es `duration.cpp` y su interfaz está en `duration.hpp`. Se compila con C++17.

Este proyecto aún no tiene tests.cpp. `make test` lo indica y termina con un estado de error; la ejecución de ejemplo no se cuenta como prueba unitaria.

Los objetos y el ejecutable quedan en `build/`. `make clean` borra esa carpeta; `make sanitize` comprueba la ejecución de ejemplo con ASan y UBSan.
