#include<stdio.h>
#include<math.h>

int main ()

{
       double x1 , x2 , x3 , y1 , y2 , y3 ;
       scanf("%lf%lf%lf%lf%lf%lf",&x1,&x2,&x3,&y1,&y2,&y3) ;
       double a=1/(y1-y2) , b=1/(x1-x2) , c=(((x1+x2)/(y2-y1))+((y1+y2)/(x2-x1))) , d=1/(y2-y3) , e=1/(x2-x3) , f=(((x2+x3)/(y3-y2))+((y2+y3)/(x3-x2))) ;
       double x=(b*f-c*e)/(a*e-b*d) , y=(c*d-a*f)/(a*e-b*d) ;
       double R=sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1)) ;
       printf("(x   %0.3ld)^2 + (y   %0.3lf)^2 = %0.3lf^2",x,y,R) ;
       return 0 ;
}
