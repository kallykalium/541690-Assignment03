Kalya Naura Farabias
24/541690/TK/60097

# Brief Description of Each Solution

* Problem 1 (Analysis): 
  Detailed Big-O analysis of three different code snippets. This includes step-by-step counting of operations and growth rate classification. (Refer to Analisis_Tugas.pdf).

* Problem 2 (Source Code): 
  Implementation of a custom resizable array (DynArray) in C++. It features manual heap memory management and an O(1) amortized pushBack operation using a doubling capacity strategy.

* Problem 3 (Source Code): 
  A comparison of Linear Search and Binary Search algorithms. Includes a mathematical analysis of the break-even point where Binary Search becomes more efficient.

* Problem 4 (Analysis): 
  A comparative amortized analysis between "doubling capacity" and "fixed-increment" strategies. Proven through trace tables and mathematical series. (Refer to Analisis_Tugas.pdf).

---

# Compilation Commands

All source files are compliant with C++17. Use the following commands:

Problem 2:
g++ -std=c++17 -Wall -Wextra -g -fsanitize=address problem2.cpp -o problem2

Problem 3:
g++ -std=c++17 -Wall -Wextra -g -fsanitize=address problem3.cpp -o problem3

---

# Known Issues or Limitations
* Memory Management: To avoid deductions for memory leaks, the user must call the freeArray() function at the end of the program life cycle to deallocate heap memory.
* Sorting Requirement: The Binary Search implementation in Problem 3 assumes the input data is already sorted in ascending order.
* Input Range: The array size and capacity are limited by the maximum value of the integer (int) type.

---

# Time Spent on the Assignment
* Problem 1: 30 minutes
* Problem 2: 1.5 hours
* Problem 3: 45 minutes
* Problem 4: 1 hour
* Total Time: Approximately 3.75 hours
