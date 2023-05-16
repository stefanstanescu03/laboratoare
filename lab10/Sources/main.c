#include <stdio.h>
#include <stdlib.h>

#include "../Headers/prob_rucsac.h"

int main() {

    vect_t* v;
    v = create(4);

    v->arr[0].c = 60;
    v->arr[0].g = 10;

    v->arr[1].c = 125;
    v->arr[1].g = 30;

    v->arr[2].c = 95;
    v->arr[2].g = 20;

    v->arr[3].c = 34;
    v->arr[3].g = 5;

    for(int i = 0; i < v->size; i++){
        v->arr[i].profit = v->arr[i].c / v->arr[i].g;
        v->arr[i].nrObiect = i;
    }

    printf("%lf\n", rucsacDiscret(v, 20));

    for(int i = 0; i < v->size; i++)
        printf("%d ", v->x[i]);
    puts("");

    return 0;
}