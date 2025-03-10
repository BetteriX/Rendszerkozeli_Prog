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

void inorder(Tree *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void free_tree(Tree *root)
{
    if (root != NULL)
    {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}

int main()
{
    Tree *root = NULL;
    int num;

    printf("Enter numbers (0 to stop)\n");
    while (1)
    {
        scanf("%d", &num);
        if (num == 0)
        {
            break;
        }
        root = insert(root, num);
    }

    inorder(root);
    free_tree(root);
    printf("\n");
}