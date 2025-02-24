#include <stdio.h>
#include <malloc.h>

typedef struct Tree
{
    int data;
    struct Tree *left;
    struct Tree *right;
} Tree;

Tree *insert(Tree *root, int data)
{
    // Create
    if (root == NULL)
    {
        Tree *temp = (Tree *)malloc(sizeof(Tree));
        temp->data = data;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }

    // Save
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }

    return root;
}

int main()
{
}