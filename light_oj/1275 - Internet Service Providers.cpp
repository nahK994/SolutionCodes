#include<stdio.h>
#include<math.h>

int main()
{
    long loop , test , a ;
    double n , c , d ;
    char cc ;
    scanf("%ld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        scanf("%lf%lf",&n,&c) ;
        if(n==0)
            d=0 ;
        else
            d=(double)c/(2*n) ;
        if(d - (int)d > 0.5)
            d = ceil(d) ;
        a=d ;
        printf("Case %ld: %ld\n",loop,a) ;
    }
    return 0 ;
}
