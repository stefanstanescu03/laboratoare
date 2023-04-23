#include <stdio.h>
#include <stdlib.h>

#include "../Headers/lista.h"

int main()
{

    nod_t *p;
    initializare(&p, 23);

    adaugareInceput(&p, 43);
    adaugareInceput(&p, 53);
    adaugareInceput(&p, 253);
    adaugareInceput(&p, 4235);
    adaugareInceput(&p, 29);

    adaugare(&p, 1, 1);

    afisare(p);

    stergere(&p, 5);

    afisare(p);

    modificare(&p, 1, 34);

    afisare(p);

    return 0;
}