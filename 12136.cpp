#include<stdio.h>

int main()
{
    long a , b , c , d , e , f , g , h , i , j ;
    char ch ;
    scanf("%ld",&j) ;
    for(i=1 ; i<=j ; i++)
    {
        scanf("%ld%c%ld%ld%c%ld",&a,&ch,&b,&c,&ch,&d) ;
        scanf("%ld%c%ld%ld%c%ld",&e,&ch,&f,&g,&ch,&h) ;
        if(((60*a+b)>(60*g+h)) || (60*c+d)<(60*e+f))
        printf("Case %ld: Hits Meeting\n",i) ;
        else printf("Case %ld: Mrs Meeting\n",i) ;
    }
    return 0 ;
}
