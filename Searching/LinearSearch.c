#include <stdio.h>

void linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            printf("%d found at %dth postion.\n", key, i+1);
            return;
        }
    }
    printf("%d not found.\n",key);
}

int main()
{
    int n = 5;
    int numbers[] = {23, 65, 75, 23, 86};

    linearSearch(numbers, n, 75);
    linearSearch(numbers, n, 32);

    return 0;
}