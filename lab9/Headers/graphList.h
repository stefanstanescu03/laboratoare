#ifndef GRAPHLIST_H
#define GRAPHLIST_H

typedef struct gln{
    int num;
    int cost;
    struct gln* next;
}gln_t;


typedef struct {
    int V, E;
    gln_t** list;
}graphList;

graphList* createList(int V);
graphList* addEdgeList(graphList* g, int i, int j);
int exists(graphList* g, int i, int j);
void printIncidentList(graphList* g, int x);
void freeList(graphList** g);
void printList(graphList* g);

#endif