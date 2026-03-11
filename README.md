# Splitwise Debt Simplification

This project implements a **debt simplification system similar to Splitwise** using **Dinic's Maximum Flow Algorithm**.

The goal is to reduce the number of transactions required between people who owe money to each other.

## Problem

In a group of people, many transactions may exist:

- A owes B
- B owes C
- C owes A

Instead of multiple payments, we can **simplify the debts** so the minimum number of transactions are needed.

## Approach

The problem is modeled as a **flow network**:

- People who owe money → Debtors
- People who should receive money → Creditors
- A **source node** connects to all debtors
- A **sink node** connects to all creditors

We use **Dinic's Maximum Flow Algorithm** to compute the optimal payment flow.

## Algorithm Used

Dinic's Algorithm works in two main steps:

1. **BFS (Level Graph Construction)**
   - Builds levels of nodes in the graph

2. **DFS (Blocking Flow)**
   - Pushes flow through valid paths

This continues until no more flow can be pushed.

## Project Structure
Splitwise-Debt-Simplification  
│    
├── main.cpp       # Program entry point  
├── dinic.h        # Dinic algorithm declaration  
├── dinic.cpp      # Dinic algorithm implementation  
└── README.md      # Project documentation  

## Technologies Used

- C++
- Graph Algorithms
- Dinic's Maximum Flow Algorithm
- Git & GitHub

## Example Concept

Original transactions:

A pays B -> 50  
B pays C -> 50  
C pays A -> 50  

Simplified result:

A pays C -> 50  

## Author

Darshan Mujalde