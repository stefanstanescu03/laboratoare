#ifndef BINTREE_H
#define BINTREE_H

struct node {
    int val;
    struct node *left;
    struct node *right;
};

typedef struct node node_t;

node_t *create();
void print(node_t *root);
void inorder(node_t *root);

#endif