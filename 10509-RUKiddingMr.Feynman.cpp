#include<stdio.h>
#include<math.h>

int main ()

{
     double a , b ;
     while(scanf("%lf",&a)!=EOF)
     {
         if(a==0)
         {
             break ;
         }
         else
         {
             b=a ;
             b=sqrt(b) ;
             a=a*b ;
             a=1/a ;
             a=sqrt(a) ;
             printf("%0.4lf\n",a) ;
         }
     }
      return 0 ;
}
