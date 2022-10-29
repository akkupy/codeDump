#include<stdio.h>
#define n 50
int s[n],top=0,item;

int IsEmpty() {
    if(top==0)
        return 1;
    else
        return 0;
}

int IsFull() {
    if(top==n)
        return 1;
    else
        return 0;
}

void Push(int item) {
    if(IsFull())
    printf("Stack is full");
    else{
        s[top]=item;
        top+=1;
    }
}

int Pop() {
    int index=-1;
    if(IsEmpty())
        printf("Stack is empty");
    else {
        top-=1;
        index=top;
    }
    return index;
}

int Peek() {
    int index=-1;
    if(IsEmpty())
        printf("Stack is empty");
    else
        index=top-1;
    return index;
}

void Display() {
    if(IsEmpty())
        printf("Stack is empty");
    else {
        printf("Stack contents are:");
        for(int i=top-1;i>=0;i--)
            printf("%d ",s[i]);}
}
void main() {
    int ch,val,p;
    do {
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);

        switch(ch) {
            case 1:
                printf("Enter the item to be pushed:");
                scanf("%d",&item);
                Push(item);
                break;
            case 2:
                val=Pop();
                if(val!=-1)
                    printf("The popped value is:%d",s[val]);
                break;
            case 3:
                p=Peek();
                if(p!=-1)
                    printf("The top item is:%d",s[p]);
                break;
            case 4:
                Display();
                break;
            case 5:
                break;
        }       
    }while(ch!=5);
}



 