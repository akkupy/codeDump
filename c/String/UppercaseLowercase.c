#include<stdio.h>

int main(){

    char ch;
    printf("Enter a character: \n");
    scanf("%c",&ch);
    if(ch>=65 && ch<=90){
        printf("The given input character is an uppercase character");
    }
    else if(ch>=97 && ch<=122){
        printf("The given input character is a lowercase character");
    }
    else{
        printf("The given input is not a character");
    }
    return 0;
}
