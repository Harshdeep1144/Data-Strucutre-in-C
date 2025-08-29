#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// Function to create a new node
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

// Function to find the minimum node in a tree (used for inorder successor)
struct node* minValueNode(struct node* node)
{
    struct node* current = node;
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

// Deletion in Binary Search Tree or BST
struct node* deleteNode(struct node* root, int value)
{
    if (root == NULL)
    {
        return root;
    }

    // If the value to be deleted is smaller than the root's data, it lies in the left subtree
    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    // If the value to be deleted is greater than the root's data, it lies in the right subtree
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    else
    {
        // Case 1: Node has no children (leaf node)
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        // Case 2: Node has one child
        else if (root->left == NULL)
        {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        // Case 3: Node has two children
        else
        {
            struct node* temp = minValueNode(root->right);  // Find the inorder successor
            root->data = temp->data;  // Copy the inorder successor's data to the node to be deleted
            root->right = deleteNode(root->right, temp->data);  // Delete the inorder successor
        }
    }

    return root;
}

// Print BST elements in inorder
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

    // Inserting elements in BST
    root = insert(root, 34);
    insert(root, 23);
    insert(root, 65);
    insert(root, 32);
    insert(root, 98);
    insert(root, 21);
    insert(root, 36);
    insert(root, 87);
    insert(root, 33);

    // Inorder traversal (Before deletion)
    printf("Inorder Traversal : ");
    inorder(root);
    printf("\n");

    // Deleting a node 
    int key = 32;
    root = deleteNode(root, key);

    // Inorder traversal (After deletion)
    printf("Inorder Traversal after deletion of %d: ", key);
    inorder(root);
    printf("\n");

    return 0;
}
