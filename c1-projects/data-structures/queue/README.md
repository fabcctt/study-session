# Queue

Reconstrucción educativa de un proyecto estudiado anteriormente. No son archivos originales recuperados.

Cola de enteros con nodos enlazados y punteros al frente y al final. `enqueue` agrega al final, `peek` consulta el primero y `dequeue` lo extrae. Sigue el orden FIFO.

## Organización

- `queue.h`: interfaz pública y tipos.
- `queue.c`: implementación.
- `main.c`: demostración reproducible sin entrada interactiva.
- `tests.c`: pruebas automáticas de comportamiento.

## Contrato y complejidad

Inicializa con `queue_init` y libera con `queue_destroy`. Al vaciarse, ambos extremos quedan en `NULL`. Una extracción o consulta en vacío devuelve `false` y conserva el valor de salida; un fallo de reserva al encolar conserva la cola.

El objeto es propietario de su memoria: no lo copies por valor ni lo reinicialices mientras conserve recursos. Los punteros de objeto y salida deben ser válidos y las salidas no deben apuntar al almacenamiento interno. Los campos públicos permiten inspeccionar el estado con fines educativos; modifícalos solamente mediante la API.

Encolar, consultar y desencolar: O(1). Liberar: O(n). Memoria: O(n).

## Compilar y ejecutar

Desde esta carpeta, con GCC compatible con C11:

```powershell
gcc -std=c11 -Wall -Wextra -Wpedantic -Werror queue.c main.c -o queue.exe
.\queue.exe
gcc -std=c11 -Wall -Wextra -Wpedantic -Werror queue.c tests.c -o tests.exe
.\tests.exe
```

En Linux usa los mismos comandos de GCC y ejecuta `./queue.exe` y `./tests.exe`. La extensión es solamente un nombre; GCC genera ejecutables para el sistema donde se utiliza. Compila la demostración y las pruebas por separado, ya que ambas tienen `main`. Mantén las aserciones habilitadas: no uses `-DNDEBUG` en las pruebas.

## Verificación

Intercalan inserciones y extracciones, comprueban el orden de 1.000 valores y prueban cola vacía, consulta y reutilización.

Salida principal: `FIFO order: 10 20 30`.

