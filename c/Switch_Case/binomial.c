#include <stdio.h>
#include <math.h>

int factorial(int x)
{
    return (x == 0) ? 1 : x * factorial(x - 1);
}

double calculateProbability(int n, float p, int r, int ch)
{
    double q = 1.0 - p;
    double result = 0;
    double term;

    switch (ch)
    {
    case 1:  // At least r success
        for (int i = r; i <= n; i++)
        {
            term = (factorial(n) / (factorial(n - i) * factorial(i))) * pow(p, i) * pow(q, (n - i));
            result += term;
        }
        break;

    case 2:  // At most r success
        for (int i = 0; i <= r; i++)
        {
            term = (factorial(n) / (factorial(n - i) * factorial(i))) * pow(p, i) * pow(q, (n - i));
            result += term;
        }
        break;

    case 3:  // Exactly r success
        term = (factorial(n) / (factorial(n - r) * factorial(r))) * pow(p, r) * pow(q, (n - r));
        result = term;
        break;

    case 4:  // Not r success
        term = (factorial(n) / (factorial(n - r) * factorial(r))) * pow(p, r) * pow(q, (n - r));
        result = 1.0 - term;
        break;

    default:
        printf("Wrong choice");
        break;
    }

    return result;
}

int main()
{
    int n, r, choice;
    float p;

    printf("Enter number of occurrence of events(n): ");
    scanf(" %d", &n);

    printf("Enter the probability of success(p): ");
    scanf("%f", &p);

    if (p < 0 || p > 1)
    {
        printf("Probability lies between 0 and 1");
        return 1;
    }

    printf("Enter the number of times success is occurring(r)[r cannot be decimal]: ");
    scanf("%d", &r);

    if (r < 0 || r > n)
    {
        printf("Value of r lies between 0 and n");
        return 1;
    }

    printf("Enter your operation from the following: \n");
    printf("1. At least r success \n2. At most r success \n3. r success \n4. not r \n");
    scanf("%d", &choice);

    double prob = calculateProbability(n, p, r, choice);
    printf("\n----------------ANSWER-----------------\n");
    printf("The required probability is %f", prob);

    return 0;
}
