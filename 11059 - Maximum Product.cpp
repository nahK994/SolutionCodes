#include<stdio.h>
#include<string.h>

long long ara[20] , Max , n ;

int main()
{
    long long a , c , b , Max , loop=1 ;
    while(scanf("%lld",&n) != EOF)
    {
        Max=c=0 ;
        for(a=0 ; a<n ; a++)
            scanf("%lld",&ara[a]) ;

        for(a=0 ; a<n ; a++)
        {
            c=1 ;
            for(b=a ; b<n ; b++)
            {
                c*=ara[b] ;
                if(Max < c)
                    Max=c ;
            }
        }
        printf("Case #%lld: The maximum product is %lld.\n\n",loop++,Max) ;
    }
}
