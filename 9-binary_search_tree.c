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
    return x;
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

node *search(node *root, int key)
{
    if (root->key == key || root == NULL)
        return root;

    if (key < root->key)
    {
        return search(root->left, key);
    }
    else
        return search(root->right, key);
}

node *iterativeSearch(node *root, int key)
{
    while (root->key != key && root != NULL)
    {
        if (key < root->key)
        {
            root = root->left;
        }
        else
            root = root->right;
    }
    return root;
}

node *treeMax(node *root)
{
    while (root->right != NULL)
        root = root->right;

    return root;
}

node *treeMin(node *root)
{
    while (root->left != NULL)
        root = root->left;

    return root;
}

void leftStep(node **root)
{
    *root = (*root)->left;
}

void rightStep(node **root)
{
    *root = (*root)->right;
}

void insert(node **root, int key)
{
    node *parent = NULL;

    while ((*root) != NULL)
    {
        if (key < (*root)->key)
        {
            parent = *root;
            leftStep(&(*root));
        }
        else
        {
            parent = *root;
            rightStep(&(*root));
        }
    }

    if (key < parent->key)
    {
        parent->left = newNode(key);
    }
    else
    {
        parent->right = newNode(key);
    }
}