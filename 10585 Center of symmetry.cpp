#include<stdio.h>

int main ()

{
    long i , j ;
    scanf("%ld",&j) ;
    for(i=1 ; i<=j ; i++)
    {
        double n , a , b , c , a1[100000] , a2[100000] , x , y ;
        for(a=0 ; a<n ; a++)
        scanf("%lf",&a1[a]) ;
        for(b=0 ; b<n-2 ; b=b+2)
        for(c=b+2,x=0 ; c<n ; c=c+2,x=x+2)
        {
            a2[x]=(a1[b]+a1[c])/2 ;
            a2[x+1]=(a1[b+1]+a1[c+1])/2 ;
        }
    }
}
