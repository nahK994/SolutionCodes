#include<stdio.h>

int main ()

{
    int i , j ;
    scanf("%d",&j) ;
    for(i=1 ; i<=j ; i++)
    {
        int a , b , c , d , e , n ;
        long ara[20]={0} ;
        scanf("%d",&n) ;
        for(a=1 ; a<=n ; a++)
        {
            b=a ;
            while(b!=0)
            {
                e=b%10 ;
                ara[e]++ ;
                b=b/10 ;
            }
        }
        for(d=0 ; d<=8 ; d++)
        printf("%ld ",ara[d]) ;
        printf("%ld\n",ara[9]) ;
    }
    return 0 ;
}
