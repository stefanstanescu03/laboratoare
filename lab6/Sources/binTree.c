#include "../Headers/binTree.h"
#include "../Headers/stack.h"

#include <stdlib.h>
#include <stdio.h>

node_t *create() {
    node_t *root = (node_t *) malloc(sizeof(node_t));
    int val;

    printf("Dati valoarea pentru nod: ");

    scanf("%d", &val);

    root->val = val;

    char s;
    
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }

    puts("Nodul adaugat are subarbore stang? d/n: ");
    scanf("%c", &s);

    while ((c = getchar()) != '\n' && c != EOF) { }

    if(s == 'd')
        root->left = create();
    else
        root->left = NULL;

    puts("Nodul adaugat are subarbore drept? d/n: ");
    scanf("%c", &s);

    while ((c = getchar()) != '\n' && c != EOF) { }

    if(s == 'd')
        root->right = create();
    else
        root->right = NULL;

    return root;
}

void print(node_t *root) {
    if(root) {
        printf("%d ", root->val);
        print(root->left);
        print(root->right);
    }
}

void inorder(node_t *root) {
    stack_t st;
    init(&st);

    node_t *curr = root;

    while(curr || !(isEmpty(st))) {
        while(curr){
            push(&st, curr);
            curr = curr->left;
        }

        curr = pop(&st);

        printf("%d", curr->val);

        curr = curr->right;
    }
}

void freeTree(node_t *root) {
    while(root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int lca(node_t *root, int a, int b) {
    stack_t st;
    init(&st);

    node_t *curr;

    push(&st, root);

    while(curr || !(isEmpty(st))) {

        curr = pop(&st);
        if(curr->left->val == a || curr->right->val == b)
            return curr->val;

        if(curr->left)
            push(&st, curr->left);

        if(curr->right)
            push(&st, curr->right);
        
    }

}