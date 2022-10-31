#include<stdio.h>

int main(){
    int a, b, c, d;
    printf("Enter four numbers: \n");
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if(a>b && a>c && a>d){
        printf("The greatest number is %d",a);
    }
    else if(b>a && b>c && b>d){
        printf("The greatest number is %d", b);
    }
    else if(c>a && c>b && c>d){
        printf("The greatest number is %d",c);
    }
    else{
        printf("The greatest numner is %d",d);
    }
    return 0;
}
