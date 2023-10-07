#include<stdio.h>
int main()
{
    int num,org_num,remainder,result=0;
    printf("Enter the number: ");
    scanf("%d",&num);
    org_num = num;

    while(org_num!=0){
        remainder = org_num%10;
        result = result+(remainder * remainder * remainder);

        org_num = org_num/10;
    }

    if(org_num==num){
        printf(num,"Its armstrong number.");
    }
    else{
        printf(num,"Its not an armstrong number.");
    }
    return 0;

}