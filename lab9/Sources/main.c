#include <stdio.h>
#include <stdlib.h>

#include "../Headers/dijkstra.h"

int main() {

    graph_t* g = initGraph(9);

    g = addEdge(g, 0, 1, 4);
    g = addEdge(g, 2, 1, 8);
    g = addEdge(g, 2, 3, 7);
    g = addEdge(g, 3, 4, 9);
    g = addEdge(g, 4, 5, 10);
    g = addEdge(g, 5, 6, 2);
    g = addEdge(g, 7, 6, 1);
    g = addEdge(g, 0, 7, 8);
    g = addEdge(g, 7, 1, 11);
    g = addEdge(g, 7, 8, 7);
    g = addEdge(g, 2, 8, 2);
    g = addEdge(g, 8, 6, 6);
    g = addEdge(g, 2, 5, 4);
    g = addEdge(g, 3, 5, 14);

    dijkstra(g, 0);

    return 0;
}