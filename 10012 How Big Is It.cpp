#include<stdio.h>
#include<math.h>
#define pi 2*acos(0.0)
#define exp 1e-10

double p(double a , double b)

{
    double s ;
    if(a>b) s=(a-b)/(a+b) ;
    else s=(b-a)/(a+b) ;
    s=asin(s) ;
    s=(a+b)*cos(s) ;
    return s ;
}

int main ()

{
    long i , j , r , n , b ;
    double a[100] , c ;
    scanf("%ld",&j) ;
    for(i=1 ; i<=j ; i++)
    {
        double count=0 ;
        scanf("%ld",&n) ;
        for(r=0 ; r<n ; r++)
        scanf("%lf",&a[r]) ;
        for(b=0 ; b<n-1 ; b++)
        {
            c=p(a[b],a[b+1]) ;
            count=count+c+exp ;
        }
        count=count+a[0]+a[n-1]+exp ;
       // if(count==0.000) continue ;
        printf("%0.3lf\n",count) ;
    }
    return 0 ;
}
