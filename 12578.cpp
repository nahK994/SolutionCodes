#include<stdio.h>
#include<math.h>
#define pi 2*acos(0.0)
#define exp 1e-6

int main ()

{
    double i , j , l , r , w ;
    scanf("%lf",&j) ;
    for(i=1 ; i<=j ; i++)
    {
        scanf("%lf",&l) ;
        r=(2.0/10.0)*l+exp ;
        w=(6.0/10.0)*l+exp ;
        w=l*w-pi*r*r+exp ;
        r=pi*r*r+exp ;
        printf("%0.2lf  %0.2lf\n",r,w) ;
    }
    return 0 ;
}
