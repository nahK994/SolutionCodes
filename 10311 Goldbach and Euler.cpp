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
  /*  long p , r , s , t , u=0 , v , ara[1000000] , p[1000000]={0} ;
    r=sqrt(1000000) ;
    for(p=1 ; p<=1000000 ; p++)
    ara[p]=p ;
    for(q=1 ; q<=r ; q++)
    {
        if(ara[q]!=1)
        {
           for(s=q+q ; s<=1000000 ; s=s+q)
           {
               ara[s]=1 ;
           }
        }
    }
    for(t=1 ; t<=1000 ; t++)
    {
        if(ara[t]!=1)
        {
            u++ ;
            p[u]=t ;
        }
    }*/
      long a , b , c=n/2 ;
      if(c%2==0)
      b=c+1 ;
      else b=c ;
      for( ; b>2 ; b-=2)
      {
        a=n-b ;
        if(prime_test(a)==2 && prime_test(b)==2)
        {
          if(a>b)
          printf("%ld is the sum of %ld and %ld.\n",n,b,a) ;
          else printf("%ld is the sum of %ld and %ld.\n",n,a,b) ;
          break ;
        }
      }
      if((prime_test(a)==1 || prime_test(b)==1) && prime_test(n-2)==2)
      printf("%ld is the sum of 2 and %ld.\n",n,n-2) ;
      else if(prime_test(a)==1 || prime_test(b)==1)
      printf("%ld is not the sum of two primes!\n",n) ;
     }
     return 0 ;
}

