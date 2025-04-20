#ifndef GRAPH_H
#define GRAPH_H
#include <list>

#include "Edge.h"
#include <vector>

class Graph {
public:
    Graph(int n); // Constructor to initialize the graph with n nodes.

    void addEdge(const Edge &edge); // Adds an edge to the graph.

    Graph transpose() const; // Returns the transpose of the graph (reverses the direction of all edges).

    std::vector<int> bfs(int start) const; // Performs a breadth-first search from the start node.

    bool isAdjEmpty() const; // Checks if the adjacency list is empty.

    void printGraph() const; // Prints the graph as a list of edges.

    Graph findShortestPaths(int start) const; // Finds the shortest paths from the start node to all other nodes.

    Graph findShortestPaths(int start, int end) const; // Finds the shortest path between the start and end nodes.


private:
    int n; // Number of nodes in the graph.
    std::vector<std::list<int> > adj; // Adjacency list representing edges from each node.
    std::vector<Edge> edges; // List of all edges in the graph.
};

#endif //GRAPH_H
