#include<stdio.h>
#include<math.h>

int main ()

{
    long n , i=1 ;
    double u , v , a , s , t , j ;
    while(scanf("%ld",&n)!=EOF)
    {
        if(n==0) break ;
        switch(n)
        {
            case 1:
            {
                scanf("%lf%lf%lf",&u,&v,&t) ;
                a=(v-u)/t ;
                s=(v*v-u*u)/(2*a) ;
                printf("Case %ld: %0.3lf %0.3lf\n",i,s,a) ;
                break ;
            }
            case 2:
            {
                scanf("%lf%lf%lf",&u,&v,&a) ;
                s=(v*v-u*u)/(2*a) ;
                t=(v-u)/a ;
                printf("Case %ld: %0.3lf %0.3lf\n",i,s,t) ;
                break ;
            }
            case 3:
            {
                scanf("%lf%lf%lf",&u,&a,&s) ;
                j=u*u+2*a*s ;
                v=sqrt(j) ;
                t=(v-u)/a ;
                printf("Case %ld: %0.3lf %0.3lf\n",i,v,t) ;
                break ;
            }
            default:
            {
                scanf("%lf%lf%lf",&v,&a,&s) ;
                j=v*v-2*a*s ;
                u=sqrt(j) ;
                t=(v-u)/a ;
                printf("Case %ld: %0.3lf %0.3lf\n",i,u,t) ;
                break ;
            }
        }
        i++ ;
    }
    return 0 ;
}
