#include<stdio.h>

long prime_test (long n)
{
    if(n == 2) return 2;
    if(n % 2 == 0) return 1;
    for(long i=3 ; i*i<=n ; i+=2)
    if(n%i==0) return 1;
    return 2 ;
}

int main ()

{
    long n , count ;
    while(scanf("%ld",&n)!=EOF)
    {
      if(n==0)
      break ;
      if(n==4)
      {
          printf("1\n") ;
          continue ;
      }
      count=0 ;
      long i , a ;
      for(i=3 ; i<=n ; i+=2)
      {
        a=n-i ;
        if(i>a) break ;
        if(prime_test(a)==2 && prime_test(i)==2) count++ ;
      }
      printf("%ld\n",count) ;
    }
     return 0 ;
}


