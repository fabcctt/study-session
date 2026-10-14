# Arrays & Dynamic Arrays

Reconstrucción educativa de un proyecto estudiado anteriormente. No son archivos originales recuperados.

Compara un array de tamaño fijo con un array dinámico de enteros que administra su memoria mediante `realloc`. `size` cuenta elementos usados; `capacity` cuenta posiciones reservadas. El crecimiento geométrico permite inserciones al final en O(1) amortizado; insertar o eliminar en medio cuesta O(n). El acceso por índice cuesta O(1).

## Archivos y contrato

- `dynamic_array.h`: estructura e interfaz pública.
- `dynamic_array.c`: reserva, crecimiento, inserción, eliminación, lectura y escritura.
- `main.c`: demostración reproducible, sin entrada interactiva.
- `tests.c`: pruebas de crecimiento, orden, límites, eliminación y reutilización.

Inicializa con `array_init` y libera con `array_destroy`. No copies la estructura por valor: es propietaria de su memoria. Los punteros de objeto y salida deben ser válidos; el puntero de salida no debe apuntar al almacenamiento interno. Las operaciones devuelven `false` ante índices inválidos o fallos de reserva y conservan los elementos existentes. Un crecimiento puede invalidar punteros anteriores a `data`. La capacidad no disminuye al eliminar.

## Compilar y ejecutar

Desde esta carpeta, con GCC compatible con C11:

```powershell
gcc -std=c11 -Wall -Wextra -Wpedantic -Werror dynamic_array.c main.c -o arrays.exe
.\arrays.exe
gcc -std=c11 -Wall -Wextra -Wpedantic -Werror dynamic_array.c tests.c -o tests.exe
.\tests.exe
```

En Linux, usa los mismos comandos de GCC y ejecuta `./arrays.exe` y `./tests.exe`; la extensión no determina el formato del ejecutable. No compiles `main.c` y `tests.c` juntos: cada uno define su propio punto de entrada. Las pruebas requieren las aserciones habilitadas (sin `-DNDEBUG`).

La demostración muestra `10 15 20 30 40`, elimina `10` y termina con cuatro elementos. Las pruebas imprimen `Arrays: all tests passed.` al completarse.
