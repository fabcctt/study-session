# Max-Heap

Reconstrucción educativa de un proyecto estudiado anteriormente. No son archivos originales recuperados.

Montículo máximo de enteros almacenado en un array dinámico. Cada padre es mayor o igual que sus hijos. `push` restaura el orden ascendiendo; `pop` extrae el máximo y restaura el orden descendiendo.

## Organización

- `max_heap.h`: interfaz pública y tipos.
- `max_heap.c`: implementación.
- `main.c`: demostración reproducible sin entrada interactiva.
- `tests.c`: pruebas automáticas de comportamiento.

## Contrato y complejidad

Inicializa con `heap_init` y libera con `heap_destroy`. No se garantiza que el array interno esté completamente ordenado. `pop` y `peek` devuelven `false` en vacío sin modificar la salida. Un fallo de reserva conserva el heap. No uses punteros a su almacenamiento como salidas.

El objeto es propietario de su memoria: no lo copies por valor ni lo reinicialices mientras conserve recursos. Los punteros de objeto y salida deben ser válidos y las salidas no deben apuntar al almacenamiento interno. Los campos públicos permiten inspeccionar el estado con fines educativos; modifícalos solamente mediante la API.

Consultar máximo: O(1). Extraer: O(log n). Insertar: O(log n) amortizado, con O(n) cuando hay que mover el array durante su crecimiento. Memoria: O(n).

## Compilar y ejecutar

Desde esta carpeta, con GCC compatible con C11:

```powershell
gcc -std=c11 -Wall -Wextra -Wpedantic -Werror max_heap.c main.c -o max-heap.exe
.\max-heap.exe
gcc -std=c11 -Wall -Wextra -Wpedantic -Werror max_heap.c tests.c -o tests.exe
.\tests.exe
```

En Linux usa los mismos comandos de GCC y ejecuta `./max-heap.exe` y `./tests.exe`. La extensión es solamente un nombre; GCC genera ejecutables para el sistema donde se utiliza. Compila la demostración y las pruebas por separado, ya que ambas tienen `main`. Mantén las aserciones habilitadas: no uses `-DNDEBUG` en las pruebas.

## Verificación

Comparan 1.000 extracciones con `qsort`, verifican la propiedad padre-hijos después de cada cambio y cubren duplicados, extremos, vacío e inserciones intercaladas.

Salida principal: `Maximum-first order: 30 30 15 8 4 -2`.

