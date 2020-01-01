#include<stdio.h>
#include<math.h>

long long H(long n)
{
    long long res=0 , a , i , b , count=0 ;
    a=sqrt(n) ;
    for(i=1 ; i<=a ; i++)
      {
        if(n%i==0)
        {
            res=n/i+i ;
            count+=2 ;
        }
        else res=n/i ;
      }
    if(a*a==n)
    {
        res-=i ;
        count-=2 ;
    }
    return res+n-count ;
}

int main ()

{
    int i , j ;
    scanf("%d",&j) ;
    for(i=1 ; i<=j ; i++)
    {
        long long a ;
        long n ;
        scanf("%ld",&n) ;
        a=H(n) ;
        printf("%lld\n",a) ;
    }
    return 0 ;
}
