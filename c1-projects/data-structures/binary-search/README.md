# Binary Search

Reconstrucción educativa de un proyecto estudiado anteriormente. No son archivos originales recuperados.

Búsqueda binaria iterativa sobre un array de enteros ordenado de menor a mayor. Usa el intervalo semiabierto `[left, right)` y devuelve la primera coincidencia, incluso con duplicados.

## Organización

- `binary_search.h`: interfaz pública y tipos.
- `binary_search.c`: implementación.
- `main.c`: demostración reproducible sin entrada interactiva.
- `tests.c`: pruebas automáticas de comportamiento.

## Contrato y complejidad

El array debe estar ordenado; la función no lo ordena ni valida ese requisito. `values` puede ser `NULL` solamente cuando `size` es cero. `index` debe ser un puntero válido. Un resultado `false` conserva el índice de salida. El punto medio se calcula como `left + (right - left) / 2` para evitar desbordamiento.

Tiempo: O(log n). Memoria adicional: O(1).

## Compilar y ejecutar

Desde esta carpeta, con GCC compatible con C11:

```powershell
gcc -std=c11 -Wall -Wextra -Wpedantic -Werror binary_search.c main.c -o binary-search.exe
.\binary-search.exe
gcc -std=c11 -Wall -Wextra -Wpedantic -Werror binary_search.c tests.c -o tests.exe
.\tests.exe
```

En Linux usa los mismos comandos de GCC y ejecuta `./binary-search.exe` y `./tests.exe`. La extensión es solamente un nombre; GCC genera ejecutables para el sistema donde se utiliza. Compila la demostración y las pruebas por separado, ya que ambas tienen `main`. Mantén las aserciones habilitadas: no uses `-DNDEBUG` en las pruebas.

## Verificación

Comparan los resultados con una búsqueda lineal; incluyen vacío, un elemento, duplicados, ausencias y extremos `INT_MIN`/`INT_MAX`.

Encuentra `5` en el índice `2` e informa que `7` no está presente.

