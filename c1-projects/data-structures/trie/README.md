# Trie

Reconstrucción educativa de un proyecto estudiado anteriormente. No son archivos originales recuperados.

Árbol de prefijos con 26 hijos posibles por nodo. Permite insertar palabras, buscar coincidencias exactas, consultar prefijos y eliminar palabras sin borrar otras que comparten el mismo camino.

## Organización

- `trie.h`: interfaz pública y tipos.
- `trie.c`: implementación.
- `main.c`: demostración reproducible sin entrada interactiva.
- `tests.c`: pruebas automáticas de comportamiento.

## Contrato y complejidad

Acepta solamente letras ASCII minúsculas `a`–`z`, hasta 128 caracteres, y también la palabra vacía. No convierte mayúsculas ni acepta tildes. El límite acota la profundidad de la liberación y poda recursivas. `trie_init` debe devolver `true` antes de usarlo. Las cadenas deben terminar en NUL. Insertar duplicados tiene éxito sin aumentar `word_count`. Una entrada inválida o un fallo de reserva no modifica el árbol. El prefijo vacío existe en todo trie inicializado, aunque no tenga palabras. `trie_destroy` libera todo.

El objeto es propietario de su memoria: no lo copies por valor ni lo reinicialices mientras conserve recursos. Los punteros de objeto y salida deben ser válidos y las salidas no deben apuntar al almacenamiento interno. Los campos públicos permiten inspeccionar el estado con fines educativos; modifícalos solamente mediante la API.

Insertar, buscar y eliminar: O(L), con L igual a la longitud de la palabra y alfabeto fijo. La liberación visita todos los nodos. Memoria proporcional a los nodos creados; cada nodo contiene 26 punteros.

## Compilar y ejecutar

Desde esta carpeta, con GCC compatible con C11:

```powershell
gcc -std=c11 -Wall -Wextra -Wpedantic -Werror trie.c main.c -o trie.exe
.\trie.exe
gcc -std=c11 -Wall -Wextra -Wpedantic -Werror trie.c tests.c -o tests.exe
.\tests.exe
```

En Linux usa los mismos comandos de GCC y ejecuta `./trie.exe` y `./tests.exe`. La extensión es solamente un nombre; GCC genera ejecutables para el sistema donde se utiliza. Compila la demostración y las pruebas por separado, ya que ambas tienen `main`. Mantén las aserciones habilitadas: no uses `-DNDEBUG` en las pruebas.

## Verificación

Cubren palabras con prefijos compartidos, poda, duplicados, cadena vacía, caracteres inválidos y el límite de longitud.

Inserta cuatro palabras y confirma que `cart` sigue existiendo después de eliminar `car`.

