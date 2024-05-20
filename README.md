###
<p align="center">
  <img src="else/cover-push_swap-bonus.png" alt="cover_push_swap_bonus"/>
</p>

<p align="center">
  <img src="else/push_swapm.png" alt="push_swap_badge"/>
</p>
<h1 align="center">
 42 Project - Push Swap
</h1>

## Overview

Push Swap is a sorting algorithm project at 42 School. The goal is to sort a stack of integers using a limited set of stack operations in the fewest possible moves. This project aims to develop algorithmic skills and optimize sorting strategies.

## Features

- **Sorting Algorithms:** Implements various sorting algorithms to efficiently sort the stack.
- **Optimization:** Focuses on optimizing sorting algorithms to minimize the number of moves required.
- **Visualizer:** Provides a visualizer tool to visualize the sorting process step by step.
- **Error Handling:** Includes error handling mechanisms to handle invalid inputs and edge cases.

## Usage

**1. Clone the repository:**

```bash
git clone https://github.com/ychbily/push_swap.git
```
**2. Compile the project:**
```bash
make
```
or
```bash
make bonus
```
**2. Executing the program**

To execute the program, run:

```shell
$ ./push_swap $ARG
```

where `$ARG` is a space-separated list of integers, for example, `ARG="1 5 2 4 3"`.

### Actions

The program supports the following actions:

**PUSH**
- `pa`: Pushes the top element of stack B onto stack A.
- `pb`: Pushes the top element of stack A onto stack B.

**SWAP**
- `sa`: Swaps the first two elements of stack A.
- `sb`: Swaps the first two elements of stack B.
- `ss`: Performs `sa` and `sb` simultaneously.

**ROTATE**
- `ra`: Rotates stack A, moving the top element to the bottom.
- `rb`: Rotates stack B, moving the top element to the bottom.
- `rr`: Performs `ra` and `rb` simultaneously.

**REVERSE ROTATE**
- `rra`: Reverses rotate stack A, moving the bottom element to the top.
- `rrb`: Reverses rotate stack B, moving the bottom element to the top.
- `rrr`: Performs `rra` and `rrb` simultaneously.

### Used Algorithm

The Turk Algorithm, coined in reference to the Mechanical Turk, is an efficient sorting strategy implemented in this project. It prioritizes pushing elements from STACK_A to STACK_B while strategically positioning them based on the maximum and minimum numbers in STACK_B. After returning all elements to STACK_A, it ensures STACK_B is empty, and STACK_A is sorted. While not the most elegant solution, it proves effective in minimizing the number of operations required to sort the stack.

## 📋 Testing

You can use third-party testers to fully test the project:

- [SimonCROS/push_swap_complexity_tester](https://github.com/SimonCROS/push_swap_tester)
- [laisarena/complete_push_swap_tester](https://github.com/laisarena/push_swap_tester)

Additionally, a tool to visualize the movements is available:

- [o-reo/push_swap_visualizer](https://github.com/o-reo/push_swap_visualizer)

## Contributing
Contributions are welcome! If you find any issues or have suggestions for improvements, feel free to open an issue or create a pull request.
