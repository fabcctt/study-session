# Graphs — BFS / DFS

Grafo de vértices numerados desde cero, representado mediante listas de adyacencia. Soporta aristas dirigidas o no dirigidas, ciclos, aristas repetidas y bucles de un vértice a sí mismo.

## Archivos

- `graph.h` y `graph.c`: creación, aristas, liberación y recorridos.
- `queue.h` y `queue.c`: cola circular de identificadores para BFS.
- `stack.h` y `stack.c`: pila de identificadores para DFS.
- `main.c`: construye un grafo, imprime sus listas y ejecuta ambos recorridos.
- `tests.c`: pruebas de recorridos, límites y estructuras auxiliares.

La cola y la pila son módulos propios de este proyecto, con capacidad fija reservada al iniciar el recorrido. No dependen de las carpetas `queue` o `stack`, que contienen otras implementaciones educativas para enteros.

## Comportamiento y contrato

`graph_init` debe tener éxito antes de usar el grafo. Un fallo lo deja en un estado que se puede liberar. Los identificadores válidos están en `[0, vertex_count)`. Las operaciones rechazan identificadores inválidos; añadir una arista no dirigida reserva ambos nodos antes de modificar las listas, para evitar una inserción parcial si falla la memoria.

Las nuevas aristas se insertan al principio de cada lista. Por ello, los vecinos se examinan en orden inverso al de inserción. Esto hace que los resultados sean deterministas para una misma secuencia de aristas.

- BFS marca un vértice cuando entra en la cola y lo visita por niveles.
- DFS usa una pila explícita y un cursor de vecinos por vértice. Desciende por un vecino antes de continuar con el siguiente, como un DFS recursivo, sin depender de la profundidad de la pila de llamadas.
- Ambos recorren solamente los vértices alcanzables desde el inicio. Los vértices desconectados requieren otro recorrido.
- Cada vértice entra como máximo una vez; por eso una capacidad de V en la cola o pila es suficiente.

El array de salida debe tener espacio para al menos V identificadores. `capacity` expresa ese espacio; `count` recibe cuántos fueron escritos y queda en cero ante un fallo. No hay un vértice inicial válido en un grafo vacío, por lo que sus recorridos devuelven `false`. Los punteros deben ser válidos y las salidas no deben solaparse con los datos internos. Las colas/pilas auxiliares devuelven `false` al insertar si están llenas y al extraer si están vacías, sin modificar su contenido ni las salidas.

El grafo y sus auxiliares son propietarios de sus reservas: no copies sus estructuras por valor ni las reinicialices sin liberarlas. No modifiques manualmente los campos públicos. `graph_destroy` libera todas las listas sin recursión.

## Complejidad

Crear el grafo cuesta O(V) y añadir una arista O(1). Cada recorrido cuesta O(V + E) en el peor caso y usa O(V) de memoria auxiliar. El grafo ocupa O(V + E); en un grafo no dirigido se almacenan ambas direcciones, salvo los bucles propios.

## Compilar y ejecutar

```sh
make run
make test
make sanitize
```

Se usa C11. `build/demo` ejecuta el ejemplo y `build/tests` las pruebas.
`make clean` borra `build/`. Los módulos están enumerados en el Makefile;
las reglas comunes están en `../topic.mk`.

## Resultado y pruebas

La demostración tiene siete vértices. Desde el vértice 0:

```text
BFS from 0: 0 2 1 5 4 3
DFS from 0: 0 2 5 4 1 3
```

El vértice 6 está desconectado. Las pruebas verifican estos órdenes exactos, recorridos desde el vértice aislado, ciclos, duplicados, bucles propios, grafos vacíos, IDs inválidos, capacidad insuficiente y una cadena dirigida de 256 vértices. También comprueban el retorno circular de la cola y los límites de la pila.
