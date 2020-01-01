#include<stdio.h>
#include<math.h>

#define pi 2*acos(0.0)

int main()
{
    long loop , test ;
    double r1 , r2 , h , p , V , R , a , b , c ;
    scanf("%ld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        scanf("%lf%lf%lf%lf",&r1,&r2,&h,&p) ;
        a=(h/3.0) ;
        b=(r2*p/3.0)+(r1*(h-p)/3.0) ;
        c=(p*r2*r2/3.0)+(r1*r1*(h-p)/3.0)-(h/3.0)*(r1*r1+r1*r2+r2*r2) ;
        R=(-b+sqrt(b*b-4*a*c)>=0)?-b+sqrt(b*b-4*a*c):-b-sqrt(b*b-4*a*c) ;
        R=R/(2*a) ;
        V=pi*(R*R+r2*R+r2*r2)*p/3.0 ;
        printf("Case %ld: %.10lf\n",loop,V) ;
    }
    return 0 ;
}
