#ifndef PROB_RUCSAC_H
#define PROB_RUCSAC_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double g, c;
    double profit;
    int nrObiect;
}obiect_t;

typedef struct {
    obiect_t* arr;
    int* x;
    int size;
}vect_t;

vect_t* create(int size);
void quickSort(vect_t* v, int low, int high);

double rucsac(vect_t* v, double Gmax);
double rucsacDiscret(vect_t* v, double Gmax);

#endif