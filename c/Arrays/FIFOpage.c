#include<stdio.h>
int main()
{
    int i,j,pf=0,f=0,np,nf,c,k;
    printf("enter the no. of pages: ");
    scanf("%d",&np);
    int ap[np];
    printf("enter the page numbers: \n");
    for ( i = 0; i < np; i++)
    {
        scanf("%d",&ap[i]);
    }

    printf("enter the no. of frames: ");
    scanf("%d",&nf);
    int af[nf];
    printf("enter the page numbers: \n");
    for ( i = 0; i < nf; i++)
    {
        af[i]=-1;
    }
    


    for ( i = 0; i<np; i++)
    {
        c=0;
        for ( j = 0; j<nf;j++)
        {
            if(ap[i]==af[j])
            {
                c=1;
                printf("%d \n",ap[i]);
                break;
            }
        }

        if(c!=1)
        {
            af[f]=ap[i];
            if(f+1<nf)
            {
            f++;
            }
            else
            {
            f=0;
            }
            pf++;
           printf("%d \t",ap[i]); 
           for ( k = 0; k<nf; k++)
           {
                printf("%d \t",af[i]); 
           }
            printf("\n"); 
        }
        
    }
    printf("page fault is %d",pf); 
    return 0;

}