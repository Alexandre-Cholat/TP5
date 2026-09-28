# Subset Library

In this TP, you will build a small C++ library for manipulating subsets.

The main goal is to enable efficient iteration over subsets of a given size. For example:

```cpp
for (const auto& subset : subsets) {
    // Perform operations on subset
}
```

This capability is essential for many exponential-time algorithms, including the Held–Karp algorithm for the Traveling Salesman Problem, which you will implement during this project.

Such loops appear in many exponential-time algorithms, where even small inefficiencies can become prohibitive. We want our iterator to generate subsets in optimal time, avoiding redundant work such as recomputing all `2^n` subsets at each step.

Examples of algorithms that can benefit from efficient subset iteration include:

- Branch-and-bound algorithms, which are widely used to solve combinatorial problems.
- Backtracking algorithms for constraint satisfaction problems.
- Exponential dynamic programming algorithms, such as the Held–Karp algorithm.

## Pedagogical Objectives

- Practice C++ class design and implementation.
- Learn how to create custom iterators in C++.
- Write code that is interoperable with the C++ Standard Template Library (STL).
