#include "../Headers/lista.h"

void initializare(nod_t **p, double val)
{

    (*p) = (nod_t *)malloc(sizeof(nod_t));
    (*p)->urm = NULL;
    (*p)->val = val;
}

void adaugareInceput(nod_t **p, double val)
{
    nod_t *nodNou = (nod_t *)malloc(sizeof(nod_t));
    nodNou->val = val;
    nodNou->urm = *p;
    *p = nodNou;
}

void adaugare(nod_t **p, int poz, double val)
{

    if (*p)
    {
        nod_t *nodNou = (nod_t *)malloc(sizeof(nod_t));
        nodNou->val = val;
        nodNou->urm = NULL;

        int i = 0;
        nod_t *curent = *p;
        while (i != poz && curent->urm)
        {
            curent = curent->urm;
            i++;
        }

        nodNou->urm = curent->urm->urm;
        curent->urm = nodNou;
    }
}

void afisare(nod_t *p)
{

    while (p)
    {
        printf("%lf ", p->val);
        p = p->urm;
    }

    puts("\n");
}

void stergere(nod_t **p, int poz)
{

    if (poz == 0)
    {
        nod_t *q = (*p)->urm;
        free(*p);
        *p = q;
    }
    else
    {
        int i = 0;
        nod_t *curent = *p;
        while (i != (poz - 1) && curent->urm)
        {
            curent = curent->urm;
            i++;
        }

        nod_t *q = curent->urm;
        curent->urm = curent->urm->urm;
        free(q);
    }
}

void modificare(nod_t **p, int poz, double val)
{
    int i = 0;
    nod_t *curent = *p;
    while (i != poz && curent->urm)
    {
        curent = curent->urm;
        i++;
    }

    curent->val = val;
}

void stergereLista(nod_t **p)
{
    nod_t *q;
    while (*p)
    {
        q = (*p)->urm;
        free(*p);
        *p = q;
    }
    *p = NULL;
}

double distanta(punct_t A, punct_t B){
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

double perimetru(nodpunct_t *p) {
    double perim = 0.0;
    
    nodpunct_t *q = p;

    while(q->urm){
        perim += distanta(q->val, q->urm->val);

    }

    perim += distanta(p->val, q->val);

    return perim;
}