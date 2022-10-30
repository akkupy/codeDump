#include<stdio.h>
int main()
{
    int i,j,pf=0,np,nf,c,k,m;
    printf("enter the no. of pages: ");
    scanf("%d",&np);
    int ap[np],f[np];
    printf("enter the page numbers: \n");
    for ( i = 0; i < np; i++)
    {
        scanf("%d",&ap[i]);
        f[i]=0;
    }

    printf("enter the no. of frames: ");
    scanf("%d",&nf);
    int af[nf][3];
    printf("enter the page numbers: \n");
    for ( i = 0; i < nf; i++)
    {
        af[i][0]=-1;
        af[i][1]=0;
        af[i][2]=-1;
    }


    for ( i = 0; i < np; i++)
    {
        for ( j = 0; j < nf; j++)
        {
            if(af[j][0]==-1)
            {
                af[j][0]=ap[i];
                af[j][1]=1;
                af[j][2]=i;
                pf++;
                printf("%d \t",ap[i]); 
                for ( k = 0; k<nf; k++)
                {
                    printf("%d \t",af[k][0]); 
                }
                 printf("\n"); 
                 break;
            }
            else 
            if(af[j][0]==ap[i])
            {
                af[j][1]++;
                printf("%d \n",ap[i]);
                break;
            }
        }
        if(j==nf)
        {
            int min=0,c=0;
            for ( k = 1; k < nf; k++)
            {
                if(af[k][1]<af[min][1])
                {
                    min=k;
                }
                if(af[k][2]<af[min][2] && af[k][1]==af[min][1])
                {
                    min=k;
                }
            }
            af[min][0]=ap[i];
            af[min][1]=1;
            af[min][2]=i;
            pf++;
            printf("%d \t",ap[i]); 
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