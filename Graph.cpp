#include "Graph.h"

#include <iostream>
#include <list>
#include <ostream>

Graph::Graph(const int n) : n(n), adj(n + 1) {
}

void Graph::addEdge(const Edge &edge) {
    adj[edge.source].push_back(edge.dest);
    edges.push_back(edge);
}

Graph Graph::transpose() const {
    Graph transposed(n);

    for (const Edge e: edges) {
        transposed.addEdge(Edge(e.dest, e.source));
    }
    return transposed;
}

std::vector<int> Graph::bfs(const int start) const {
    std::list<int> queue;
    std::vector<int> distance(n + 1, -1);

    queue.push_back(start);
    distance[start] = 0;

    while (!queue.empty()) {
        const int u = queue.front();
        queue.pop_front();

        for (int v: adj[u]) {
            if (distance[v] == -1) {
                distance[v] = distance[u] + 1;
                queue.push_back(v);
            }
        }
    }
    return distance;
}

bool Graph::isAdjEmpty() const {
    for (int u = 1; u <= n; u++) {
        if (!adj[u].empty()) {
            return false;
        }
    }
    return true;
}

void Graph::printGraph() const {
    for (int u = 1; u <= n; ++u) {
        for (const int v: adj[u]) {
            std::cout << u << " " << v << std::endl;
        }
    }
}

Graph Graph::findShortestPaths(const int start) const {
    const std::vector<int> distances = bfs(start);
    Graph shortestPaths(n);

    for (const auto &edge: edges) {
        const int u = edge.source;
        const int v = edge.dest;
        if (distances[u] != -1 && distances[v] == distances[u] + 1) {
            shortestPaths.addEdge(edge);
        }
    }

    return shortestPaths;
}

Graph Graph::findShortestPaths(const int start, const int end) const {
    const Graph fromStart = findShortestPaths(start);
    const Graph fromEnd = fromStart.transpose().findShortestPaths(end);
    return fromEnd.transpose();
}
