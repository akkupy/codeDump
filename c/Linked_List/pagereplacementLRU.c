#include<stdio.h>
int main()
{
    int np,nf,i,j,f=-1,c,pfc=0,n,m,k;
    printf("Enter number of pages ");
    scanf("%d",&np);
    int ap[np][2];
    printf("Enter page number : \n");
    for(i=0;i<np;i++)
    {
        scanf("%d",&ap[i][0]);
        ap[i][1]=i;
    }
    printf("Enter number of frames : ");
    scanf("%d",&nf);
    int af[nf][2];
    for(i=0;i<nf;i++)
    {
        af[i][0]=-1;
    }
    for(i=0;i<np;i++)
    {
        c=0;
        for(j=0;j<nf;j++)
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
            for(n=0;n<nf;n++)
            {
                if(af[n][0]==-1)
                {
                    f=n;
                    break;
                }
                else if(af[n][1]<m)
                {
                    f=n;
                    m=af[n][1];
                }
            }
            af[f][0]=ap[i][0];
            af[f][1]=ap[i][1];
            pfc++;
            printf("%d \t",ap[i][0]);
            for(k=0;k<nf;k++)
            {
                printf("%d ",af[k][0]);
            }
            printf("\n");
        }
    }
    printf("Page fault is %d",pfc);
    return 0;
}