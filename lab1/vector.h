#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdlib.h>

struct vector
{
    int n;
    int *arr;
};

typedef struct vector vector_t;

void initVect(vector_t *v, int n)
{
    (*v).n = n;
    (*v).arr = (int *)calloc(n, sizeof(int));
}

void readVect(vector_t *v)
{
    int i = 0;
    int x;
    for (; i < (*v).n; i++)
    {
        scanf("%d", &x);
        (*v).arr[i] = x;
    }
}

void sort(vector_t *v)
{
    int i, j;
    for (i = 0; i < (*v).n - 1; i++)
        for (j = 0; j < (*v).n - i - 1; j++)
            if ((*v).arr[j] > (*v).arr[j + 1])
            {
                int temp = (*v).arr[j + 1];
                (*v).arr[j + 1] = (*v).arr[j];
                (*v).arr[j] = temp;
            }
}

void printVect(vector_t v)
{
    int i = 0;
    for (; i < v.n; i++)
        printf("%d ", v.arr[i]);
    puts("\n");
}

#endif