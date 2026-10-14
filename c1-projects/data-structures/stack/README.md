# Stack

Reconstrucción educativa de un proyecto estudiado anteriormente. No son archivos originales recuperados.

Pila de enteros implementada con nodos enlazados. `push` agrega en la cima, `peek` consulta sin quitar y `pop` extrae. Sigue el orden LIFO: último en entrar, primero en salir.

## Organización

- `stack.h`: interfaz pública y tipos.
- `stack.c`: implementación.
- `main.c`: demostración reproducible sin entrada interactiva.
- `tests.c`: pruebas automáticas de comportamiento.

## Contrato y complejidad

Inicializa con `stack_init` y libera con `stack_destroy`. `pop` y `peek` devuelven `false` si la pila está vacía y conservan el valor de salida. `push` devuelve `false` si no puede reservar memoria.

El objeto es propietario de su memoria: no lo copies por valor ni lo reinicialices mientras conserve recursos. Los punteros de objeto y salida deben ser válidos y las salidas no deben apuntar al almacenamiento interno. Los campos públicos permiten inspeccionar el estado con fines educativos; modifícalos solamente mediante la API.

`push`, `peek` y `pop`: O(1). Liberar la pila: O(n). Memoria: O(n).

## Compilar y ejecutar

Desde esta carpeta, con GCC compatible con C11:

```powershell
gcc -std=c11 -Wall -Wextra -Wpedantic -Werror stack.c main.c -o stack.exe
.\stack.exe
gcc -std=c11 -Wall -Wextra -Wpedantic -Werror stack.c tests.c -o tests.exe
.\tests.exe
```

En Linux usa los mismos comandos de GCC y ejecuta `./stack.exe` y `./tests.exe`. La extensión es solamente un nombre; GCC genera ejecutables para el sistema donde se utiliza. Compila la demostración y las pruebas por separado, ya que ambas tienen `main`. Mantén las aserciones habilitadas: no uses `-DNDEBUG` en las pruebas.

## Verificación

Verifican 1.000 extracciones en orden inverso, consulta sin extracción, duplicados, valores negativos y reutilización.

Salida principal: `LIFO order: 30 20 10`.

