# Shortest Paths Subgraph Builder

This project implements an algorithm that constructs a **shortest paths subgraph** from a directed graph. Given a source node and a target node, the program builds a new graph that contains **all shortest paths** from source to target.
This project was built as part of an Algorithms course assignment.

## 🧠 Project Overview

- Language: C++
- Approach: Object-Oriented Programming (OOP)
- Data Structure: Adjacency List
- Input: Graph as edge list, source is always node `1`, target is node `n`
- Output: Subgraph containing all shortest paths from `1` to `n`

The algorithm uses BFS to find the shortest path distances, then reconstructs all edges that participate in any shortest path to the target.

## 📥 Example

The program expects input in the following format from standard input:
6
7
1 2
2 4
3 4
3 5
4 5
4 6
5 6

and the output would be:
1 2
2 4
4 6
