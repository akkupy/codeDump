#include<stdio.h>
#include<math.h>

void power();

int main()
{
    float p;
    power(p);
    return 0;
}

void power()
{
    float p, n, a;
    printf("Enter any number and the power: ");
    scanf("%f %f", &n, &a);

    p = pow(n, a);

    printf("The result is: %f", p);
}
