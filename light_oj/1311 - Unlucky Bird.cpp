#include<stdio.h>

int main()
{
    long loop , test ;
    double a1 , a2 , v1 , v2 , v3 , t , d ;
    scanf("%ld",&test) ;
    for(loop=1; loop<=test ; loop++)
    {
        scanf("%lf%lf%lf%lf%lf",&v1,&v2,&v3,&a1,&a2) ;
        d=((v1*v1)/(2*a1))+((v2*v2)/(2*a2)) ;
        t=((v1/a1)>(v2/a2))?(v1/a1):(v2/a2) ;
        v3=t*v3 ;
        printf("Case %ld: %.10lf %.10lf\n",loop,d,v3) ;
    }
    return 0 ;
}
