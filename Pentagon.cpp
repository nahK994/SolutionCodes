#include<stdio.h>
#include<math.h>

#define pi 2*acos(0.0)
int main ()

{
    double a , b ;
    while(scanf("%lf",&a)!=EOF)
             {
                   b=a*sin(108*pi/180)/sin(63*pi/180) ;
                   printf("%0.10lf\n",b) ;
            }
      return 0 ;
}
