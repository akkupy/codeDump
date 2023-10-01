#include <stdio.h>

int a[100];
int n;
void selection()
{
    int i, j, min, temp;
    for (i = 0; i < n - 1; i = i + 1)
    {
        min = i;
        for (j = i + 1; j < n; j = j + 1)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}
int main()
{
    printf("Enter the size of the array\n");
    scanf("%d", &n);
    printf("Enter the elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    selection();

    printf("The Sorted Array is \n");
    for (int i = 0; i < n; i++)
        printf("%d\t", a[i]);

    return 0;
}

/*
OUTPUT

Enter the size of the array
5
Enter the elements
1
45
34
20
-424
The Sorted Array is
-424    1       20      34      45

*/