# Trie

Árbol de prefijos con 26 hijos posibles por nodo. Permite insertar palabras, buscar coincidencias exactas, consultar prefijos y eliminar palabras sin borrar otras que comparten el mismo camino.

## Contrato y complejidad

Acepta solamente letras ASCII minúsculas `a`–`z`, hasta 128 caracteres, y también la palabra vacía. No convierte mayúsculas ni acepta tildes. El límite acota la profundidad de la liberación y poda recursivas. `trie_init` debe devolver `true` antes de usarlo. Las cadenas deben terminar en NUL. Insertar duplicados tiene éxito sin aumentar `word_count`. Una entrada inválida o un fallo de reserva no modifica el árbol. El prefijo vacío existe en todo trie inicializado, aunque no tenga palabras. `trie_destroy` libera todo.

La estructura posee su memoria: libérala antes de reinicializarla y no la copies por valor. Modifica sus campos mediante la API y usa variables independientes para recibir resultados.

Insertar, buscar y eliminar: O(L), con L igual a la longitud de la palabra y alfabeto fijo. La liberación visita todos los nodos. Memoria proporcional a los nodos creados; cada nodo contiene 26 punteros.

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

Cubren palabras con prefijos compartidos, poda, duplicados, cadena vacía, caracteres inválidos y el límite de longitud.

Inserta cuatro palabras y confirma que `cart` sigue existiendo después de eliminar `car`.
