#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
} node;

node *newNode(int key)
{
    node *x = (node *)malloc(sizeof(node));
    x->key = key;
    x->left = NULL;
    x->right = NULL;
}

// function that builds a binary search tree from an array
// returns a pointer to a node that is the root of the newly created tree
node *buildBST(int *v, int leftBound, int rightBound)
{
    // if left>right it means that no more divisions should be performed
    if (leftBound > rightBound)
        return NULL;

    int mid = (leftBound + rightBound) / 2;
    node *root = newNode(v[mid]);

    // recursively calls the function on the left subtree
    root->left = buildBST(v, leftBound, mid - 1);

    // recursively calls the function on the right subtree
    root->right = buildBST(v, mid + 1, rightBound);

    return root;
}