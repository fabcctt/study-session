# Headers Separate Compilation

El header declara `maximum`; el módulo lo define y `main.c` lo utiliza. Cada `.c` se convierte en su propio objeto. El enlazador conecta la referencia de `main.o` con la definición del módulo.

## Ejecutar

Desde esta carpeta:

```sh
make run
make test
```

El ejecutable queda en `build/demo` y las pruebas en `build/tests`.
`make clean` borra los archivos de compilación.

## Investigar

Ejecuta `make symbols` y busca `U maximum` en `main.o` y `T maximum` en el objeto del módulo. `make preprocess` permite leer el header incorporado en `build/main.i`.

`make sanitize` ejecuta las pruebas con AddressSanitizer y UndefinedBehaviorSanitizer.
Compilación: GCC, C11 y GNU Make en Linux.
