#include<stdio.h>
#include<malloc.h>

struct NODE {
	int info;
	struct NODE *link;
} ;

typedef struct NODE node;
node *top=NULL;

node *newnode(int val) {  
    node *p;
	p=(node *)malloc(sizeof(node));
	p->info=val;
	p->link=NULL;
	return p;
}

void Display() { 
	node *curr;
	curr=top;
	while(curr!=NULL) {
        printf("%d", curr->info);
		curr=curr->link;
		if(curr !=NULL)
			printf(" --> ");
	}
}

void push(int item) {
	node *p;
	p=newnode(item);
	if(p==NULL)
		printf("overflow");
	else
		p->info = item;
		p->link = top;
		top = p;
}

void pop() {
	node *ptr;
	ptr = top;
	if(ptr == NULL)
		printf("Underflow");
	else
		ptr = top;
		top = top->link;
		free(ptr);
}
void main() {
	int ch,item;
	
	do {
        printf("\n1. Insert \n2. Delete\n3. Display\n4. Quit\nEnter your Choice : ");
		scanf("%d",&ch);
		switch(ch) { 
			case 1:
                printf("\nvalue to be inserted:");
			    scanf("%d",&item); 
			    push(item);
			    break;
			case 2:
				pop();	
				break;	
			case 3:
				Display();	
				break;
			case 4: 
                break;
			
			default:printf("Invalid choice");
		}
	}while(ch!=4);
	
}
