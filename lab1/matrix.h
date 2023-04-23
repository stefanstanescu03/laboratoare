#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>

struct matrix
{
    int r, c;
    int **mat;
};

typedef struct matrix matrix_t;

void initMat(matrix_t *m, int r, int c)
{

    (*m).r = r;
    (*m).c = c;

    (*m).mat = (int **)malloc((*m).r * sizeof(int *));
    
    for (int i = 0; i < (*m).r; i++)
    {
        (*m).mat[i] = (int *)malloc((*m).c * sizeof(int));
    }

    for (int i = 0; i < (*m).r; i++)
        for (int j = 0; j < (*m).c; j++)
            (*m).mat[i][j] = 0;
}

void readMat(matrix_t *m)
{
    int x;

    for (int i = 0; i < (*m).r; i++)
        for (int j = 0; j < (*m).c; j++)
        {
            scanf("%d", &x);
            (*m).mat[i][j] = x;
        }
}

matrix_t square(matrix_t m)
{
    matrix_t sm;

    initMat(&sm, m.c, m.r);

    if (sm.c != sm.r)
        return;
    else
    {
        for (int i = 0; i < sm.c; i++)
            for (int j = 0; j < sm.c; j++)
                for (int k = 0; k < sm.c; k++)
                    sm.mat[i][j] += m.mat[i][k] * m.mat[k][j];

        return sm;
    }
}

int sumDiag(matrix_t m){
    int s = 0;
    for(int i = 0; i < m.r; i++)
        s += m.mat[i][i];
    return s;
}

void printMat(matrix_t m)
{
    for (int i = 0; i < m.r; i++)
    {
        for (int j = 0; j < m.c; j++)
            printf("%d ", m.mat[i][j]);
        printf("\n");
    }
}

#endif