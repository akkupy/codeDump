// WAP to compare addresses of 2 variables and display appropriate message

#include <stdio.h>

int main()
{
    int x, *p;
    int y, *q;
    p = &x;
    q = &y;
    printf("Address : %x \n", p);
    printf("Address : %x \n", q);
    if (p == q)
        printf("Equal");
    else
        printf("Not Equal");
    return 0;
}
/*
OUTPUT

Address : 61ff14
Address : 61ff10
Not Equal

*/