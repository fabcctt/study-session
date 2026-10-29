# C Foundation

Ejemplos en C11. Las funciones del módulo se comparten entre main.c y tests.c.

- [arrays_strings](arrays_strings/)
- [dynamic_memory](dynamic_memory/)
- [functions_pointers](functions_pointers/)
- [headers_separate_compilation](headers_separate_compilation/)
- [modular_c](modular_c/)
- [pointers](pointers/)
- [structs](structs/)
- [syntax_fundamentals](syntax_fundamentals/)

Desde cualquiera de esas carpetas:

```sh
make run
make test
```

Los objetos y ejecutables quedan en `build/`. `make sanitize` ejecuta las pruebas con ASan y UBSan.

Desde esta carpeta, `make` compila los ocho proyectos y `make test` ejecuta sus pruebas. Las reglas compartidas están en `topic.mk`.
