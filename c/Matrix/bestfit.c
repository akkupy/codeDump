#include<stdio.h>
int main()
{
    int np,nb,min=1000,i,j,pos=0;
    printf("enter the no. of processes: ");
    scanf("%d",&np);
    int ap[np][2];
    printf("enter the size of processes: \n");
    for(i=0;i<np;i++)
    {
        printf("p[%d]: ",i+1);
        scanf("%d",&ap[i][0]);
        ap[i][1]=0;
    }



    printf("enter the no. of blocks: ");
    scanf("%d",&nb);
    int ab[nb][3];
    printf("enter the size of blocks: \n");
    for(i=0;i<nb;i++)
    {
        printf("b[%d]: ",i+1);
        scanf("%d",&ab[i][0]);
        ab[i][1]=0;
        ab[i][2]=0;
    }


    for(i=0;i<np;i++)
    {
        for(j=0;j<nb;j++)
        {
            if(ap[i][0]<ab[j][0] && ab[j][1]==0)
            {
                if((ab[j][0]-ap[i][0])<min)
                {
                    min=ab[j][0]-ap[i][0];
                    pos=j;
                }
            }
        } 

        if(ap[i][0]<ab[pos][0] )
            {  ab[pos][1]=i+1;
             ab[pos][2]=ap[i][0];
             ap[i][1]=1;
             min=1000;
              pos=0; 
            } 
    }

    printf("block\tsize\tprocess\tsize\tstatus\n");
    for(i=0;i<nb;i++)
    {
         printf("b[%d]\t\t%d\t\t%d\t\t%d\t\t",i+1,ab[i][0],ab[i][1],ab[i][2]);
        if(ab[i][1]==0)
        printf("not allocated\n");
        else
         printf("allocated\n");
    }

    return 0;

}