#include<stdio.h>
#include<stdlib.h>
struct poly
{
	int e,c;
	struct poly*next;
};
struct poly*p,*p1,*p2,*current;
struct poly*t,*dum;


struct poly* insert(struct poly*p,int c,int e)  { 
    t = (struct poly*) malloc(sizeof(struct poly));
    dum = (struct poly*) malloc(sizeof(struct poly));
    t->c=c;
    t->e=e;
    dum->next=p;
    current=dum;
    while(current->next!=NULL && current->next->e>e)
  	    current=current->next;
    t->next=current->next;
    current->next=t;
    p=dum->next;
    dum->next=NULL;
    free(dum);
    dum=NULL;
    current=NULL;
    t=NULL;
    return p;
}


void display(struct poly*h) {
    current=h;
    while(current!=NULL) {
        printf("%dx^%d",current->c,current->e);
    current=current->next;
    if(current!=NULL)
       printf("+");
    }
}


void modify(struct poly*p) {
	struct poly*temp,*current,*todelete;
	temp=p;
	while(temp!=NULL) {
		current=temp;
 		while(current->next!=NULL) {
 			if(current->next->e==temp->e) {
 			    temp->c=temp->c+current->next->c;
 			    todelete=current->next;
 			    current->next=todelete->next;
 			    todelete->next=NULL;
 			    free(todelete);
 			    todelete=NULL;
 			}
 			current=current->next;
 		}
 		temp=temp->next;
 	}
 	temp=NULL;
 	current=NULL;
}
 
 
struct poly* mlp_poly(struct poly*a1,struct poly*a2) {
    int c;int e;
    struct poly*p2 = a2;
    struct poly*a = NULL;
    while(a1!=NULL) {
  	    while(p2!=NULL) {
  		    c=a1->c*p2->c;
  		    e=a1->e+p2->e;
  		    a=insert(a,c,e);
  		    p2=p2->next;
  	    }
  	    p2=a2;
  	    a1=a1->next;
    }
    modify(a);
    return a;
}  


int main() {
    int n1,n2,c,e,i;
    p = (struct poly*) malloc(sizeof(struct poly));
    printf("Polynomial 1--");
    printf("\nNo.of terms:");
    scanf("%d",&n1);
    for(i=0;i<n1;i++) {
        printf("coeff.:");
        scanf("%d",&c);
        printf("exp.:");
        scanf("%d",&e);
        p1=insert(p1,c,e);
    }
    printf("Polynomial 2--");
    printf("\nNo.of terms:");
    scanf("%d",&n2);
    for(i=0;i<n2;i++) {
        printf("coeff.:");
        scanf("%d",&c);
        printf("exp.:");
        scanf("%d",&e);
        p2=insert(p2,c,e);
    }
    printf("Polynomial 1:");
    display(p1);
    printf("\nPolynomial 2:");
    display(p2);
    printf("\nResult:");
    p=mlp_poly(p1,p2);
    display(p);
    return 0;
}