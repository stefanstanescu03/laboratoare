#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "masina.h"

void citire(masina_t *masina) {

    char marca[101];
    scanf("%s", marca);

    masina->marca = (char *) malloc((strlen(marca) + 1) * sizeof(char));

    strcpy(masina->marca, marca);

    scanf("%d", &masina->pret);

    char numar[8];

    scanf("%s", numar);

    strcpy(masina->numar, numar);

}

void citire_f(masina_t *masina){
    
    FILE *ptr = fopen("data_intrare.txt", "r");
    if(ptr == NULL){
        puts("Eroare!");
        exit(1);
    }

    char marca[101];
    fscanf(ptr, "%s", marca);

    masina->marca = (char *) malloc((strlen(marca) + 1) * sizeof(char));

    strcpy(masina->marca, marca);

    fscanf(ptr, "%d", &masina->pret);

    char numar[8];

    fscanf(ptr, "%s", numar);

    strcpy(masina->numar, numar);

}

void afisare(masina_t masina) {

    printf("%s\n%d\n%s\n", masina.marca, masina.pret, masina.numar);
}

void afisare_f(masina_t masina) {

    FILE *ptr = fopen("data_iesire", "w");
    if(ptr == NULL){
        puts("Eroare!");
        exit(1);
    }

    fprintf(ptr, "%s\n%d\n%s\n", masina.marca, masina.pret, masina.numar);
}

void modificare(masina_t *masina, const char *marca_noua){

    free(masina->marca);
    masina->marca = (char *) malloc((strlen(marca_noua) + 1) * sizeof(char));

    strcpy(masina->marca, marca_noua);

}

void cpy(masina_t *dest, masina_t src){

    dest->marca = (char *) malloc((strlen(src.marca) + 1) * sizeof(char));

    strcpy(dest->marca, src.marca);

    (*dest).pret = src.pret;

    strcpy(dest->numar, src.numar);
}