#include <stdio.h>
#include <stdlib.h>

#include "../Headers/queue.h"
#include "../Headers/stack.h"

#include <stdio.h>
#include <string.h>

char *backwards(const char* str) {

    stack_t st;
    char *rev = (char *) malloc((strlen(str) + 1) * sizeof(char));

    initStack(&st);

    int i;
    for(i = 0; str[i]; i++) 
        push(&st, str[i]);

    int index = 0;
    while(!isEmptySt(st)) 
        rev[index++] = pop(&st);
    
    rev[index] = '\0';

    clearStack(&st);

    return rev;

}

int main() { 

    queue_t q;

    initQueue(&q);

    char str[51] = "";

    while(strcmp(str, "stop")){

        scanf("%s", str);

        if(strcmp(str, "stop"))
            enQueue(&q, str);

    }

    while(!isEmpty(q))
        printf("%s\n", backwards(deQueue(&q)));

    clearQueue(&q);

    return 0;
}