#include<stdio.h>

int main ()

{
    int i , j ;
    scanf("%d",&j) ;
    for(i=1 ; i<=j ; i++)
    {
        long a , b , d , t , ara[100000]={0} ;
        scanf("%ld",&a) ;
        for(b=0 ; b<a ; b++)
        scanf("%ld",&ara[b]) ;
        t=ara[0] ;
        for(d=0 ; d<a ; d++)
        if(t<ara[d])
           t=ara[d] ;
        printf("Case %d: %ld\n",i,t) ;
    }
    return 0 ;
}
