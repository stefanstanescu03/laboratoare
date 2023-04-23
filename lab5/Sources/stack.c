#include "../Headers/stack.h"

#include <stdlib.h>

void initStack(stack_t *st) {
    st->size = 0;
}

void push(stack_t *st, const char c) {

    nodeC_t *newNode = (nodeC_t *)malloc(sizeof(nodeC_t));

    newNode->c = c;

    newNode->next = st->head;
    st->head = newNode;
    st->size++;

}

char pop(stack_t *st)
{

    nodeC_t *front = st->head;

    char c = front->c;

    st->head = st->head->next;

    free(front);

    st->size--;

    return c;
}

int isEmptySt(stack_t st)
{

    if (st.size == 0)
        return 1;
    return 0;
}

void clearStack(stack_t *st) {
    while (isEmptySt(*st) == 0)
        pop(st);
}