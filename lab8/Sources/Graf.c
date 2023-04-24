#include "../Headers/Graf.h"

#include <stdlib.h>
#include <stdio.h>

/////////////////////////////////////////////////////////////

graphMat *createMat(int V)
{

    graphMat *g = (graphMat *)malloc(sizeof(graphMat));

    if (g == NULL)
    {
        puts("Can't create this graph");
        return NULL;
    }

    g->V = V;
    g->E = 0;

    g->a = (int **)malloc(g->V * sizeof(int *));
    int i;
    for (i = 0; i < g->V; i++)
        g->a[i] = (int *)calloc(g->V, sizeof(int));

    if (g->a == NULL)
    {
        puts("Can't allocate adjacency matrix");
        return NULL;
    }

    return g;
}

graphMat *addEdgeMat(graphMat *g, int i, int j)
{

    if (i >= 0 && j >= 0 && i < g->V && j < g->V)
    {
        g->a[i][j] = 1;
        g->E++;
    }
    return g;
}

int existsInMat(graphMat *g, int i, int j)
{

    return g->a[i][j];
}

void printIncidentMat(graphMat *g, int x)
{

    if (x >= 0 && x < g->V)
    {
        for (int i = 0; i < g->V; i++)
            if (g->a[x][i])
                printf("%d ", i);
        printf("\n");
    }
}

void freeMat(graphMat **g)
{

    for (int i = 0; i < (*g)->V; i++)
        free((*g)->a[i]);
    free((*g)->a);

    free(*g);
}

void printMat(graphMat *g)
{

    for (int i = 0; i < g->V; i++)
    {
        for (int j = 0; j < g->V; j++)
            printf("%d ", g->a[i][j]);
        printf("\n");
    }
}

/////////////////////////////////////////////////////////////

graphList *createList(int V)
{

    graphList *g = (graphList *)malloc(sizeof(graphList));

    if (g == NULL)
    {
        puts("Can't create this graph");
        return NULL;
    }

    g->V = V;
    g->E = 0;

    g->list = (gln_t **)malloc(g->V * sizeof(gln_t *));

    for (int i = 0; i < g->V; i++)
        g->list[i] = NULL;

    return g;
}

graphList *addEdgeList(graphList *g, int i, int j)
{

    if (i >= 0 && j >= 0 && i < g->V && j < g->V)
    {
        gln_t *newNode = (gln_t *)malloc(sizeof(gln_t));

        if (newNode == NULL)
        {
            puts("Can't allocate space for new edge");
            return g;
        }

        newNode->num = j;
        newNode->next = NULL;

        if (g->list[i] == NULL)
        {
            g->list[i] = newNode;
        }
        else
        {
            newNode->next = g->list[i];
            g->list[i] = newNode;
        }

        g->E++;
    }

    return g;
}

int exists(graphList *g, int i, int j)
{

    gln_t *curr = g->list[i];
    while (curr)
    {
        if (curr->num == j)
            return 1;
        curr = curr->next;
    }

    return 0;
}

void printIncidentList(graphList *g, int x)
{

    gln_t *curr = g->list[x];
    while (curr)
    {
        printf("%d ", curr->num);
        curr = curr->next;
    }
}

void freeList(graphList **g)
{

    for (int i = 0; i < (*g)->V; i++)
    {
        gln_t *tmp;

        while ((*g)->list[i] != NULL)
        {
            tmp = (*g)->list[i];
            (*g)->list[i] = (*g)->list[i]->next;
            free(tmp);
        }
    }

    free((*g)->list);

    free(*g);
}

void printList(graphList *g)
{

    for (int i = 0; i < g->V; i++)
    {
        printf("%d: ", i);
        gln_t *curr = g->list[i];
        while (curr)
        {
            printf("%d ", curr->num);
            curr = curr->next;
        }
        printf("\n");
    }
}

/////////////////////////////////////////////////////////////

graphList *Mat2List(graphMat *g)
{

    graphList *newGraph = createList(g->V);

    for (int i = 0; i < g->V; i++)
        for (int j = 0; j < g->V; j++)
            if (g->a[i][j])
                newGraph = addEdgeList(newGraph, i, j);

    return newGraph;
}

graphMat *List2Mat(graphList *g)
{

    graphMat *newGraph = createMat(g->V);

    for (int i = 0; i < g->V; i++)
        for (int j = 0; j < g->V; j++)
            if (exists(g, i, j) == 1)
                newGraph = addEdgeMat(newGraph, i, j);

    return newGraph;
}

/////////////////////////////////////////////////////////////

int **RoyWarshall(graphMat *g)
{

    int i, j, k;

    int **matrix = NULL;

    matrix = (int **)malloc(g->V * sizeof(int *));
    for (i = 0; i < g->V; i++)
        matrix[i] = (int *)calloc(g->V, sizeof(int));

    for (i = 0; i < g->V; i++)
        for (j = 0; j < g->V; j++)
        {
            if (g->a[i][j] == 0 && i != j)
                matrix[i][j] = (1 << 31) + 1;
            else
                matrix[i][j] = g->a[i][j];
        }

    for (k = 0; k < g->V; k++)
        for (i = 0; i < g->V; i++)
            for (j = 0; j < g->V; j++)
                if (matrix[i][k] + matrix[k][j] < matrix[i][j])
                    matrix[i][j] = matrix[i][k] + matrix[k][j];

    return matrix;
}