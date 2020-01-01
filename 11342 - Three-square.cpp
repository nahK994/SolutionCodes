#include<stdio.h>
#include<string.h>
#define ll long

struct data
{
    ll a1 , b1 , c1 ;
} ara[50005] ;
bool color[50005] ;

int main()
{
    ll test , a , b , c , n , i , j ;
    memset(color,false,sizeof color) ;
    i=0 ;
    for(a=0 ; a<=130 ; a++)
        for(b=a ; b<=158 ; b++)
            for(c=b ; a*a+b*b+c*c <= 50000 ; c++)
            {
                i++ ;
                if(!color[a*a+b*b+c*c])
                {
                    ara[ a*a+b*b+c*c ].a1=a ;
                    ara[ a*a+b*b+c*c ].b1=b ;
                    ara[ a*a+b*b+c*c ].c1=c ;
                    color[ a*a+b*b+c*c ]=true ;
                }
            }
    //printf("%ld\n",i) ;
    scanf("%ld",&test) ;
    while(test--)
    {
        scanf("%ld",&n) ;
        if(!color[n])
            printf("-1\n") ;
        else printf("%ld %ld %ld\n",ara[n].a1,ara[n].b1,ara[n].c1) ;
    }
}
