#include<stdio.h>
#include<math.h>
#define pi 2*acos(0.0)

int main ()

{
    double r , a , t , x , y , b , c ;
    while(scanf("%lf",&r)!=EOF)
    {
        t=30.0*pi/180.0 ;
        x=r*sin(t)/sin(75.0*pi/180.0) ;
        a=x*x+2*r*r*(t-sin(t)) ;
        y=2*r*r*((pi/2.0)-sin(pi/2.0)) ;
        b=y-2*a ;
        c=r*r-a-b ;
        printf("%0.3lf %0.3lf %0.3lf\n",a,b,c) ;
    }
    return 0 ;
}
