#include<stdio.h>
#include<math.h>
#define eps 1e-9

int main ()

{
    double a , b , c , s ;
    while(scanf("%lf%lf%lf",&a,&b,&c)!=EOF)
    {
        if(2.0*b*b+2.0*c*c-a*a<0 || 2.0*a*a+2.0*c*c-b*b<0 || 2.0*b*b-c*c+2.0*a*a<0)
        printf("-1\n") ;
        else
        {
           a=2.0*sqrt(2.0*b*b+2.0*c*c-a*a)/3.0+eps ;
           b=2.0*sqrt(2.0*a*a+2.0*c*c-b*b)/3.0+eps ;
           c=2.0*sqrt(2.0*b*b+2.0*a*a-c*c)/3.0+eps ;
           s=(a+b+c)/2.0+eps ;
           s=sqrt(s*(s-a)*(s-b)*(s-c))+eps ;
           printf("%0.3lf\n",s) ;
        }
    }
    return 0 ;
}
