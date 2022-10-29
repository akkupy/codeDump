#include <stdio.h>
#include <stdlib.h>
#include<string.h>
char c[50];
int top=-1;
float op1,op2,r,a;
float s[50];
int push(int top,float tok){
	s[++top]=tok;
	return top;
}
float pop(int top){
	r=s[top];
	return r;
}
int operate(int top,char tok){
    if(top==-1)
        return top;
    op1=pop(top);
    top=top-1;
    op2=pop(top);
    top=top-1;
    switch(tok){
        case '+':a=op2+op1;
		 top=push(top,a);
                 break;
        case '-':a=op2-op1;
		 top=push(top,a);
		 break;
	case '*':a=op2*op1;
		 top=push(top,a);
                 break;
        case '/':a=op2/op1;
		 top=push(top,a);
		 break;
    }
    return top;
}
int main(){
	printf("Enter postfix expression:\n");
	scanf("%s",c); 
	for(int i=0;i<strlen(c);i++){
		char tok=c[i];
        	if((tok=='+')||(tok=='-')||(tok=='*')||(tok=='/'))
        		top=operate(top,tok);
		else
			top=push(top,atof(&tok));
	}
        top=pop(top);
	printf("Result is : %.2f",r);
	return 0;
}
