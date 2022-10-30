#include<stdio.h>
#define size 50
char stack[size];
int top = 0;

int isempty() {
	if(top==0)
		return 1;
	else 
		return 0;
}

int isfull() {
	if(top==size)
		return 1;
	else
		return 0;
}

void push(char x) {
	if(isfull())
		printf("Stack is full!!!");
	else
		stack[top++]=x;
}

char pop() {
	if(isempty())
		printf("Stack is empty !!!");
	else
		return stack[--top]; 
}

int inputpriority(char c) {
	switch(c) { 
		case '-': return 1;break;
		case '+': return 1;break;
		case '*': return 3;break;
		case '/': return 3;break;
		case '^': return 6;break;
	}
}

int stackpriority(char c) {
	switch(c) { 
		case '-':return 2;break;
		case '+': return 2;break;
		case '*':return 4;break;
		case '/': return 4;break;
		case '^': return 5;break;
		case '(': return 0;break;
	}
}
void displaystack() {
	int i;
	printf("\t stack : ");
	for(i=0;i<top;i++)
		printf("%c ",stack[i]);
}
void displaypost(char a[],int k) {
	int i;
	printf("\t postfix : ");
	for(i=0;i<k;i++)
		printf("%c ",a[i]);
}
char peek() {
	return(stack[top-1]);
	
}

int main() {
	char token,c,expr[100],post[100];
	int i,j=0;
	printf("Enter the Expression : ");
	scanf("%[^\n]",&expr);
	for(i=0;expr[i]!='\0';i++) { 
        token=expr[i];
		switch(token) { 
			case '(': 
                push(token);break;
			case ')': {
				while((c=pop())!='(')
				post[j++]=c;
				break;
			}
			case '-': {
				while(!isempty() && (stackpriority(peek())>inputpriority(token))) {
					post[j++]=pop();
				}
				push(token);
				break;
			}
			case '+': {	
				while(!isempty() && (stackpriority(peek())>inputpriority(token))) {
					post[j++]=pop();
				}
				push(token);
				break;
			}
			case '*': {	
				while(!isempty() && (stackpriority(peek())>inputpriority(token))) {
					post[j++]=pop();
				}
				push(token);
				break;
			}
			case '/': {
				while(!isempty() && (stackpriority(peek())>inputpriority(token))) {
					post[j++]=pop();
				}
				push(token);
				break;
			}
			case '^': {
				while(!isempty() && (stackpriority(peek())>inputpriority(token))) {
					post[j++]=pop();
				}
				push(token);
				break;
			}
			default: post[j++]=token;
		}
		printf("\n Token: %c",token);
		displaystack(); 
		displaypost(post,j);
	}
	while(!isempty())
		post[j++]=pop();
	post[j]='\0';
			printf("\n Postfix: %s \n",post);
			return 0;
}
