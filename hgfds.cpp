#include<stdio.h>

int main ()

{
    long i , j , a , b , c ;
    scanf("%ld",&a) ;
    b=a-1 ;
    for(i=1 ; i<=a+1 ; i++)
    {
        for(c=1 ; c<=b+1 ; c++)
        printf(" ") ;
        for(j=1 ; j<=2*i-1 ; j++)
        {
            if(i>j) printf("%ld",i-j) ;
            else printf("%ld",j-i) ;
        }
        printf("\n") ;
        b-- ;
    }
    return 0 ;
}
