#include<stdio.h>
#include<string.h>

long p[200] , c[200] , w[200] , W , n , ara[200][10010] ;

long max(long a , long b)
{
    if(a>b) return a ;
    return b ;
}

long rec(long weight , long size)
{
    long price1=0 , price2=0 ;
    if(size==n || weight==0)
        return 0 ;

    if(ara[size][weight]!=-1)
        return ara[size][weight] ;

    if(weight-w[size]>=0)
        price1 += p[size] + rec(weight-w[size] , size) ;
    price2 += rec(weight , size+1) ;
    return ara[size][weight] = max(price1 , price2) ;

}

int main()
{
    long loop , test , a , b , sum ;
    scanf("%ld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        sum=0 ;
        memset(ara,-1,sizeof(ara)) ;
        scanf("%ld%ld",&n,&W) ;
        for(a=0 ; a<n ; a++)
        {
            scanf("%ld%ld%ld",&p[a],&c[a],&w[a]) ;
            sum+=w[a]*c[a] ;
        }

        if(sum>W)
        {
            printf("Case %ld: Impossible\n",loop) ;
            continue ;
        }

        a=rec(W-sum , 0) ;

        printf("Case %ld: %ld\n",loop,a) ;
    }
}
// summit.haque@gmail.com

/*

2
2 13
10 1 5
1 1 1
3 27
10 7 2
12 1 5
8 1 1

Case 1: 12
Case 2: 56

*/
