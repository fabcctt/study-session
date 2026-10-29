# Modular C

El módulo se encarga de acumular y calcular; `main.c` se encarga de presentar los resultados. La interfaz permite probar los cálculos sin depender del programa principal. El ejemplo utiliza cantidades pequeñas y valores finitos.

## Ejecutar

Desde esta carpeta:

```sh
make run
make test
```

El ejecutable queda en `build/demo` y las pruebas en `build/tests`.
`make clean` borra los archivos de compilación.

## Investigar

Para seguir una función paso a paso: `make debug`, `break nombre_de_funcion` y `run`.

`make sanitize` ejecuta las pruebas con AddressSanitizer y UndefinedBehaviorSanitizer.
Compilación: GCC, C11 y GNU Make en Linux.
