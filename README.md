# Data Structures and Algorithms

A personal collection of Data Structures and Algorithms solutions written in **C++**, covering
core concepts, standard patterns, and problems from LeetCode and other practice platforms.

Currently **437 solutions** across **22 topics**.

## Topics

| Topic | Solutions | What's inside |
| --- | ---: | --- |
| [Arrays and Vectors](./Arrays%20and%20Vectors) | 84 | Two pointers, prefix sums, matrix problems, sorting-based techniques |
| [DynamicProgramming](./DynamicProgramming) | 34 | Knapsack, LIS, stock problems, grid DP, string DP |
| [Heaps](./Heaps) | 30 | Priority queues, top-K problems, heap-based scheduling |
| [BinaryAndGenericTrees](./BinaryAndGenericTrees) | 29 | Traversals, views, LCA, path problems |
| [Stacks](./Stacks) | 29 | Monotonic stacks, expression parsing, histogram problems |
| [Strings](./Strings) | 29 | Pattern matching, parsing, string manipulation |
| [LinkedList](./LinkedList) | 28 | Reversal, cycle detection, merging, reordering |
| [RecursionAndBackTracking](./RecursionAndBackTracking) | 26 | Subsets, permutations, N-Queens, sudoku |
| [Patterns](./Patterns) | 23 | Classic pattern-printing exercises |
| [Graphs](./Graphs) | 21 | BFS/DFS, cycle detection, topological sort, Dijkstra, bipartite check |
| [BinarySearchTrees](./BinarySearchTrees) | 20 | Insertion, deletion, validation, BST-to-list conversions |
| [Searching And Sorting](./Searching%20And%20Sorting) | 20 | Binary search variants, classic sorting algorithms |
| [Queues](./Queues) | 18 | Deques, circular queues, sliding-window maximum |
| [BitManipulation](./BitManipulation) | 14 | XOR tricks, bit counting, subset generation |
| [SlidingWindow](./SlidingWindow) | 8 | Fixed and variable window problems |
| [Tries](./Tries) | 7 | Prefix trees, word search, autocomplete |
| [Maps](./Maps) | 6 | Hash map and ordered map based problems |
| [BasicMaths](./BasicMaths) | 5 | Primes, GCD, number theory basics |
| [BasicsOfProgramming](./BasicsOfProgramming) | 3 | Language fundamentals |
| [OOPS](./OOPS) | 2 | Object-oriented programming concepts |
| [Pointers](./Pointers) | 1 | Pointer fundamentals |
| [DSA Notes](./DSA%20Notes) | — | Written notes and revision material |

## Structure

Each topic is a folder, and each problem is a single self-contained `.cpp` file named after
the problem it solves:

```
Graphs/
├── BFS.cpp
├── CheckLoopDirectedBFS.cpp
├── CourseSchedule.cpp
├── Dijkstra.cpp
└── ...
```

Most files include a `main()` with sample test cases, so they can be compiled and run
independently.

## Running a solution

```bash
g++ -std=c++17 "Graphs/CourseSchedule.cpp" -o solution
./solution
```

Or compile and run in one step:

```bash
g++ -std=c++17 "Graphs/CourseSchedule.cpp" -o solution && ./solution
```

## Purpose

This repository is a running log of my DSA practice — used for revision, interview
preparation, and tracking progress across topics over time.
