#include<stdio.h>

void selection(int x[],int n)
{
    int i,j,minvalue,temp;
    for(i=0; i<n-1; i++)
    {
        minvalue=i;
        for(j=i+1; j<n; j++)
        {
            if(x[minvalue]>x[j])
            {
                minvalue=j;
            }
        }
        if(minvalue!=i)
        {
            temp=x[i];
            x[i]=x[minvalue];
            x[minvalue]=temp;
        }
    }
}


int main()
{
    int n,d,r,i,morning[100],evening[100],dtime,totaltime;
    while(scanf("%d%d%d",&n,&d,&r))
    {
        if(n==0 && d==0 && r==0)
            break;
        totaltime=0 ;
        for(i=0; i<n; i++)
            scanf("%d",&morning[i]) ;
        for(i=0; i<n; i++)
            scanf("%d",&evening[i]) ;
        selection(morning,n);
        selection(evening,n);
        for(i=0; i<n; i++)
        {
            dtime=morning[i]+evening[n-1-i];
            if(dtime>d)
                totaltime=totaltime+(dtime-d);
        }
        printf("%d\n",totaltime*r);

    }
    return 0;
}
