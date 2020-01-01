#include<stdio.h>
#include<string.h>
#include<stack>
#include<vector>
using namespace std ;

long coins[60] , ara[60][2010] , number_of_coins[60] ;

long rec(long size , long amount)
{
    if(amount==0) return 1 ;
    if(size<0) return 0 ;

    if(ara[size][amount]!=-1) return ara[size][amount] ;
    ara[size][amount]=0 ;

    for(long i=0 ; i<=number_of_coins[size] ; i++)
        if(amount-coins[size]*i>=0)
            ara[size][amount]+=rec(size-1 , amount-coins[size]*i)%100000007 ;
    return ara[size][amount]%100000007 ;
}

int main()
{
    long loop , test , a , b , n , dst ;
    scanf("%ld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        memset(ara,-1,sizeof(ara)) ;
        scanf("%ld%ld",&n,&dst) ;
        for(a=0 ; a<n ; a++)
            scanf("%ld",&coins[a]) ;
        for(a=0 ; a<n ; a++)
            scanf("%ld",&number_of_coins[a]) ;

        a=rec(n-1,dst) ;
        printf("Case %ld: %ld\n",loop,a) ;
    }
}


/*
5
2 3
1 2 1 1
3 3
1 2 5 2 2 1
3 5
1 2 5 2 2 1
3 5
1 2 5 3 2 1
3 5
1 2 5 10 10 10


1
1
2
3
4



2
3 5
1 2 5 3 2 1
4 20
1 2 3 4 8 4 2 1


3
9

*/

