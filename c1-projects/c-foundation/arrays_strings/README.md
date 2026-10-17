# Arrays & Strings

A small project in C to practice arrays, strings, pointers, and functions.

The program works with an integer array and a character array. It calculates the sum of the numbers, finds the largest value, counts vowels, and reverses a string.

## Files

- `main.c` - Runs the program and prints the results.
- `arrays.c` - Contains the function implementations.
- `arrays.h` - Function declarations.
- `tests.c` - Basic tests using `assert()`.

## Compilation

Compile the main program:

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic main.c arrays.c -o arrays_demo
./arrays_demo
```

Run the tests:

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic tests.c arrays.c -o arrays_tests
./arrays_tests
```

## Example Output

```text
=== Array & String Lab ===

Array sum: 150
Maximum: 50

Original word: Gentoo
Vowels: 3
Reversed word: ootneG
```

## Notes

This project is part of my C programming practice. I used separate source and header files to keep the code organized and added some tests to check the functions.

The string operations use regular C character arrays instead of C++ `std::string`.