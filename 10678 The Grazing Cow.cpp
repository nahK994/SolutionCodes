#include<stdio.h>
#include<math.h>
#define pi 2*acos(0.0)

int main ()

{
    int i , j ;
    scanf("%d",&j) ;
    for(i=1 ; i<=j ; i++)
    {
        double a , b ;
        scanf("%lf%lf",&a,&b) ;
        double c=b/2-a/2 ;
        c=c+a/2 ;
        double d=sqrt((b/2)*(b/2)-(a/2)*(a/2)) ;
        double e=pi*c*d ;
        printf("%0.3lf\n",e) ;
    }
    return 0 ;
}
