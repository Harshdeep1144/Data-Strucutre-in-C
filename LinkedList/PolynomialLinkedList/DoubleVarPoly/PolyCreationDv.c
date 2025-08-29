#include <stdio.h>
#include <stdlib.h>

// for double variable
struct node
{
    int coeff;
    int expoX;
    int expoY;
    struct node *next;
};

struct node *createPolyNode(int coeff, int expoX, int expoY)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    newnode->coeff = coeff;
    newnode->expoX = expoX;
    newnode->expoY = expoY;
    newnode->next = NULL;

    return newnode;
}

struct node *createPoly(struct node *head)
{
    int n, coeff, expoX, expoY;

    printf("Enter the number of terms in the polynomial : ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        printf("Enter the coefficient for term %d : ", i);
        scanf("%d", &coeff);

        printf("Enter the Exponent of x for term %d : ", i);
        scanf("%d", &expoX);

         printf("Enter the Exponent of y for term %d : ", i);
        scanf("%d", &expoY);

        struct node *newnode = createPolyNode(coeff, expoX, expoY);

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
        printf("%dx^%dy^%d", temp->coeff, temp->expoX, temp->expoY);

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