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


// Insertion in Binary Search Tree or BST
struct node *insert(struct node *root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }
    else if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        root->right = insert(root->right, value);
    }

    return root;
}

// print BST elements
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main()
{
    struct node* root = NULL;

    root = insert(root,34);

    insert(root,23);
    insert(root,65);
    insert(root,32);
    insert(root,98);
    insert(root,21);
    insert(root,36);
    insert(root,87);
    insert(root,33);

    printf("Inorder Traversal : ");
    inorder(root);

    return 0;
}