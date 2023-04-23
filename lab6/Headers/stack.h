#ifndef STACK_H
#define STACK_H

#include "binTree.h"

struct stackNode {
    node_t* data;
    struct stackNode *next;
};

typedef struct stackNode sn_t; 

struct stack {
    sn_t *head;
    int size;
};

typedef struct stack stack_t;

void init(stack_t *st);
int isEmpty(stack_t st);
void push(stack_t *st, node_t *node);
node_t *pop(stack_t *st);

#endif