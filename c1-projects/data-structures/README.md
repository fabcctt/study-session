# Estructuras de datos

Diez proyectos en C11. Las implementaciones se reconstruyeron a partir de los temas estudiados; no son una recuperación de los archivos originales.

| Proyecto | Qué contiene |
| --- | --- |
| [arrays](arrays/) | Arreglo dinámico |
| [linked-list](linked-list/) | Lista simplemente enlazada |
| [stack](stack/) | Pila LIFO |
| [queue](queue/) | Cola FIFO |
| [binary-search](binary-search/) | Primera coincidencia en un arreglo ordenado |
| [max-heap](max-heap/) | Montículo máximo |
| [heap-sort](heap-sort/) | Ordenación sobre el propio arreglo |
| [trie](trie/) | Árbol de prefijos |
| [union-find](union-find/) | Conjuntos disjuntos |
| [graphs](graphs/) | Listas de adyacencia, BFS y DFS |

Dentro de cada carpeta:

```sh
make run
make test
make sanitize
```

Los objetos y ejecutables quedan en `build/`. `make clean` borra esa carpeta.
Cada README explica el contrato de su módulo, la complejidad y las pruebas.

Para comprobar este bloque, usa `make test` desde `data-structures/`. Las estructuras que reservan memoria deben liberarse al terminar;
no copies sus objetos propietarios por valor.

El script `build-and-test.ps1` sigue disponible para Windows con GCC y PowerShell.
Los Makefiles se verifican en Linux. El registro anterior de pruebas está en
[VALIDATION.md](VALIDATION.md).
