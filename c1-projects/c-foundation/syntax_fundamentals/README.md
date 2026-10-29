# Syntax Fundamentals

Repaso de tipos, bucles, condiciones, retorno y parámetros de salida. La suma comprueba el límite antes de sumar y conserva la salida si falla.

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
