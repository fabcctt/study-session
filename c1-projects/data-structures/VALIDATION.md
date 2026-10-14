# Registro de validación

Fecha: 14 de octubre de 2026.

## Base inspeccionada

- Copia local de `fabcctt/sys-projects`, commit `5156566` (`Added C++: stl fundamentals project.`).
- Al inicio, Git no mostraba cambios pendientes.
- Las diez carpetas de `data-structures` ya existían sin implementaciones.
- La copia contiene nueve carpetas de `cpp-foundation`, desde `01-cpp-fundamentals` hasta `09-stl-fundamentals`. Se conservaron exactamente como estaban; no se intentó corregir esa numeración ni reconstruir proyectos de ese bloque.
- No se pudo verificar el estado remoto de GitHub por falta de conexión. El trabajo se basa en la copia local proporcionada.

## Compilación y ejecución

Entorno verificado: Windows x86-64, PowerShell y GCC 16.2.0 de WinLibs / MinGW-w64 UCRT POSIX SEH.

Comando ejecutado desde `c1-projects/data-structures`:

```powershell
.\build-and-test.ps1
```

Opciones de compilación: `-std=c11 -Wall -Wextra -Wpedantic -Werror -g`.

Resultado: **20 ejecutables compilados sin advertencias; 10 demostraciones y 10 suites de pruebas terminaron con código 0**. El script terminó con `Passed: 10 project(s).` y código 0.

| Proyecto | Demostración | Pruebas |
| --- | --- | --- |
| Arrays & Dynamic Arrays | Correcta | Aprobadas |
| Singly Linked List | Correcta | Aprobadas |
| Stack | Correcta | Aprobadas |
| Queue | Correcta | Aprobadas |
| Binary Search | Correcta | Aprobadas |
| Max-Heap | Correcta | Aprobadas |
| Heap Sort | Correcta | Aprobadas |
| Trie | Correcta | Aprobadas |
| Union-Find | Correcta | Aprobadas |
| Graphs (BFS/DFS) | Correcta | Aprobadas |

Cada README describe los casos comprobados. Las pruebas de búsqueda binaria, heap, ordenación y conjuntos disjuntos contrastan resultados con búsquedas lineales, `qsort` o un modelo de etiquetas. Las de grafos verifican órdenes esperados y alcanzabilidad en grafos dirigidos y no dirigidos.

## Preservación y límites

`git diff HEAD` no mostró diferencias en archivos previamente versionados. `git status --short --untracked-files=all` mostró únicamente archivos nuevos bajo `c1-projects/data-structures`. Los ejecutables generados están ignorados por las reglas existentes de Git.

No se hicieron commits, push, pull requests ni cambios remotos. Tampoco se modificó la carpeta original situada fuera de esta copia de trabajo.

La ejecución se verificó en Windows, no en Linux. Los comandos Linux están documentados, pero no se afirma haberlos ejecutado. No se ejecutaron sanitizadores ni detectores de fugas, y no se inyectaron fallos de reserva de memoria. Las pruebas no constituyen una demostración formal de ausencia de errores.

Este registro describe reconstrucciones educativas nuevas, no recuperación de los archivos originales.
