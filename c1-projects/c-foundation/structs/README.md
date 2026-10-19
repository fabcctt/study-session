# Structs

A small project in C to practice structures, pointers, and working with multiple records.

The program stores student information, searches for students by ID, updates grades, and calculates the average grade.

## Files

- `main.c` - Main program and example usage.
- `structs.c` - Function implementations.
- `structs.h` - Structure definitions and function declarations.
- `tests.c` - Basic tests using `assert()`.

## Compilation

Compile the main program:

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic main.c structs.c -o structs_demo
./structs_demo
```

Run the tests:

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic tests.c structs.c -o structs_tests
./structs_tests
```

## Example Output

```text
=== Student Records Lab ===

Searching for student ID 2...
Found: Maria
Grade updated to: 90

=== Student Records ===

ID: 1
Name: Alex
Grade: 85

ID: 2
Name: Maria
Grade: 90

ID: 3
Name: John
Grade: 95

Total students: 3

Average grade: 90.00
```

## Notes

This project is part of my C programming practice. I used `struct` to organize student data and pointers to access and modify records.

I also added basic tests to check student initialization, grade updates, searching, and the maximum number of students.