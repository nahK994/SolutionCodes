#include<stdio.h>

int main ()

{
    long long i , j , k , l , a[100] , n ;
    a[0]=1 ;
    a[1]=1 ;
    for(i=2 ; i<=51 ; i++)
    a[i]=a[i-1]+a[i-2] ;
    scanf("%lld",&k) ;
    for(j=1 ; j<=k ; j++)
    {
       scanf("%lld",&n) ;
       printf("Scenario #%lld:\n",j) ;
       printf("%lld\n\n",a[n+1]) ;
    }
    return 0 ;
}

