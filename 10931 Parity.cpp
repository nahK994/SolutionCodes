#include<stdio.h>

int main ()

{
    long n ;
    while(scanf("%ld",&n)!=EOF)
    {
        if(n==0) break ;
        long c=0 , count=0 , p=1 , sum=0 , ara[100]={0} ;
        char a[100]={0} ;
        while(n!=0)
        {
          a[c]=n%2+48 ;
          if(a[c]==49) count++ ;
          n=n/2 ;
          c++ ;
        }
        c=c-1 ;
        printf("The parity of ") ;
        for( ; c>=0 ; c--)
        printf("%c",a[c]) ;
        printf(" is %ld (mod 2).\n",count) ;
    }
    return 0 ;
}
