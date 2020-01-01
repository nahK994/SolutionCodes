#include<stdio.h>
#include<math.h>
#define pi 2*acos(0.0)
int main()
{
    long loop , test ;
    double R,  r , a , n ;
    scanf("%ld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        scanf("%lf%lf",&R,&n) ;
        a=360.0/n ;
        a=a/2 ;
        a=90-a ;
        r=(cos(a*pi/180.0)*R)/(1+cos(a*pi/180.0)) ;
        printf("Case %ld: %0.9lf\n",loop,r) ;

        /*r=r*sqrt(2)-r ;
        printf("R = %lf\n",r) ;*/
    }
    return 0 ;
}
