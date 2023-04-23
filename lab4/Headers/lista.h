#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct nod
{
    double val;
    struct nod *urm;
};

struct Punct {
    char *nume_punct;
    double x, y;
};

typedef struct Punct punct_t;

struct nodPunct{
    
    punct_t val;
    struct nodPunct *urm;
};

typedef struct nodPunct nodpunct_t;

typedef struct nod nod_t;

void initializare(nod_t **p, double val);

void adaugareInceput(nod_t **p, double val);

void adaugare(nod_t **p, int poz, double val);

void afisare(nod_t *p);

void stergere(nod_t **p, int poz);

void modificare(nod_t **p, int poz, double val);

void stergereLista(nod_t **p);

double perimetru(nodpunct_t *p);

#endif