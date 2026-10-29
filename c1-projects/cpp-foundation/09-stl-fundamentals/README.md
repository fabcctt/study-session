# Notas con STL

Usa std::vector para guardar notas, algoritmos para ordenarlas y std::map para contar repeticiones.

```sh
make
make run
make smoke
```

`make smoke` ejecuta la misma demostración sin entrada interactiva.

Las notas ordenadas son 65, 75, 75, 80, 90 y 90. El promedio mostrado es 79.17.

El módulo es `scores.cpp` y su interfaz está en `scores.hpp`. Se compila con C++17.

Este proyecto aún no tiene tests.cpp. `make test` lo indica y termina con un estado de error; la ejecución de ejemplo no se cuenta como prueba unitaria.

Los objetos y el ejecutable quedan en `build/`. `make clean` borra esa carpeta; `make sanitize` comprueba la ejecución de ejemplo con ASan y UBSan.
