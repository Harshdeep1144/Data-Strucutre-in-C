#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

// print binary tree using in all three orders (inorder, preorder,postorder)
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    struct node *root = NULL;

    root = createNode(5);
    root->left = createNode(6);
    root->right = createNode(40);
    root->left->left = createNode(18);
    root->left->right = createNode(20);
    root->right->left = createNode(70);
    root->right->right = createNode(23);

    printf("Inorder Traversal : ");
    inorder(root);
    printf("\n");

    printf("Preorder Traversal : ");
    preorder(root);
    printf("\n");

    printf("Postorder Traversal : ");
    postorder(root);
    printf("\n");

    return 0;
}