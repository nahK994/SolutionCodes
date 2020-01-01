#include<stdio.h>
#include<math.h>
const long s = 5000 ;
long a[s] ;

void sieve()
{
    long a[5000] , i1 , j1 , p1 , z1=sqrt(5000) ;
    a[0]=1 ;
    for(i1=1 ; i1<5000 ; i1++)
    {
        a[i1]=i1 ;
    }
    for(j1=2 ; j1<=z1 ; j1++)
    {
        if(a[j1]!=1)
        {
            for(p1=2*j1 ; p1<5000 ; p1=p1+j1)
            a[p1]=1 ;
        }
    }
}

int main ()

{
    /*long a[50000300] , i1 , j1 , p1 , z1=sqrt(50000300) ;
    a[0]=1 ;
    for(i1=1 ; i1<50000300 ; i1++)
    {
        a[i1]=i1 ;
    }
    for(j1=2 ; j1<=z1 ; j1++)
    {
        if(a[j1]!=1)
        {
            for(p1=2*j1 ; p1<50000300 ; p1=p1+j1)
            a[p1]=1 ;
        }
    }*/
    long n ;
    while(scanf("%ld",&n)!=EOF)
    {
        long r=0 , b=n/2 ;
        if(b%2==0) b=b+1 ;
        for( ; b>2 ; b-=2)
        {
          r=n-b ;
          if(a[r]!=1 && a[b]!=1 && b!=r)
          {
            if(r>b)
            printf("%ld is the sum of %ld and %ld.\n",n,b,r) ;
            else printf("%ld is the sum of %ld and %ld.\n",n,r,b) ;
            break ;
          }
        }
        if((a[r]==1 || a[b]==1) && n!=1 && a[n-2]!=1)
        printf("%ld is the sum of 2 and %ld.\n",n,n-2) ;
        else if(a[r]==1 || a[b]==1)
        printf("%ld is not the sum of two primes!\n",n) ;
      }
    return 0 ;
}

