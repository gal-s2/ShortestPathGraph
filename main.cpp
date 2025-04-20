#include <iostream>

#include "Graph.h"

int main() {
    int n, m;
    std::cin >> n;
    std::cin >> m;

    if (n < 0 || m < 0) {
        std::cout << "invalid input" << std::endl;
        return 1;
    }

    Graph graph(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        if (u <= 0 || u > n || v <= 0 || v > n) {
            std::cout << "invalid input" << std::endl;
            return 1;
        }
        graph.addEdge(Edge(u, v));
    }

    Graph res = graph.findShortestPaths(1, n);
    if (res.isAdjEmpty()) {
        std::cout << "No path from " << 1 << " to " << n << std::endl;
    } else {
        res.printGraph();
    }
    return 0;
}
