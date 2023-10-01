#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push(){
    int x;
    if(top == MAX - 1){
        printf("Overflow\n");
    }
    else{
        printf("Enter Data : ");
        sacnf("%d", &x);
        top ++;
        stack[top] = x;
    }
}

void pop(){
    if(top == -1){
        printf("Stack is Empty\n");
    }
    else{
        printf("Popped Element : %d\n", stack[top]);
        top--;
    }
}

void display(){
    if(top == -1){
        printf("Stackis Empty\n");
    }
    else{
        printf("The Stack is : ");
        for(int i = top; i >= 0; i --){
            printf("%d\t", stack[i]);
        }
    }
}

void peek(){
    if(top == -1){
        printf("Stackis Empty\n");
    }
    else{
        printf("%d", stack[top]);
    }
}

int main(){



    return 0;
}