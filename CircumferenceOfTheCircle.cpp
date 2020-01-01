#include<stdio.h>
#include<math.h>

const double pi=3.141592653589793 ;

int main ()

{
       double x1 , y1 , x2 , y2 , x3 , y3 ;
       while(scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3)!=EOF)
            {
                 double a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)) ;
                 double b=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2)) ;
                 double c=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3)) ;
                 double s=0.5*(a+b+c) ;
                 double area=sqrt(s*(s-a)*(s-b)*(s-c)) ;
                 double R=(a*b*c)/(4*area) ;
                 printf("%0.2lf\n",2*pi*R) ;
            }
        return 0 ;
}
