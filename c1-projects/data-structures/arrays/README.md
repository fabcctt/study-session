# Arrays & Dynamic Arrays

Compara un array de tamaño fijo con un array dinámico de enteros que administra su memoria mediante `realloc`. `size` cuenta elementos usados; `capacity` cuenta posiciones reservadas. El crecimiento geométrico permite inserciones al final en O(1) amortizado; insertar o eliminar en medio cuesta O(n). El acceso por índice cuesta O(1).

## Archivos y contrato

- `dynamic_array.h`: estructura e interfaz pública.
- `dynamic_array.c`: reserva, crecimiento, inserción, eliminación, lectura y escritura.
- `main.c`: demostración reproducible, sin entrada interactiva.
- `tests.c`: pruebas de crecimiento, orden, límites, eliminación y reutilización.

Inicializa con `array_init` y libera con `array_destroy`. No copies la estructura por valor: es propietaria de su memoria. Los punteros de objeto y salida deben ser válidos; el puntero de salida no debe apuntar al almacenamiento interno. Las operaciones devuelven `false` ante índices inválidos o fallos de reserva y conservan los elementos existentes. Un crecimiento puede invalidar punteros anteriores a `data`. La capacidad no disminuye al eliminar.

## Compilar y ejecutar

```sh
make run
make test
make sanitize
```

Se usa C11. `build/demo` ejecuta el ejemplo y `build/tests` las pruebas.
`make clean` borra `build/`. Los módulos están enumerados en el Makefile;
las reglas comunes están en `../topic.mk`.
