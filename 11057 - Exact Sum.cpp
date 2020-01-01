#include<stdio.h>
#include<stdlib.h>
#include<string.h>

long long ara[10005] , Min , sum , n , a , b , i , j ;

int main()
{
    while(scanf("%lld",&n) != EOF)
    {
        for(i=0 ; i<n ; i++)
            scanf("%lld",&ara[i]) ;
        scanf("%lld",&sum) ;
        Min=99999999 ;
        for(i=0 ; i<n ; i++)
            for(j=i+1 ; j<n ; j++)
                if(ara[i]+ara[j] == sum && Min > abs( ara[i]-ara[j] ))
                {
                    a=ara[i] ; b=ara[j] ; Min=abs( ara[i]-ara[j] ) ;
                }
        if(a>b)
            printf("Peter should buy books whose prices are %lld and %lld.\n\n",b,a) ;
        else printf("Peter should buy books whose prices are %lld and %lld.\n\n",a,b) ;
    }
}
