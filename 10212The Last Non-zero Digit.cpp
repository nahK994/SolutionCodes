#include<stdio.h>
#include<math.h>

int main()
{
    long n , m , pr , b ;
    while(scanf("%ld%ld",&n,&m)!=EOF)
    {
        pr=1 ;
        for(b=n ; b>=n-m+1 ; b--)
        {
            pr*=b ;
            while(pr%10==0) pr/=10 ;
            pr=pr%1000000000 ;
        }
        pr%=10 ;
        printf("%ld\n",pr) ;
    }
    return 0 ;
}
