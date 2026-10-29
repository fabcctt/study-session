# C++ Foundation

Nueve proyectos en C++17. Cada carpeta tiene su programa, módulos, header y Makefile.

- [Calculadora](01-cpp-fundamentals/)
- [Duraciones](02-variables-types-operators/)
- [Adivinar el número](03-control-flow/)
- [Notas](04-functions/)
- [Palabras](05-arrays-strings/)
- [Punteros y referencias](06-pointers-references/)
- [Inventario](07-structs-classes/)
- [Buffer con RAII](08-raii/)
- [Notas con STL](09-stl-fundamentals/)

Dentro de un proyecto:

```sh
make run
make smoke
```

`make run` permite introducir datos. `make smoke` usa `example.in` cuando existe.
Estos proyectos todavía no tienen suites de pruebas; `make test` devuelve un error con esa indicación.

El ejecutable queda en `build/demo`. `make sanitize` comprueba el ejemplo con sanitizadores y `make clean` borra los archivos generados.

Desde esta carpeta, `make` compila los nueve programas y `make smoke` ejecuta sus ejemplos. Las reglas compartidas están en `topic.mk`.
