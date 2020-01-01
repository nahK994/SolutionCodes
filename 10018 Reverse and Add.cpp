#include<stdio.h>

long long g(long long n)

{
    long long a=0 , b , sum=0 , product=1 , c , q , ara[1000] ;
    q=n ;
    while(q!=0)
    {
        ara[a]=q%10 ;
        q=q/10 ;
        a++ ;
    }
    a-- ;
    for(b=a ; b>=0 ; b--)
    {
        c=product*ara[b] ;
        sum=sum+c ;
        product*=10 ;
    }
    return sum ;
}

int main ()

{
   long long a , b , n , c , count ;
   scanf("%lld",&b) ;
   for(a=1 ; a<=b ; a++)
   {
       count=0 ;
       scanf("%lld",&n) ;
       c=g(n) ;
       while(n!=c)
       {
           n=c+n ;
           c=g(n) ;
           count++ ;
       }
       printf("%lld %lld\n",count,c) ;
   }
   return 0 ;
}
