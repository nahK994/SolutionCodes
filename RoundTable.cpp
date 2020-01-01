#include<stdio.h>
#include<math.h>

int main ()

{
      double a , b , c , s , area , r ;
      while(scanf("%lf%lf%lf",&a,&b,&c)!=EOF)
           {
                 if( a==0 || b==0 || c==0 )
                 printf("The radius of the round table is: 0.000\n") ;
                 else
                 {
                     s=0.5*(a+b+c) ;
                     area=sqrt(s*(s-a)*(s-b)*(s-c)) ;
                     r=area/s ;
                     printf("The radius of the round table is: %0.3lf\n",r) ;
                 }
           }
      return 0 ;
}
