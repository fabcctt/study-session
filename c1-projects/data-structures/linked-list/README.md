# Singly Linked List

Reconstrucción educativa de un proyecto estudiado anteriormente. No son archivos originales recuperados.

Lista simplemente enlazada de enteros, con punteros `head` y `tail`. Permite insertar al principio o al final, extraer el primero, buscar valores y eliminar su primera aparición.

## Organización

- `list.h`: interfaz pública y tipos.
- `list.c`: implementación.
- `main.c`: demostración reproducible sin entrada interactiva.
- `tests.c`: pruebas automáticas de comportamiento.

## Contrato y complejidad

Inicializa con `list_init` y libera con `list_destroy`. `list_remove_first` elimina únicamente la primera coincidencia. Al quitar el último nodo, tanto `head` como `tail` quedan en `NULL`. Los punteros a nodos eliminados dejan de ser válidos.

El objeto es propietario de su memoria: no lo copies por valor ni lo reinicialices mientras conserve recursos. Los punteros de objeto y salida deben ser válidos y las salidas no deben apuntar al almacenamiento interno. Los campos públicos permiten inspeccionar el estado con fines educativos; modifícalos solamente mediante la API.

Insertar en los extremos y extraer el primero: O(1). Buscar y eliminar por valor: O(n). Memoria: O(n).

## Compilar y ejecutar

Desde esta carpeta, con GCC compatible con C11:

```powershell
gcc -std=c11 -Wall -Wextra -Wpedantic -Werror list.c main.c -o linked-list.exe
.\linked-list.exe
gcc -std=c11 -Wall -Wextra -Wpedantic -Werror list.c tests.c -o tests.exe
.\tests.exe
```

En Linux usa los mismos comandos de GCC y ejecuta `./linked-list.exe` y `./tests.exe`. La extensión es solamente un nombre; GCC genera ejecutables para el sistema donde se utiliza. Compila la demostración y las pruebas por separado, ya que ambas tienen `main`. Mantén las aserciones habilitadas: no uses `-DNDEBUG` en las pruebas.

## Verificación

Comprueban el orden de 1.000 nodos, duplicados, eliminación de cabeza/cola, lista vacía y reutilización.

La demostración muestra `10 20 30`, encuentra `20` y luego extrae `10 30`.

