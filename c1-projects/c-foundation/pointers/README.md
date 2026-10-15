# Pointer Lab — C Foundation

A modular C project demonstrating pointer fundamentals and pointer arithmetic.

## Features

- Modify variables through pointers
- Swap integer values using pointers
- Modify arrays using pointer arithmetic
- Calculate the sum of array elements
- Basic null-pointer validation
- Automated tests using `assert()`

## Project Structure

- `main.c` — Main demonstration
- `pointers.h` — Function declarations
- `pointers.c` — Function implementations
- `tests.c` — Automated tests

## Build

Compile the demonstration:

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic main.c pointers.c -o pointers_demo
./pointers_demo
```

Compile and run the tests:

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic tests.c pointers.c -o pointers_tests
./pointers_tests
```

## Purpose

Educational reconstruction for practicing C pointers, memory addresses, array traversal, modular programming, and automated testing.