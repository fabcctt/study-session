# Inventario

Product agrupa nombre, precio y stock. Inventory guarda hasta cinco productos, busca por nombre y calcula el valor total.

```sh
make
make run
make smoke
```

`make smoke` ejecuta la misma demostración sin entrada interactiva.

El ejemplo carga teclado, ratón y monitor. El total es 591.50; buscar Mouse devuelve un stock de 6.

El módulo es `inventory.cpp` y su interfaz está en `inventory.hpp`. Se compila con C++17.

Este proyecto aún no tiene tests.cpp. `make test` lo indica y termina con un estado de error; la ejecución de ejemplo no se cuenta como prueba unitaria.

Los objetos y el ejecutable quedan en `build/`. `make clean` borra esa carpeta; `make sanitize` comprueba la ejecución de ejemplo con ASan y UBSan.
