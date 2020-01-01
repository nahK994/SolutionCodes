#include<stdio.h>

long Cube_Test(long n,long a)

{
   long i , j=n-a ;
   i=a*a*a ;
   j=j*j*j ;
   if(i+j==n) return 2 ;
   else return 1 ;
}

int main ()

{
    long n ;
    while(scanf("%ld",&n)!=EOF)
    {
        if(n==0)
        break ;
        long i , a ;
        for(i=1 ; i<n ; i++)
        {
            if(Cube_Test(n,i)==2)
            break ;
        }
        printf("%ld %ld\n",n-a,a) ;
    }
    return 0 ;
}

