#ifndef GRAF_H
#define GRAF_H

typedef struct {
    int V, E;
    int** a;
}graphMat;

graphMat* createMat(int V);
graphMat* addEdgeMat(graphMat* g, int i, int j);
int existsInMat(graphMat* g, int i, int j);
void printIncidentMat(graphMat* g, int x);
void freeMat(graphMat** g);
void printMat(graphMat* g);

typedef struct gln{
    int num;
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

graphList* Mat2List(graphMat* g);
graphMat* List2Mat(graphList* g);

#endif