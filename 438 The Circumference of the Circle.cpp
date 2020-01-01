#include<stdio.h>
#include<math.h>

#define pi 3.141592653589793

int main ()

{
    double x1,x2,x3,y1,y2,y3,s,a,b,c,r;
    while(scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3)!=EOF)
    {
        a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)) ;
        b=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2)) ;
        c=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3)) ;
        s=(a+b+c)/2 ;
        s=sqrt(s*(s-a)*(s-b)*(s-c)) ;
        s=4*s ;
        r=(a*b*c)/s ;
        r=2*pi*r ;
        printf("%0.2lf\n",r) ;
    }
    return 0 ;
}
