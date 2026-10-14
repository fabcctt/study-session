# Data Structures — Cycle 1

Diez reconstrucciones educativas de proyectos estudiados anteriormente. **No son archivos originales recuperados.** Este bloque reconstruye implementaciones para el repositorio; no reinicia las lecciones del roadmap.

Todo el código, identificadores, comentarios y mensajes de consola están en inglés. La documentación está en español. Se utiliza C11 y cada proyecto es independiente, con interfaz `.h`, implementación `.c`, demostración `main.c` y pruebas `tests.c`.

## Proyectos

| Orden | Carpeta | Implementación |
| --- | --- | --- |
| 1 | [arrays](arrays/README.md) | Array fijo y array dinámico con crecimiento geométrico |
| 2 | [linked-list](linked-list/README.md) | Lista simplemente enlazada con cabeza y cola |
| 3 | [stack](stack/README.md) | Pila enlazada, LIFO |
| 4 | [queue](queue/README.md) | Cola enlazada, FIFO |
| 5 | [binary-search](binary-search/README.md) | Búsqueda binaria de la primera coincidencia |
| 6 | [max-heap](max-heap/README.md) | Montículo máximo con almacenamiento dinámico |
| 7 | [heap-sort](heap-sort/README.md) | Ordenación ascendente en el mismo array |
| 8 | [trie](trie/README.md) | Inserción, búsqueda, prefijos y eliminación |
| 9 | [union-find](union-find/README.md) | Unión por tamaño y compresión de caminos |
| 10 | [graphs](graphs/README.md) | Listas de adyacencia, BFS y DFS iterativo |

Se conservan los nombres de carpeta que ya existían. No se modifica `cpp-foundation`, `c-foundation` ni el README histórico de la raíz.

## Compilar y probar todo en Windows

Requisito: GCC con soporte C11 accesible como `gcc` desde PowerShell. Desde esta carpeta:

```powershell
.\build-and-test.ps1
```

Para trabajar progresivamente con un solo proyecto:

```powershell
.\build-and-test.ps1 -Project arrays
.\build-and-test.ps1 -Project graphs
```

Si GCC no está en PATH, puedes indicar su ruta con `-Compiler 'C:\ruta\a\gcc.exe'`. Si tu configuración no permite scripts de PowerShell, usa los comandos GCC individuales de cada README; no es necesario cambiar la política del sistema.

El script compila por separado las diez demostraciones y sus diez suites, ejecuta ambas y se detiene ante el primer error. Utiliza `-std=c11 -Wall -Wextra -Wpedantic -Werror -g`. Los ejecutables quedan dentro del `build/` de cada proyecto, ignorado por el `.gitignore` existente. No instala herramientas, no modifica Git ni publica cambios.

## Compilación individual y Linux

Cada README incluye la lista exacta de archivos que hay que compilar. Por ejemplo, desde `arrays/`:

```sh
gcc -std=c11 -Wall -Wextra -Wpedantic -Werror dynamic_array.c main.c -o arrays
./arrays
gcc -std=c11 -Wall -Wextra -Wpedantic -Werror dynamic_array.c tests.c -o tests
./tests
```

Si quieres mantener todos los binarios dentro de una carpeta ignorada, crea `build/` y usa `-o build/arrays` o `-o build/tests`. En Windows los README utilizan nombres terminados en `.exe`, también ignorados por Git.

**No uses `gcc *.c`**: incluiría `main.c` y `tests.c` juntos y produciría dos definiciones de `main`. Las pruebas usan `assert`; deben compilarse sin `-DNDEBUG`.

## Uso y alcance

Las demostraciones son deterministas y no requieren introducir datos. Los módulos manejan errores mediante `bool` y dejan la presentación a `main.c`. Sus README describen precondiciones, propiedad de memoria y complejidad. Las estructuras son educativas, no seguras para acceso concurrente ni sustitutos de bibliotecas de producción.

Los tipos que poseen memoria deben inicializarse antes de usarse, liberarse al terminar y no copiarse superficialmente. Las pruebas cubren comportamiento normal, vacíos, límites, duplicados y comparación con modelos de referencia cuando corresponde. No simulan todos los posibles fallos de `malloc`/`realloc`.

Consulta [VALIDATION.md](VALIDATION.md) para conocer el entorno y los resultados verificados.
