#include<stdio.h>
#include<conio.h>
#include<string.h>
int top=-1;
char stack[10];

void push(char ch){
if(top==9)
	printf("Stack is full");
else
	stack[++top]=ch;
}

char pop(){
char c1;
if(top==-1)
	printf("stack is empty");
else
	c1=stack[top--];
return c1;
}

//Paranthesis checker using Stack

void main(){
char exp[10],tp;
int i,flag=1;
clrscr();
printf("Enter the expression: ");
gets(exp);
for(i=0;i<strlen(exp);i++){
	if(exp[i]=='('||exp[i]=='{'||exp[i]=='['){
		push(exp[i]);
	}
	if(exp[i]==')'||exp[i]=='}'||exp[i]==']'){
		if(top==-1)
			flag=0;
		else
			tp=pop();
	}
	if(exp[i]==')'&&(tp=='{'||tp=='['))
		flag=0;
	if(exp[i]=='}'&&(tp=='('||tp=='['))
		flag=0;
	if(exp[i]==']'&&(tp=='{'||tp=='('))
		flag=0;
}
if(top>=0)
	flag=0;
if(flag==1)
	printf("match");
else
	printf("Mismatch");

getch();
}