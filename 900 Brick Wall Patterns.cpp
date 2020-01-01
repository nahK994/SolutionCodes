#include<stdio.h>

int main ()

{
    long long i , j , k , l , a[100] , n ;
    a[0]=1 ;
    a[1]=1 ;
    for(i=2 ; i<=50 ; i++)
    a[i]=a[i-1]+a[i-2] ;
    while(scanf("%lld",&n)!=EOF)
    {
       if(n==0) break ;
       printf("%lld\n",a[n]) ;
    }
    return 0 ;
}
