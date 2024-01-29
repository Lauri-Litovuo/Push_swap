# Push Swap

## Introduction
The Push Swap is a sorting algorithm project that was done as a part of the curriculum for the Hive Helsinki Coding Sccool. The goal of the project was writing a sorting program called push_swap, which sorts user provided integer values using two stacks and a set of instructions to manipulate these stacks. The instructions included: swap operations, push operations, rotate stack operations, and reverse rotation operations.

This project provided an opportunity for me to learn about sorting algorithms, time and space complexity, linked list and operations to manipulate the lists, and use of bitwise operations in C. In my solution, I chose to use radix sort approach to tackle the given challenge. This choice was made based on the applicability of radix sort for given delimitations and my own interest to learn more about radix sort and bitwise operations, while acknowledging that radix sort was unlikely to be the most efficient solution for this task.

## Table of Contents
- [Introduction](#introduction)
- [Installation](#installation)
- [Usage](#usage)
- [Tests](#tests)
- [License](#license)

## Installation
To use push_swap program, follow these steps:
1. Clone the repository to your local machine using 'git clone https://github.com/Lauri-Litovuo/Push_swap.git push_swap.
2. Navigate to the project directory: 'cd push_swap'.
3. Run the `make` command to compile the source files.

And you're good to go!

## Usage
To use the push_swap program, follow these steps:
1. After compiling the project, run the executable with the integer values as arguments.
   ```
   ./push_swap 4 67 2 8 12
   ```
2. The program will display the set of Push Swap operations to sort the provided integers.

## Tests
The program was tested using external tests.

## License
This project is licensed under the MIT License - see the [LISENSE](LICENSE) file for details.