#include<stdio.h>
int main()
{
    int i,j,pf=0,f=0,np,nf,c,k,m;
    printf("enter the no. of pages: ");
    scanf("%d",&np);
    int ap[np][2];
    printf("enter the page numbers: \n");
    for ( i = 0; i < np; i++)
    {
        scanf("%d",&ap[i][0]);
        ap[i][1]=i;
    }

    printf("enter the no. of frames: ");
    scanf("%d",&nf);
    int af[nf][2];
    printf("enter the page numbers: \n");
    for ( i = 0; i < nf; i++)
    {
        af[i][0]=-1;
    }
    


    for ( i = 0; i<np; i++)
    {
        c=0;
        for ( j = 0; j<nf;j++)
        {
            if(ap[i][0]==af[j][0])
            {
                c=1;
                af[j][1]=ap[i][1];
                printf("%d \n",ap[i][0]);
                break;
            }
        }

        if(c!=1)
        {
            m=10000;
            for(j=0;j<nf;j++)
            {   
                if(af[j][0]==-1)
                {
                    f=j;
                    break;
                }
                else 
                if(af[j][1]<m)
                {
                    f=j;
                    m=af[j][1];

                }
            }

          af[f][0]=ap[i][0];
          af[f][1]=ap[i][1];
            pf++;
           printf("%d \t",ap[i][0]); 
           for ( k = 0; k<nf; k++)
           {
                printf("%d \t",af[k][0]); 
           }
            printf("\n"); 
        }
        
    }
    printf("page fault is %d",pf); 
    return 0;

}