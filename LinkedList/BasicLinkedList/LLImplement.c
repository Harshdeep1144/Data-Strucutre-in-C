#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void displayList(struct node *head)
{
    struct node *temp = head;

    printf("The Linked List Elements are : ");
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }


    printf("NULL\n");
}

int main()
{
    struct node *A, *B, *C;

    // We can also use create function to create all the three nodes 
    A = (struct node *)malloc(sizeof(struct node));
    A->data = 21;
    A->next = NULL;

    B = (struct node *)malloc(sizeof(struct node));
    B->data = 45;
    B->next = NULL;

    C = (struct node *)malloc(sizeof(struct node));
    C->data = 78;
    C->next = NULL;

    A->next = B;
    B->next = C;
    C->next = NULL;

    //Print the Linked list 
    displayList(A);

    //Free allocated memory 
    free(A);
    free(B);
    free(C);

    return 0;
}