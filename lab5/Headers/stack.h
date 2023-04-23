#ifndef STACK_H
#define STACK_H

struct nodeC {
    char c;
    struct nodeC *next;
};

typedef struct nodeC nodeC_t;

struct stack {
    nodeC_t *head;  
    int size;
};

typedef struct stack stack_t;

void initStack(stack_t *st);
void push(stack_t *st, const char c);
char pop(stack_t *st);
int isEmptySt(stack_t st);
void clearStack(stack_t *st);

#endif