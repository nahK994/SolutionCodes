#include<stdio.h>
#include<math.h>
#include<algorithm>

using namespace std ;

double c(double a , double b)

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
    long i , j , n , r , k , l ;
    double a[10] , count , g=0 , h , q ;
    scanf("%ld",&j) ;
    for(i=1 ; i<=j ; i++)
    {
        count=0 ;
        scanf("%ld",&n) ;
        sort(a,a+n) ;
        for(r=0 ; r<n ; r++)
        scanf("%lf",&a[r]) ;
        for(k=0 ; k<n ; k++)
        {
            if(a[k]==0) continue ;
            for(l=k+1 ; l<n ; l++)
            {
                if(a[l]==0) continue ;
                h=c(a[k],a[l]) ;
                if(g==0 || h<g)
                {
                    g=h ;
                    count=count+g ;
                    a[l]=0 ;
                    q=l ;
                }
            }
        }
        count=count+a[0]+a[l] ;
        printf("%0.3lf\n",count) ;
    }
    return 0 ;
}
