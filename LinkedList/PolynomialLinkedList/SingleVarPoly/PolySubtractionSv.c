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

struct node *createPoly(struct node *head, int coeff, int expo)
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

// Subtraction of two polynomials
struct node *subtractPoly(struct node *head1, struct node *head2)
{
    int co, ex;
    struct node *poly1, *poly2, *head3;

    head3 = NULL;
    poly1 = head1;
    poly2 = head2;

    while (poly1 != NULL && poly2 != NULL)
    {
        if (poly1->expo > poly2->expo)
        {
            co = poly1->coeff;
            ex = poly1->expo;
            head3 = createPoly(head3, co, ex);
            poly1 = poly1->next;
        }

        else if (poly1->expo < poly2->expo)
        {
            co = -poly2->coeff; // Subtraction: coefficient of poly2 is negated
            ex = poly2->expo;
            head3 = createPoly(head3, co, ex);
            poly2 = poly2->next;
        }
        else
        {
            co = poly1->coeff - poly2->coeff; // Subtraction: coefficients are subtracted
            ex = poly1->expo;                 // we can also write poly2->expo

            if (co != 0)
            {
                head3 = createPoly(head3, co, ex);
            }

            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL)
    {
        co = poly1->coeff;
        ex = poly1->expo;
        head3 = createPoly(head3, co, ex);
        poly1 = poly1->next;
    }

    while (poly2 != NULL)
    {
        co = -poly2->coeff; // Subtraction: remaining terms of poly2 are negated
        ex = poly2->expo;
        head3 = createPoly(head3, co, ex);
        poly2 = poly2->next;
    }
    return head3;
}

int main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    struct node *head3 = NULL;

    // First Polynomial: 5x^2 + 4x^1 + 2x^0
    head1 = createPoly(head1, 5, 2);
    head1 = createPoly(head1, 4, 1);
    head1 = createPoly(head1, 2, 0);

    display(head1);

    // Second Polynomial: -3x^3 + 4x^1 - 1x^0
    head2 = createPoly(head2, -3, 3);
    head2 = createPoly(head2, 4, 1);
    head2 = createPoly(head2, -1, 0);

    display(head2);

    // Subtract the two polynomials
    head3 = subtractPoly(head1, head2);

    printf("Resultant Polynomial after Subtraction : ");
    display(head3);

    return 0;
}
