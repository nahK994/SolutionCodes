#include<stdio.h>

int main()
{
    long h , m , i , j ;
    char c ;
    scanf("%ld",&j) ;
    for(i=1 ; i<=j ; i++)
    {
        scanf("%ld%c%ld",&h,&c,&m) ;
        h=(24*3600-h*3600-m*60)/3600 ;
        m=(24*3600-h*3600-m*60)%3600 ;
        m=m/60 ;
        if(h>12) h=h-12 ;
        if(m>59) m=m-12-60 ;
        if(h<10) printf("0%ld",h) ;
        else printf("%ld",h) ;
        printf("%c",c) ;
        if(m<10) printf("0%ld",m) ;
        else printf("%ld",m) ;
        printf("\n") ;
    }
    return 0 ;
}
