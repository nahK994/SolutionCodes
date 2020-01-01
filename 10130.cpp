#include<stdio.h>
#include<string.h>
#define ll long long

ll ara[1050][80] , price[1050] , weights[1050] , W ;

ll rec(ll i , ll a)
{
    if(i==0 || a<1) return 0 ;
    if(ara[i][a]!=0) return ara[i][a] ;
    ll profit1 , profit2 ;
    if(weights[i]<=a) profit1=price[i]+rec(i-1,a-weights[i]) ;
    else profit1=0 ;
    profit2=rec(i-1,a) ;
    if(profit1>profit2) return ara[i][a]=profit1 ;
    return ara[i][a]=profit2 ;
}

int main()
{
    ll test , i , g , a , n ,sum ;
    scanf("%lld",&test) ;
    while(test--)
    {
        memset(ara,0,sizeof(ara)) ;
        memset(price,0,sizeof(price)) ; memset(weights,0,sizeof(weights)) ;
        scanf("%lld",&n) ;
        for(i=1 ; i<=n ; i++) scanf("%lld%lld",&price[i],&weights[i]) ;
        scanf("%lld",&g) ;
        sum=0 ;
        for(i=0 ; i<g ; i++)
        {
            scanf("%lld",&W) ; sum+=rec(n,W) ;
        }
        printf("%lld\n",sum) ;
    }
    return 0 ;
}
