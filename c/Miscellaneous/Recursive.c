#include<stdio.h>

void simplemerge(int x[] , int l , int s , int r )

{

    int temp[30], k=0, i=l, j=s ;

    while(i<s && j<=r)

    {

        if(x[i]<x[j])

            temp[k++]=x[i++];

        else

            temp[k++]=x[j++];

    }

    while(i<s)

        temp[k++]=x[i++];

    while(j<=r)

        temp[k++]=x[j++];

    for(i=l, j=0; j<k;  )

        x[i++]=temp[j++];

}

void mergesort(int a[] , int l , int r)

{

    int m;

    if(l<r)

    {

        m=(l+r)/2;

        mergesort(a,l,m);

        mergesort(a,(m+1),r);

        simplemerge(a, l , (m+1), r);

    }

}

void main()

{

    int a[50], n , i ;

    printf("Enter the  no of elements:  ");

    scanf("%d",&n);

    printf("Enter the elements : \n");

    for(i=0;i<n;i++)

    {

        scanf("%d",&a[i]);

    }      

    mergesort(a,0,(n-1));

    printf(" sorted array is :  ");

    for(i=0;i<n;i++){

        printf("%d",a[i]);

        if(i!=n-1)

            printf(" , ");

    }

}













 
