#include <stdio.h>

int a[100];
int n;

int insertion()
{
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        int t = a[i];
        c = i - 1;
        while (c >= 0 && t <= a[c])
        {
            a[c + 1] = a[c];
            c--;
        }
        a[c + 1] = t;
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

    insertion();

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
10
3
4
56
0
The Sorted Array is
0       3       4       10      56

*/