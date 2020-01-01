#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
using namespace std ;

int main()
{
    long loop, test , a , b , c , min , m , n , ara[1005] ;
    scanf("%ld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        scanf("%ld",&n) ;
        for(a=0 ; a<n ; a++)
            scanf("%ld",&ara[a]) ;
        m=0 ;
        for(a=0 ; a<n-1 ; a++)
        {
            min = a ;
            for(b=a+1 ; b<n ; b++)
                if(ara[b]<ara[min])
                min=b ;
            if(min!=a)
            {
                m++ ;
                c=ara[a] ;
                ara[a]=ara[min] ;
                ara[min]=c ;
            }
        }
        printf("Case %ld: %ld\n",loop,m) ;
    }
}
