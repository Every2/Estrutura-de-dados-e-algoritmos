# Fibonacci Heap

A Fibonacci Heap is a priority queue data structure that provides efficient amortized average time for operations like insertion, minimum extraction, and key decrease. It is one of the most efficient data structures for solving algorithms such as Dijkstra's algorithm and Prim's algorithm.

## Overview

The Fibonacci Heap is a collection of trees (sub-heaps) that satisfy some essential properties:

1. Each tree is a binomial tree.
2. There are no two binomial trees in the collection with the same degree (number of children).
3. The root of each binomial tree has a value less than or equal to the values of its children.
4. There is at most one binomial tree of each degree at any given time.

The Fibonacci Heap data structure supports the following core operations:

- **Insertion**: Adding an element to the priority queue.
- **Minimum Extraction**: Removing and returning the element with the minimum value in the priority queue.
- **Key Decrease**: Decreasing the value of a specific element in the priority queue.
- **Deletion**: Removing a specific element from the priority queue.