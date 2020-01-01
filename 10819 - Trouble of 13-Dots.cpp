#include<stdio.h>
#include<string.h>

struct info
{
    long p , f ;
} data[200];

long ara[200][15010] , m , n ;

long rec(long a , long cost)
{
    if(cost > m && m < 1800)
        return -10;
    if(cost > m + 200)
        return -10;
    if(a == n)
    {
        if(cost > m && cost <= 2000)
            return -10;
        return 0;
    }

    if(ara[a][cost] != -1)
        return ara[a][cost] ;

    long b = 0 , c = 0 ;
    b = rec(a+1,cost) ;
    c = data[a].f + rec(a+1,cost+data[a].p) ;

    ara[a][cost] = (b>c)? b:c ;
    return ara[a][cost] ;
}

int main()
{
    long a ;
    while(scanf("%ld%ld",&m,&n)!=EOF)
    {
        for(a=0 ; a<n ; a++)
            scanf("%ld%ld",&data[a].p,&data[a].f) ;
        memset(ara,-1,sizeof ara) ;
        a=rec(0,0) ;
        printf("%ld\n",a) ;
    }
    return 0 ;
}
