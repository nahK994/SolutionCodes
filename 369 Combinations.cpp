#include<stdio.h>
#include<string.h>
#define ll long long

ll ara[150][150] ;

ll ncr(ll n , ll r)
{
    if(ara[n][r]!=0) return ara[n][r] ;
    if(n==r) return ara[n][r]=1 ;
    if(r==1) return ara[n][r]=n ;
    return ara[n][r]=ncr(n-1,r-1)+ncr(n-1,r) ;
}

int main()
{
    ll i , n , r , a ;
    memset(ara,0,sizeof(ara)) ;
    while(scanf("%lld%lld",&n,&r)!=EOF && (n!=0 || r!=0))
    {
        a=ncr(n,r) ;
        printf("%lld things taken %lld at a time is %lld exactly.\n",n,r,a) ;
    }
}
