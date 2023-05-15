#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "graphList.h"

typedef struct {
    int V;
    int** a;
} graph_t;

graph_t* initGraph(int V);
graph_t* addEdge(graph_t* g, int i, int j, int cost);
void dijkstra(graph_t* g, int s);
void dijkstraList(graphList* g, int s);

#endif