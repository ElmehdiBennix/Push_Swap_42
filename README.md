# push_swap

## Introduction
The `push_swap` project is an algorithmic challenge that involves sorting a set of integers using two stacks (`a` and `b`) with a limited set of operations described below. The objective is to find the most efficient sorting solution with the fewest operations.

### Available Operations
- `sa` (swap a): Swap the first two elements of stack `a`.
- `sb` (swap b): Swap the first two elements of stack `b`.
- `ss`: Perform `sa` and `sb` simultaneously.
- `pa`: Push the first element from stack `b` to stack `a`.
- `pb`: Push the first element from stack `a` to stack `b`.
- `ra` (rotate a): Shift all elements of `a` up by one.
- `rb` (rotate b): Shift all elements of `b` up by one.
- `rr`: Perform `ra` and `rb` simultaneously.
- `rra` (reverse rotate a): Shift all elements of `a` down by one.
- `rrb` (reverse rotate b): Shift all elements of `b` down by one.
- `rrr`: Perform `rra` and `rrb` simultaneously.

## Features
- Implements an optimized sorting algorithm for stack sorting.
- Uses a set of predefined operations to sort numbers.
- Includes error handling for invalid inputs and duplicates.
- Provides a bonus `checker` program to validate sorting operations.

## Usage
### Compilation
To compile the project, use the provided `Makefile`:
```sh
make
```
This will generate the `push_swap` executable.

To compile the bonus `checker` program, run:
```sh
make bonus
```

### Running the Program
To sort a sequence of numbers, run:
```sh
./push_swap [numbers]
```
Example:
```sh
./push_swap 4 67 3 87 23
```
To check if the output is correct, use:
```sh
./push_swap 4 67 3 87 23 | ./checker 4 67 3 87 23
```
If the sequence is correctly sorted, `checker` will return `OK`, otherwise, it will return `KO`.

## Chunk-Based Sorting Algorithm
The sorting approach used in this project is a **chunk-based sorting algorithm**. Instead of sorting all numbers at once, the list is divided into smaller **chunks** based on predefined size thresholds. The sorting process follows these steps:
1. **Splitting into Chunks**: The input list is divided into multiple smaller subsets.
2. **Sorting Chunks**: Each chunk is processed separately using efficient stack operations.
3. **Merging Chunks**: The sorted chunks are merged back into stack `a` in an optimal way to minimize operations.
4. **Final Optimization**: Small adjustments are made to ensure the sorted sequence is fully ordered with minimal moves.

This method improves performance by reducing the number of moves compared to traditional brute-force sorting approaches.

## Error Handling
The program returns an `Error` message for the following cases:
- Non-numeric inputs.
- Duplicate numbers.
- Numbers exceeding the integer range.
- Invalid arguments.

## Bonus Features
- **Checker Program**: A separate program to verify the correctness of sorting operations.
- **Improved Algorithm**: Optimized sorting solutions for different input sizes.

## Makefile Targets
- `make`: Compile `push_swap`.
- `make bonus`: Compile `checker`.
- `make clean`: Remove object files.
- `make fclean`: Remove executables and object files.
- `make re`: Recompile everything.
