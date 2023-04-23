#include "../Headers/bst.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isGreater(const char *s1, const char *s2)
{

    int i = 0;
    for (; s1[i] && s2[i]; i++)
        if (s1[i] > s2[i])
            return 1;
        else if (s1[i] < s2[i])
            return 0;

    if (strlen(s1) > strlen(s2))
        return 1;
    else if (strlen(s1) < strlen(s2))
        return 0;

    return -1;
}

int matchPrefix(const char *prefix, const char *s) {
    int i = 0;
    for(; prefix[i] && s[i]; i++)
        if(prefix[i] != s[i])
            return 0;
    return 1;
}

Node *newNode(const char *word, const char *description)
{

    Node *node = (Node *)malloc(sizeof(Node));
    node->word = (char *)malloc((strlen(word) + 1) * sizeof(Node));
    node->description = (char *)malloc((strlen(description) + 1) * sizeof(Node));

    strcpy(node->word, word);
    strcpy(node->description, description);

    node->left = NULL;
    node->right = NULL;

    return node;
}

Node *insert(Node *root, const char *word, const char *description)
{

    if (root == NULL)
        return newNode(word, description);

    if (isGreater(root->word, word))
        root->left = insert(root->left, word, description);

    if (isGreater(word, root->word))
        root->right = insert(root->right, word, description);

    return root;
}

Node *search(Node *root, const char *word)
{

    if (root == NULL || !strcmp(root->word, word))
        return root;

    if (isGreater(root->word, word))
        return search(root->left, word);

    return search(root->right, word);
}

Node *minValueNode(Node *node)
{
    while (node->left != NULL)
        node = node->left;
    return node;
}

Node *erase(Node *root, const char *word)
{
    if (root == NULL)
        return root;

    if (isGreater(root->word, word))
        root->left = erase(root->left, word);
    else if (isGreater(word, root->word))
        root->right = erase(root->right, word);
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root;
            root = root->right;
            free(temp);
            return root;
        }
        else if (root->right == NULL)
        {
            Node *temp = root;
            root = root->left;
            free(temp);
            return root;
        }

        Node *temp = minValueNode(root->right);

        strcpy(root->word, temp->word);
        strcpy(root->description, temp->description);

        root->right = erase(root->right, temp->word);
    }
    return root;
}

void searchPrefix(Node *root, const char *prefix) {
    if (root != NULL)
    {
        if(matchPrefix(prefix, root->word))
            printf("%s = %s\n", root->word, root->description);
        searchPrefix(root->left, prefix);
        searchPrefix(root->right, prefix);
    }
}

void printTree(Node *root)
{
    if (root != NULL)
    {
        printTree(root->left);
        printf("%s = %s\n", root->word, root->description);
        printTree(root->right);
    }
}
