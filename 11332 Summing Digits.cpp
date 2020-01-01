#include<stdio.h>

long g (long n)
{
    long j , sum=0 ;
    while(n!=0)
    {
       j=n%10 ;
       sum=sum+j ;
       n=n/10 ;
    }
    return sum ;
}

int main ()

{
    long a ;
    while(scanf("%ld",&a)!=EOF)
    {
        if(a==0)
        break ;
        long b=g(a) ;
        while(b>=10)
        b=g(b) ;
        printf("%ld\n",b) ;
    }
    return 0 ;
}
