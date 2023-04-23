#ifndef BST_H_
#define BST_H_

#include <string.h>

struct node {
    char *word;
    char *description;
    struct node *left, *right;
};

typedef struct node Node;

int isGreater(const char *s1, const char *s2);
int matchPrefix(const char *prefix, const char *s);
Node* newNode(const char *word, const char *description);
Node* insert(Node *root, const char *word, const char *description);
Node *minValueNode(Node *node);
Node *search(Node *root, const char *word);
Node *erase(Node *root, const char *word);
void searchPrefix(Node *root, const char *prefix);
void printTree(Node *root);

#endif