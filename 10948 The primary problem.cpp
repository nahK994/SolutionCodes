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
    long n ;
    while(scanf("%ld",&n)!=EOF)
    {
      if(n==0)
      break ;
      if(prime_test(2)==2 && prime_test(n-2)==2)
      {
          printf("%ld:\n2+%ld\n",n,n-2) ;
          continue ;
      }
      long i , a ;
      for(i=3 ; i<=n ; i+=2)
      {
        a=n-i ;
        if(prime_test(a)==2 && prime_test(i)==2)
        {
          printf("%ld:\n%ld+%ld\n",n,i,a) ;
          break ;
        }
        else if(a<=i)
        break ;
      }
      if(prime_test(a)==1 || prime_test(i)==1)
      printf("%ld:\nNO WAY!\n",n) ;
     }
     return 0 ;
}
