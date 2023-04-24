#include <stdio.h>
#include <stdlib.h>

#include "../Headers/Graf.h"

int main() {

    graphList* g = NULL;
    g = createList(4);

    g = addEdgeList(g, 0, 2);
    g = addEdgeList(g, 2, 0);
    g = addEdgeList(g, 3, 2);
    g = addEdgeList(g, 3, 1);
    g = addEdgeList(g, 3, 0);
    g = addEdgeList(g, 2, 1);
    g = addEdgeList(g, 1, 2);

    printList(g);

    graphMat* gg = NULL;
    gg = List2Mat(g);

    printMat(gg);

    freeMat(&gg);
    freeList(&g);

    return 0;
}