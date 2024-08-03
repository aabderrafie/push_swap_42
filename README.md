
# Push_swap

## Overview

The **Push_swap** project involves sorting data on a stack using a limited set of instructions. The goal is to sort the numbers in the fewest number of moves possible. The project challenges you to implement and optimize various sorting algorithms.

## Summary

You need to sort a list of integers using two stacks (`a` and `b`) and a predefined set of operations. The goal is to sort the stack `a` in ascending order while keeping stack `b` empty, utilizing the minimum number of moves.

## Mandatory Part

### Rules

- **Stacks**: You have two stacks named `a` and `b`.
  - Stack `a` initially contains a list of unique integers.
  - Stack `b` is initially empty.

- **Operations**: You have the following operations at your disposal:
  - `sa` (swap a): Swap the first two elements at the top of stack `a`. Do nothing if there's only one or no element.
  - `sb` (swap b): Swap the first two elements at the top of stack `b`. Do nothing if there's only one or no element.
  - `ss`: Perform `sa` and `sb` simultaneously.
  - `pa` (push a): Take the first element at the top of stack `b` and put it at the top of stack `a`. Do nothing if `b` is empty.
  - `pb` (push b): Take the first element at the top of stack `a` and put it at the top of stack `b`. Do nothing if `a` is empty.
  - `ra` (rotate a): Shift all elements of stack `a` up by one. The first element becomes the last.
  - `rb` (rotate b): Shift all elements of stack `b` up by one. The first element becomes the last.
  - `rr`: Perform `ra` and `rb` simultaneously.
  - `rra` (reverse rotate a): Shift all elements of stack `a` down by one. The last element becomes the first.
  - `rrb` (reverse rotate b): Shift all elements of stack `b` down by one. The last element becomes the first.
  - `rrr`: Perform `rra` and `rrb` simultaneously.

### Example

To illustrate the effect of the instructions, consider the following example:

Initial state:
```
a: 2 1 3 6 5 8
b: (empty)
```

After executing `sa`:
```
a: 1 2 3 6 5 8
b: (empty)
```

After executing `pb pb pb`:
```
a: 6 5 8
b: 3 2 1
```

After executing `ra rb` (equivalent to `rr`):
```
a: 5 8 6
b: 2 1 3
```

After executing `rra rrb` (equivalent to `rrr`):
```
a: 6 5 8
b: 3 2 1
```

After executing `sa`:
```
a: 5 6 8
b: 3 2 1
```

After executing `pa pa pa`:
```
a: 1 2 3 5 6 8
b: (empty)
```

### Program Requirements

- **Program Name**: `push_swap`
- **Turn-in Files**: `Makefile`, `*.h`, `*.c`
- **Makefile Targets**: `NAME`, `all`, `clean`, `fclean`, `re`
- **Arguments**: The stack `a` as a list of integers
- **External Functions**: `read`, `write`, `malloc`, `free`, `exit`, `ft_printf` (or equivalent), `libft` (allowed)
- **Description**: The program must sort the stack `a` in ascending order using the smallest list of instructions possible. Instructions should be separated by a newline character. The program must display nothing if no parameters are given and should handle errors gracefully by displaying "Error" followed by a newline on standard error.

### Evaluation Criteria

- The number of instructions will be compared against a maximum limit. If the program exceeds this limit or fails to sort the stack, the grade will be 0.
- For validation:
  - Sort 100 random numbers in fewer than 700 operations.
  - For maximal validation, sort 500 random numbers in fewer than 5500 operations.

## Bonus Part

### The "checker" Program

- **Program Name**: `checker`
- **Turn-in Files**: `*.h`, `*.c`
- **Makefile Target**: `bonus`
- **Arguments**: The stack `a` as a list of integers
- **External Functions**: `read`, `write`, `malloc`, `free`, `exit`, `ft_printf` (or equivalent), `libft` (allowed)
- **Description**: The program takes the initial state of stack `a` and a list of instructions as standard input. It executes the instructions and checks if the stack `a` is sorted and stack `b` is empty.
  - If `a` is sorted and `b` is empty, the program outputs "OK".
  - Otherwise, it outputs "KO".
  - In case of error, the program outputs "Error".

### Example

```sh
$ ./checker 3 2 1 0
rra
pb
sa
rra
pa
OK
```

```sh
$ ./checker 3 2 1 0
sa
rra
pb
KO
```

```sh
$ ./checker 3 2 one 0
Error
```

## Installation and Usage

To compile and run the programs, follow these steps:

1. Clone the repository:
   ```sh
   git clone https://github.com/yourusername/push_swap.git
   cd push_swap
   ```

2. Compile the mandatory part:
   ```sh
   make
   ```

3. Run the sorting simulation:
   ```sh
   ./push_swap [stack a elements]
   ```

4. Compile the bonus part (checker):
   ```sh
   make bonus
   ```

5. Run the checker program:
   ```sh
   ./checker [stack a elements]
   ```

6. To clean object files:
   ```sh
   make clean
   ```

7. To clean object files and executables:
   ```sh
   make fclean
   ```

8. To recompile:
   ```sh
   make re
   ```

## Contributing

Contributions are welcome! Feel free to fork the repository, make your changes, and submit a pull request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgements

Special thanks to the 42 Network and the community for their support and feedback.
