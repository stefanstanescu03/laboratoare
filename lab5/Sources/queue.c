#include "../Headers/queue.h"

#include <string.h>
#include <stdlib.h>

char *getFront(queue_t q)
{
    return q.head->str;
}

void initQueue(queue_t *q)
{
    q->size = 0;
}

void enQueue(queue_t *q, const char *str)
{

    node_t *newNode = (node_t *)malloc(sizeof(node_t));

    newNode->str = (char *)malloc((strlen(str) + 1) * sizeof(char));

    strcpy(newNode->str, str);

    if (q->head)
    {

        node_t *curr = q->head;

        while (curr->next)
            curr = curr->next;

        curr->next = newNode;

        q->size++;
    }
    else
    {
        q->head = newNode;
        q->size++;
    }
}

char *deQueue(queue_t *q)
{

    node_t *front = q->head;

    char *frontStr = (char *)malloc((strlen(front->str) + 1) * sizeof(char));

    strcpy(frontStr, front->str);

    q->head = q->head->next;

    free(front->str);

    free(front);

    q->size--;

    return frontStr;

}

int isEmpty(queue_t q)
{

    if (q.size == 0)
        return 1;
    return 0;
}

void clearQueue(queue_t *q)
{

    while (isEmpty(*q) == 0)
        deQueue(q);
}