#include<stdio.h>
#include<math.h>

int main()
{
    long loop , test ;
    double ab , bc , ac , r , a ;
    scanf("%ld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        scanf("%lf%lf%lf%lf",&ab,&ac,&bc,&r) ;
        a = (double) sqrt(r/(r+1)) ;
        ab=ab*a ;
        printf("Case %ld: %0.9lf\n",loop,ab) ;
    }
}
