# Union-Find

Reconstrucción educativa de un proyecto estudiado anteriormente. No son archivos originales recuperados.

Conjuntos disjuntos mediante un bosque de padres. Combina unión por tamaño y compresión completa de caminos. Permite consultar representantes, unir conjuntos y comprobar conectividad.

## Organización

- `union_find.h`: interfaz pública y tipos.
- `union_find.c`: implementación.
- `main.c`: demostración reproducible sin entrada interactiva.
- `tests.c`: pruebas automáticas de comportamiento.

## Contrato y complejidad

Inicializa con `uf_init` y comprueba el resultado. Los identificadores están en `[0, size)`. Un conjunto de tamaño cero es válido. `uf_union` devuelve éxito si los elementos ya estaban unidos, sin reducir `components`. `uf_connected` devuelve el éxito de la consulta; el resultado de conectividad se escribe en su parámetro de salida. Consultar puede modificar padres por compresión de caminos. Libera con `uf_destroy`.

El objeto es propietario de su memoria: no lo copies por valor ni lo reinicialices mientras conserve recursos. Los punteros de objeto y salida deben ser válidos y las salidas no deben apuntar al almacenamiento interno. Los campos públicos permiten inspeccionar el estado con fines educativos; modifícalos solamente mediante la API.

Inicializar: O(n). Encontrar/unir: O(α(n)) amortizado, donde α es la inversa de Ackermann. Memoria: O(n).

## Compilar y ejecutar

Desde esta carpeta, con GCC compatible con C11:

```powershell
gcc -std=c11 -Wall -Wextra -Wpedantic -Werror union_find.c main.c -o union-find.exe
.\union-find.exe
gcc -std=c11 -Wall -Wextra -Wpedantic -Werror union_find.c tests.c -o tests.exe
.\tests.exe
```

En Linux usa los mismos comandos de GCC y ejecuta `./union-find.exe` y `./tests.exe`. La extensión es solamente un nombre; GCC genera ejecutables para el sistema donde se utiliza. Compila la demostración y las pruebas por separado, ya que ambas tienen `main`. Mantén las aserciones habilitadas: no uses `-DNDEBUG` en las pruebas.

## Verificación

Comparan todas las parejas de 32 elementos con un modelo simple de etiquetas durante 64 uniones. Comprueban el contador de componentes, uniones repetidas, IDs inválidos y tamaño cero.

Confirma que `0` y `2` están conectados, que `0` y `4` no lo están y que quedan tres componentes.

