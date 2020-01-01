#include<stdio.h>
#include<math.h>
#define pi 2*acos(0.0)

int main ()

{
    double a , b ;
    while(scanf("%lf%lf",&a,&b)!=EOF)
    {
        if(a==0 && b==0) break ;
        a=a/2.0 ;
        a=pi*a*a*a*2 ;
        a=a-b ;
        printf("%0.3lf",a) ;
       /* a=a/pi ;
        a=pow(a,1.0/3.0) ;
        printf("%0.3lf\n",a*2) ;*/
    }
    return 0 ;
}
