// WAP to implement tower of hanoi

#include <stdio.h>

int towers(int n, char beg, char end, char aux)
{

    if (n == 1)
    {
        printf("\n Move disk %d from the peg %c to the peg %c", n, beg, end);
        return 0;
    }
    else
    {
        towers(n - 1, beg, aux, end);
        printf("\n Move disk %d from the peg %c to the peg %c", n, beg, end);
        towers(n - 1, aux, end, beg);
    }
}

int main()
{
    int n;
    printf("Enter the number of disks to be operated\n");
    scanf("%d", &n);
    towers(n, 'A', 'B', 'C');
    return 0;
}

/*
A beginning peg/from peg
B end peg/to peg
C auxilliary peg

OUTPUT:

Enter the number of disks to be operated
3

 Move disk 1 from the peg A to the peg B
 Move disk 2 from the peg A to the peg C
 Move disk 1 from the peg B to the peg C
 Move disk 3 from the peg A to the peg B
 Move disk 1 from the peg C to the peg A
 Move disk 2 from the peg C to the peg B
 Move disk 1 from the peg A to the peg B

*/