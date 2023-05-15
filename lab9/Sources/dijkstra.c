#include "../Headers/dijkstra.h"

#include <stdlib.h>
#include <stdio.h>

#define INT_MAX ((1 << 31) - 1)

graph_t *initGraph(int V)
{

    graph_t *g = (graph_t *)malloc(sizeof(graph_t));

    if (g == NULL)
        return NULL;

    g->V = V;

    g->a = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
        g->a[i] = (int *)calloc(g->V, sizeof(int));

    return g;
}

graph_t *addEdge(graph_t *g, int i, int j, int cost)
{

    g->a[i][j] = cost;
    g->a[j][i] = cost;

    return g;
}

int minDist(graph_t *g, int dist[], int sps[])
{
    int min = INT_MAX, minIndex;

    for (int i = 0; i < g->V; i++)
        if (sps[i] == 0 && dist[i] <= min)
            min = dist[i], minIndex = i;

    return minIndex;
}

void dijkstra(graph_t *g, int s)
{

    int dist[g->V], sps[g->V], anterior[g->V];

    for (int i = 0; i < g->V; i++)
    {
        dist[i] = INT_MAX;
        sps[i] = 0;
    }

    dist[s] = 0;

    for (int i = 0; i < g->V; i++)
    {
        int u = minDist(g, dist, sps);
        sps[u] = 1;

        for (int j = 0; j < g->V; j++)
            if (!sps[j] && g->a[u][j] != 0 && dist[u] != INT_MAX && dist[u] + g->a[u][j] < dist[j])
            {
                dist[j] = dist[u] + g->a[u][j];
                anterior[j] = u;
            }
    }

    for (int i = 0; i < g->V; i++)
        printf("%d ", dist[i]);

    printf("\n");

    for (int i = 0; i < g->V; i++)
        printf("%d ", anterior[i]);

    printf("\n");
}

void dijkstraList(graphList *g, int s)
{

    int dist[g->V], sps[g->V], anterior[g->V];

    for (int i = 0; i < g->V; i++)
    {
        dist[i] = INT_MAX;
        sps[i] = 0;
    }

    dist[s] = 0;

    for (int i = 0; i < g->V; i++)
    {
        int u = minDist(g, dist, sps);
        sps[u] = 1;

        gln_t *curr = g->list[u];
        while (curr)
        {

            if (!sps[curr->num] && dist[u] != INT_MAX && dist[u] + curr->cost < dist[curr->num])
            {
                dist[curr->num] = dist[u] + curr->cost;
                anterior[curr->num] = u;
            }

            curr = curr->next;
        }
    }

    for (int i = 0; i < g->V; i++)
        printf("%d ", dist[i]);

    printf("\n");

    for (int i = 0; i < g->V; i++)
        printf("%d ", anterior[i]);

    printf("\n");
}