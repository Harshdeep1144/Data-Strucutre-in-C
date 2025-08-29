#include <stdio.h>
#include <stdlib.h>

// Node structure for a term in the polynomial
struct node
{
    int coeff;
    int expoX;
    int expoY;
    struct node *next;
};

// Function to create a new polynomial node
struct node *createPolyNode(int coeff, int expoX, int expoY)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->coeff = coeff;
    newnode->expoX = expoX;
    newnode->expoY = expoY;
    newnode->next = NULL;
    return newnode;
}

// Function to insert a new term into the polynomial
struct node *insertNode(struct node *head, int coeff, int expoX, int expoY)
{
    struct node *newnode = createPolyNode(coeff, expoX, expoY);
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

// Function to display the polynomial
void display(struct node *head)
{
    if (head == NULL)
    {
        printf("No terms in the polynomial to display.\n");
        return;
    }

    struct node *temp = head;
    printf("The polynomial terms are: ");
    while (temp != NULL)
    {
        printf("%dx^%dy^%d", temp->coeff, temp->expoX, temp->expoY);
        if (temp->next != NULL)
        {
            printf(" + ");
        }
        temp = temp->next;
    }
    printf("\n");
}

// Function to subtract two polynomials
struct node *subtractPoly(struct node *head1, struct node *head2)
{
    int co, expoX, expoY;
    struct node *poly1, *poly2, *head3;

    head3 = NULL;
    poly1 = head1;
    poly2 = head2;

    while (poly1 != NULL && poly2 != NULL)
    {
        if (poly1->expoX > poly2->expoX || (poly1->expoX == poly2->expoX && poly1->expoY > poly2->expoY))
        {
            co = poly1->coeff;
            expoX = poly1->expoX;
            expoY = poly1->expoY;
            head3 = insertNode(head3, co, expoX, expoY);
            poly1 = poly1->next;
        }
        else if (poly1->expoX < poly2->expoX || (poly1->expoX == poly2->expoX && poly1->expoY < poly2->expoY))
        {
            co = -poly2->coeff;  // Negate the coefficient of the second polynomial for subtraction
            expoX = poly2->expoX;
            expoY = poly2->expoY;
            head3 = insertNode(head3, co, expoX, expoY);
            poly2 = poly2->next;
        }
        else
        {
            co = poly1->coeff - poly2->coeff;  // subtraction 
            expoX = poly1->expoX;  // or poly2->expoX
            expoY = poly1->expoY;  // or poly2->expoY
            if (co != 0)  
            {
                head3 = insertNode(head3, co, expoX, expoY);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    // Add remaining terms of poly1 
    while (poly1 != NULL)
    {
        co = poly1->coeff;
        expoX = poly1->expoX;
        expoY = poly1->expoY;
        head3 = insertNode(head3, co, expoX, expoY);
        poly1 = poly1->next;
    }

    // Subtract remaining terms of poly2
    while (poly2 != NULL)
    {
        co = -poly2->coeff;  // Negate the coefficient of the second polynomial for subtraction
        expoX = poly2->expoX;
        expoY = poly2->expoY;
        head3 = insertNode(head3, co, expoX, expoY);
        poly2 = poly2->next;
    }

    return head3;
}

int main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    struct node *head3 = NULL;

    // First Polynomial: 4x^3y^2 + 3x^2y^1 + 2
    head1 = insertNode(head1, 4, 3, 2);
    head1 = insertNode(head1, 3, 2, 1);
    head1 = insertNode(head1, 2, 0, 0);

    printf("First Polynomial:\n");
    display(head1);

    // Second Polynomial: 5x^3y^2 + 7x^1y^3 + 6
    head2 = insertNode(head2, 5, 3, 2);
    head2 = insertNode(head2, 7, 1, 3);
    head2 = insertNode(head2, 6, 0, 0);

    printf("Second Polynomial:\n");
    display(head2);

    // Subtract the two polynomials
    head3 = subtractPoly(head1, head2);

    printf("Resultant Polynomial after Subtraction:\n");
    display(head3);

    return 0;
}
