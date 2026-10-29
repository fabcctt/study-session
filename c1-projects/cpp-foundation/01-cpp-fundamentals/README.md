# Calculadora

Lee una expresión y aplica suma, resta, multiplicación o división. El menú y la validación están en `main.cpp`; las operaciones, en `calculator.cpp`.

```sh
make
make run
make smoke
```

`make run` permite usar el programa normalmente. `make smoke` ejecuta la entrada de `example.in`.

Con `12 + 5` imprime `Result: 17`. La división por cero se rechaza en main antes de llamar al módulo.

El módulo es `calculator.cpp` y su interfaz está en `calculator.hpp`. Se compila con C++17.

Este proyecto aún no tiene tests.cpp. `make test` lo indica y termina con un estado de error; la ejecución de ejemplo no se cuenta como prueba unitaria.

Los objetos y el ejecutable quedan en `build/`. `make clean` borra esa carpeta; `make sanitize` comprueba la ejecución de ejemplo con ASan y UBSan.
