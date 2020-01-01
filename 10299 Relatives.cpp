#include<stdio.h>
#include<math.h>

long relative_test (long a, long b)

{
    long i , j , s=1 ;
    if(a<b)
    j=a ;
    else j=b ;
    for(i=1 ; i<=j ; i++)
    if(s<i && a%i==0 && b%i==0)
    {
      s=i ;
      break ;
    }
    return s ;
}

long prime_test (long n)

{
    long i , j , a ;
    if(n==2 || n==3)
    a=2 ;
    else
    {
     j=sqrt(n) ;
     for(i=2 ; i<=j ; i++)
      {
       if(n%i==0)
        {
         a=1 ;
         break ;
        }
      }
     if(i>j)
     a=2 ;
    }
    return a ;
}

int main ()

{
    long n , i , c , a , count ;
    while(scanf("%ld",&n)!=EOF)
    {
        if(n==0)
        break ;
        count=0 ;
        a=prime_test(n) ;
        if(a==2)
        {
            printf("%ld\n",n-1) ;
            continue ;
        }
        for(i=3 ; i<n ; i=i+2)
        {
           c=relative_test(n,i) ;
           if(c==1)
           count++ ;
        }
        if(n%2==0)
        printf("%ld\n",count+1) ;
        else printf("%ld\n",count+(n+1)/2) ;
    }
    return 0 ;
}
