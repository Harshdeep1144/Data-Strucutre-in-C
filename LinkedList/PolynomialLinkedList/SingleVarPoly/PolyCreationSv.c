#include <stdio.h>
#include <stdlib.h>

// for single variable
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

struct node *createPoly(struct node *head)
{
    int n, coeff, expo;

    printf("Enter the number of terms in the polynomial : ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        printf("Enter the coefficient for term %d : ", i);
        scanf("%d", &coeff);

        printf("Enter the Exponent for term %d : ", i);
        scanf("%d", &expo);

        struct node *newnode = createPolyNode(coeff, expo);

        struct node *temp;
        temp = head;

        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }

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
}

int main()
{
    struct node *head = NULL;

    head = createPoly(head);
    display(head);

    return 0;
}