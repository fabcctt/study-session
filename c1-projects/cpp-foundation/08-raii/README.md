# Buffer con RAII

IntBuffer reserva un arreglo en el constructor y lo libera en el destructor. No permite copiar el objeto para evitar dos propietarios del mismo bloque.

```sh
make
make run
make smoke
```

`make smoke` ejecuta la misma demostración sin entrada interactiva.

El ejemplo guarda 10, 20, 30, 40 y 50, con suma 150. Al salir del bloque se ejecuta el destructor. Un índice inválido produce una excepción.

El módulo es `buffer.cpp` y su interfaz está en `buffer.hpp`. Se compila con C++17.

Este proyecto aún no tiene tests.cpp. `make test` lo indica y termina con un estado de error; la ejecución de ejemplo no se cuenta como prueba unitaria.

Los objetos y el ejecutable quedan en `build/`. `make clean` borra esa carpeta; `make sanitize` comprueba la ejecución de ejemplo con ASan y UBSan.
