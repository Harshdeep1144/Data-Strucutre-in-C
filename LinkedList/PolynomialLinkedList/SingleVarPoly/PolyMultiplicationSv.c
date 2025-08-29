#include <stdio.h>
#include <stdlib.h>

// For single variable
struct node
{
    int coeff;
    int expo;
    struct node *next;
};

struct node *createPolyNode(int coeff, int expo)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    newnode->coeff = coeff;
    newnode->expo = expo;
    newnode->next = NULL;

    return newnode;
}

struct node *insertNode(struct node *head, int coeff, int expo)
{
    struct node *newnode = createPolyNode(coeff, expo);

    struct node *temp;

    if (head == NULL)
    {
        head = newnode;
        return head;
    }

    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;

    return head;
}

// To print polynomial terms
void display(struct node *head)
{
    if (head == NULL)
    {
        printf("No term in the polynomial to display ");
        return;
    }

    struct node *temp;
    temp = head;

    printf("The polynomial terms are : ");
    while (temp != NULL)
    {
        printf("%dx^%d", temp->coeff, temp->expo);

        if (temp->next != NULL)
        {
            printf(" + ");
        }

        temp = temp->next;
    }
    printf("\n");
}

// Multiplication of two polynomial
struct node *multiplyPoly(struct node *head1, struct node *head2)
{
    int co;
    int ex;
    struct node *poly1, *poly2, *head3;

    poly1 = head1;
    poly2 = head2;
    head3 = NULL;

    while (poly1 != NULL)
    {
        poly2 = head2;
        while (poly2 != NULL)
        {
            co = poly1->coeff * poly2->coeff;
            ex = poly1->expo + poly2->expo;
            head3 = insertNode(head3, co, ex);
            poly2 = poly2->next;
        }
        poly1 = poly1->next;
    }

    return head3;
}

int main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    struct node *head3 = NULL;

    // First Polynomial: 4x^3 + 3x^2 + 1
    head1 = insertNode(head1, 4, 3); 
    head1 = insertNode(head1, 3, 2); 
    head1 = insertNode(head1, 1, 0); 

    display(head1);

    // Second Polynomial: 5x^3 + 7x^1 + 5
    head2 = insertNode(head2, 5, 3); 
    head2 = insertNode(head2, 7, 1); 
    head2 = insertNode(head2, 5, 0); 

    display(head2);

    // Multiply the two polynomials
    head3 = multiplyPoly(head1, head2);

    printf("Resultant Polynomial after Multiplication: ");
    display(head3);

    return 0;
}