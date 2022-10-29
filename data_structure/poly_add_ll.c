#include<stdio.h>
#include<stdlib.h>
struct poly {
	int e,c;
	struct poly*next;
};
struct poly*p,*p1,*p2,*current;
struct poly*t,*dum;


struct poly* insert(struct poly*p,int c,int e) { 

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


struct poly* add_poly(struct poly*a1,struct poly*a2)  {
	int c;int e;
	struct poly*a=NULL;
	while(a1!=NULL && a2!=NULL) {
		if(a1->e == a2->e) {
			c=a1->c+a2->c;
			e=a1->e;
			a1=a1->next;
			a2=a2->next;
		}
		else if(a1->e > a2->e) {
			c=a1->c;
			e=a1->e;
			a1=a1->next;
		}
		else {
			c=a2->c;
			e=a2->e;
			a2=a2->next;
		}
		if(c!=0)
			a=insert(a,c,e);
	}
	while(a1!=NULL) {
		a=insert(a,a1->c,a1->e);
		a1=a1->next;
	}
	while(a2!=NULL) {
		a=insert(a,a2->c,a2->e);
		a2=a2->next;
	}
	return a;
}


void display(struct poly*h)	{
    current=h;
    while(current!=NULL) {
        printf("%dx^%d",current->c,current->e);
        current=current->next;
        if(current!=NULL)
            printf("+");
    }
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
    p=add_poly(p1,p2);
    display(p);
    return 0;
}