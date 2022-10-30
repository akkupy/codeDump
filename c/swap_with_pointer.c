# include <stdio.h>

int main() {
    int a = 10, b = 20, temp;
    int *c = &a;
    int *d = &b;

    printf("Before the swapping of: a = %d, b = %d\n", a, b);

    temp = *c;
    *c = *d;
    *d = temp;

    printf("After the swapping of: a = %d, b = %d\n", a, b);

    return 0;

}
