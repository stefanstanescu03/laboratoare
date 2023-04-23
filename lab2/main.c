#include <stdio.h>
#include "masina.h"

/*
    Aston-Martin
    50000
    IF09BCX

    Ferrari
    123000
    B87OPA

    Dacia
    9000
    AG03EFD

    Lambo
    5273190
    GL34HIF

*/

struct Masini_v {
    masina_t *arr;
    int n;
};

typedef struct Masini_v masini_v_t;

int sumaPreturi(masina_t **mat, int n, int l){

    int s = 0, j;
    for(j = 0; j < n; j++)
        s += mat[l][j].pret;

    return s;
}

void sort(masini_v_t *v) {
    int i, j;
    for (i = 0; i < v->n - 1; i++)
        for (j = 0; j < v->n - i - 1; j++)
            if (v->arr[j].pret > v->arr[j + 1].pret){
                masina_t aux;
                cpy(&aux, v->arr[j]);
                cpy(&v->arr[j], v->arr[j + 1]);
                cpy(&v->arr[j + 1], aux);
            }
}

int main() {

    //
    int n;
    masina_t **mat;

    scanf("%d", &n);

    mat = malloc(n * sizeof(masina_t *));

    int i, j;
    for(i = 0; i < n; i++)
        mat[i] = malloc(n * sizeof(masina_t));


    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++){
            masina_t m;
            citire(&m);

            cpy(&mat[i][j], m);
        }


    //
    masini_v_t v;
    v.arr = malloc(n * sizeof(masina_t));

    for(i = 0; i < n; i++)
        cpy(&v.arr[i], mat[i][i]);

    //

    return 0;
}