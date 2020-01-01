#include<stdio.h>

int main ()

{
    long i , j ;
    scanf("%ld",&j) ;
    printf("\n") ;
    for(i=1 ; i<=j ; i++)
    {
        printf("\n") ;
        double n , a , b , c , sum1 , p , sum2=0 ;
        scanf("%lf",&n) ;
        scanf("%lf%lf",&a,&b) ;
        for(p=0 ; p<n ; p++)
        {
            scanf("%lf",&c) ;
            sum2=sum2+c ;
        }
        sum1=(a+b)/2 ;
        printf("%0.2lf\n",sum1-sum2) ;
    }
    return 0 ;
}

