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

// Search element in the binary search tree or BST
struct node *searchBST(struct node *root, int key)
{
    if (root == NULL || root->data == key)
    {
        return root;
    }

    else if (key < root->data)
    {
        return searchBST(root->left, key);
    }
    else
    {
        return searchBST(root->right, key);
    }
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
    struct node *root = NULL;

    root = insert(root, 34);

    insert(root, 23);
    insert(root, 65);
    insert(root, 32);
    insert(root, 98);
    insert(root, 21);
    insert(root, 36);
    insert(root, 87);
    insert(root, 33);

    printf("Inorder Traversal : ");
    inorder(root);
    printf("\n");

    // Search in BST
    int key = 32;

    struct node *result = searchBST(root, key);

    if (result == NULL)
    {
        printf("%d not found in the BST.\n", key); //  We can also write result->data instead of key.
    }
    else
    {
        printf("%d found in the BST.\n", key); //  We can also write result->data instead of key.
    }

    return 0;
}