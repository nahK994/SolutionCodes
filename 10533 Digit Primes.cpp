#include<stdio.h>

long prime_test(long n)

{
    if(n==2) return 2 ;
    if(n%2==0 || n<=1) return 1 ;
    for(long long i=3 ; i*i<=n ; i+=2)
    if(n%i==0) return 1 ;
    return 2 ;
}

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

long Digit_Primes(long n)

{
   long a=g(n) ;
   while(a<10)
   a=g(a) ;
   if(prime_test(a)==2) return 2 ;
   return 1 ;
}

int main ()

{
    long i , j ;
    scanf("%ld",&j) ;
    for(i=1 ; i<=j ; i++)
    {
        long a , b , count=0 ;
        scanf("%ld%ld",&a,&b) ;
        long p ;
        if(a==2) count++ ;
        if(a%2==0) p=a+1 ;
        else p=a ;
        for( ; p<=b ; p+=2)
        {
          if(Digit_Primes(p)==2) count++ ;
        }
        printf("%ld\n",count) ;
    }
    return 0 ;
}
