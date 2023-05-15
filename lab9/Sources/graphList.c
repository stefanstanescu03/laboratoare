#include "../Headers/graphList.h"

#include <stdio.h>
#include <stdlib.h>

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