#include<stdio.h>

long long per(long long n)
{
    return n*(n-1) ;
}

int main()
{
    long long n , m , a , b , sum ;
    while(scanf("%lld%lld",&n,&m)!=EOF)
    {
        if(n==0 && m==0) break ;
        if(m<n)
        {
            a=m ;
            m=n ;
            n=a ;
        }
        sum=2*(m-n-1)*per(n) ;
        for(b=2 ; b<=n ; b++)
        sum=sum+4*per(b) ;
        //if(n==m) sum=sum-2*per(n) ;
        sum=sum+m*per(n) ;
        sum=sum+n*per(m) ;
        printf("%lld\n",sum) ;
    }
    return 0 ;
}
