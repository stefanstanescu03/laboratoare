#ifndef MASINA_H
#define MASINA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Masina {
    char *marca;
    int pret;
    char numar[8];
};

typedef struct Masina masina_t;

void citire(masina_t *masina);

void citire_f(masina_t *masina);

void afisare(masina_t masina);

void modificare(masina_t *masina, const char *marca_noua);

void cpy(masina_t *dest, masina_t src);

#endif