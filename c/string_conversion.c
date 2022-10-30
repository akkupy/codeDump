#include <stdio.h>

// String Lowecase to Uppercase
 
int main()
{
    char string[100];
 
    printf("Enter the string in Lowercase: ");
    scanf("%s", &string);
    
    printf("The string in lowercase ='%s'\n", string);
     
    for(int i=0; string[i]; i++)  
    {
        if(string[i] >= 97 && string[i] <= 122)
        {
        string[i] = string[i] - 32;
        }
 	}
 	
    printf("The string in Uppercase: '%s'\n", string);
 
    return 0;
}
