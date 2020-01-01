#include<stdio.h>
#include<math.h>
#define pi 2*acos(0.0)

int main ()

{
     double n , a ;

     int i=0 ;

     while(scanf("%lf%lf",&n,&a)!=EOF)

               {
                     if(n<3)

                     {
                         break ;
                     }

                     double r1=(2/n)*a/sin(2*pi/n) ;

                     r1=sqrt(r1) ;

                     i++ ;

                     printf("Case %d: %0.5lf %0.5lf\n", i, pi*r1*r1-a, (n/2)*r1*r1*sin(2*pi/n)-pi*r1*r1*cos(pi/n)*cos(pi/n) ) ;
               }


     return 0 ;
}

