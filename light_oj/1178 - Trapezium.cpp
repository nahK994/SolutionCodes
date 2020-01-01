#include<stdio.h>
#include<math.h>

int main()
{
    int loop , test ;
    double a , b , c , d , i ;
    scanf("%d",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
         scanf("%lf%lf%lf%lf",&a,&b,&c,&d) ;
         i = ((a - c)*(a - c) + d*d - b*b)/(2*d*(a-c)) ;
         i = acos(i) ;
         i = d * sin(i) ;
         printf("Case %d: %0.10lf\n",loop , 0.5 * i * (a+c)) ;
    }
    return 0 ;
}
