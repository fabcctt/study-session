# Palabras

Guarda cinco palabras en un std::array. Busca la más larga, cuenta vocales y encuentra una palabra indicada por el usuario.

```sh
make
make run
make smoke
```

`make run` permite usar el programa normalmente. `make smoke` ejecuta la entrada de `example.in`.

La búsqueda distingue mayúsculas. El contador reconoce las vocales ASCII; no procesa vocales acentuadas como Unicode.

El módulo es `words.cpp` y su interfaz está en `words.hpp`. Se compila con C++17.

Este proyecto aún no tiene tests.cpp. `make test` lo indica y termina con un estado de error; la ejecución de ejemplo no se cuenta como prueba unitaria.

Los objetos y el ejecutable quedan en `build/`. `make clean` borra esa carpeta; `make sanitize` comprueba la ejecución de ejemplo con ASan y UBSan.
