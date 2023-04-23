#include "../Headers/stack.h"

#include <stdlib.h>

void init(stack_t *st) {
    st->size = 0;
    st->head = NULL;
}

int isEmpty(stack_t st) {
    return st.size ? 1 : 0;
}

void push(stack_t *st, node_t *node) {
    sn_t *newNode = (sn_t *) malloc(sizeof(sn_t));
    newNode->data = node;

    newNode->next = st->head;
    st->head = newNode; 
}

node_t *pop(stack_t *st) {
    node_t *top = st->head->data;
    st->head = st->head->next;
    return top;
}