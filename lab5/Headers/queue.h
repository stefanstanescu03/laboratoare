#ifndef QUEUE_H
#define QUEUE_H

struct node {
    char *str;
    struct node *next;
};

typedef struct node node_t;

struct queue {
    node_t *head;  
    int size;
};

typedef struct queue queue_t;

void initQueue(queue_t *q);
void enQueue(queue_t *q, const char* str);
char *deQueue(queue_t *q);
int isEmpty(queue_t q);
void clearQueue(queue_t *q);

#endif