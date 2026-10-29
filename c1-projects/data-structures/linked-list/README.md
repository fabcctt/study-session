# Singly Linked List

Lista simplemente enlazada de enteros, con punteros `head` y `tail`. Permite insertar al principio o al final, extraer el primero, buscar valores y eliminar su primera aparición.

## Contrato y complejidad

Inicializa con `list_init` y libera con `list_destroy`. `list_remove_first` elimina únicamente la primera coincidencia. Al quitar el último nodo, tanto `head` como `tail` quedan en `NULL`. Los punteros a nodos eliminados dejan de ser válidos.

La estructura posee su memoria: libérala antes de reinicializarla y no la copies por valor. Modifica sus campos mediante la API y usa variables independientes para recibir resultados.

Insertar en los extremos y extraer el primero: O(1). Buscar y eliminar por valor: O(n). Memoria: O(n).

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

Comprueban el orden de 1.000 nodos, duplicados, eliminación de cabeza/cola, lista vacía y reutilización.

La demostración muestra `10 20 30`, encuentra `20` y luego extrae `10 30`.
