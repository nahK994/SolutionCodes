#include<stdio.h>
#include<math.h>
#define pi 2*acos(0.0)

int main ()

{
    double l , w , h , t , V ;
    while(scanf("%lf%lf%lf%lf",&l,&w,&h,&t)!=EOF)
    {
        if(h>=l*tan(t*pi/180.0)) V=w*l*h-0.5*w*l*l*tan(t*pi/180.0) ;
        else V=0.5*h*h*w/tan(t*pi/180.0) ;
        printf("%0.3lf mL\n",V) ;
    }
    return 0 ;
}
