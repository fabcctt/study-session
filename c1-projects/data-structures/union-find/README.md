# Union-Find

Conjuntos disjuntos mediante un bosque de padres. Combina unión por tamaño y compresión completa de caminos. Permite consultar representantes, unir conjuntos y comprobar conectividad.

## Contrato y complejidad

Inicializa con `uf_init` y comprueba el resultado. Los identificadores están en `[0, size)`. Un conjunto de tamaño cero es válido. `uf_union` devuelve éxito si los elementos ya estaban unidos, sin reducir `components`. `uf_connected` devuelve el éxito de la consulta; el resultado de conectividad se escribe en su parámetro de salida. Consultar puede modificar padres por compresión de caminos. Libera con `uf_destroy`.

La estructura posee su memoria: libérala antes de reinicializarla y no la copies por valor. Modifica sus campos mediante la API y usa variables independientes para recibir resultados.

Inicializar: O(n). Encontrar/unir: O(α(n)) amortizado, donde α es la inversa de Ackermann. Memoria: O(n).

## Compilar y ejecutar

```sh
make run
make test
make sanitize
```

Se usa C11. `build/demo` ejecuta el ejemplo y `build/tests` las pruebas.
`make clean` borra `build/`. Los módulos están enumerados en el Makefile;
las reglas comunes están en `../topic.mk`.

## Verificación

Comparan todas las parejas de 32 elementos con un modelo simple de etiquetas durante 64 uniones. Comprueban el contador de componentes, uniones repetidas, IDs inválidos y tamaño cero.

Confirma que `0` y `2` están conectados, que `0` y `4` no lo están y que quedan tres componentes.
