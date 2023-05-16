#include "../Headers/prob_rucsac.h"

vect_t* create(int size) {

    vect_t* v = (vect_t*)malloc(sizeof(vect_t));

    v->size = size;
    v->arr = (obiect_t*)malloc(size * sizeof(obiect_t));

    v->x = (int*)malloc(size * sizeof(int));

    return v;
}

//
void swp(obiect_t* a, obiect_t* b) {

    obiect_t aux;

    aux.c = a->c;
    aux.g = a->g;
    aux.profit = a->profit;
    aux.nrObiect = a->nrObiect;

    a->c = b->c;
    a->g = b->g;
    a->profit = b->profit;
    a->nrObiect = b->nrObiect;

    b->c = aux.c;
    b->g = aux.g;
    b->profit = aux.profit;
    b->nrObiect = aux.nrObiect;

}

double partition(vect_t* v, int low, int high) {

    double pivot = v->arr[high].profit;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (v->arr[j].profit > pivot) {
            i++;
            swp(&v->arr[i], &v->arr[j]);
        }
    }
    swp(&v->arr[i + 1], &v->arr[high]);

    return (i + 1);
}

void quickSort(vect_t* v, int low, int high) {

     if (low < high) {

        double pi = partition(v, low, high);

        quickSort(v, low, pi - 1);
        quickSort(v, pi + 1, high);
    }
}
//

double rucsac(vect_t* v, double Gmax){

    quickSort(v, 0, v->size - 1);

    double profitMax = 0.0;

    int i;
    for(i = 0; i < v->size; i++) {

        if(v->arr[i].g <= Gmax){
            v->x[v->arr[i].nrObiect] = 1;
            Gmax -= v->arr[i].g;
            profitMax += v->arr[i].c;
        } else {
            v->x[v->arr[i].nrObiect] = 1;
            profitMax += v->arr[i].c * Gmax / v->arr[i].g;
            return profitMax;
        }

    }

    return profitMax;
}

double rucsacDiscret(vect_t* v, double Gmax) {

    quickSort(v, 0, v->size - 1);

    double profitMax = 0.0;

    int i;
    for(i = 0; i < v->size; i++) {

        if(v->arr[i].g <= Gmax){
            v->x[v->arr[i].nrObiect] = 1;
            Gmax -= v->arr[i].g;
            profitMax += v->arr[i].c;
        } else return profitMax;

    }

    return profitMax;
}