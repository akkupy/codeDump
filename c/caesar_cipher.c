/*
WAP to read any string/message from the user in uppercase
Encrypt the string by shifting each alphabet x(<256) places.
If the alphabet is 'Z' and x is 3 then it would be ']' but make it in a way so that it gives 'C'.
This is CaesarCipher Algorithm
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main()
{

    char ch[100], s[100];
    int x, j = 0;

    printf("Type your code: \n");
    scanf("%s", &ch);

    while (s[j]) // converting to uppercase
    {
        s[j] = toupper(ch[j]);
        j++;
    }

    printf("Original code is \n");
    for (int i = 0; i < strlen(s); i++)
    {
        printf("%c", s[i]);
    }

    printf("\n Enter any number < 256 \n");
    scanf("%d", &x);

    printf("\n Encrypted code is \n");

    if (x < 256)
    {
        for (int i = 0; i < strlen(s); i++)
        {
            int a = fabs((int)s[i] + x);

            if (a > (int)'Z')
            {
                int d = (a - (int)'Z') % 26;
                if (d != 0)
                    s[i] = (char)(64 + d);
                else
                    s[i] = 'Z';
            }
        }

        for (int i = 0; i < strlen(s); i++)
        {
            printf("%c", s[i]);
        }
    }
    else
        printf("Wrong input");
    return 0;
}

/*
OUTPUT:

Type your code:
ABCD
Original code is
ABCD
Enter any number < 256
58
Encrypted code is
GHIJ

*/  