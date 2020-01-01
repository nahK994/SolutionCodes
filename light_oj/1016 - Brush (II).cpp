#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std ;

#define long long long

int main()
{
    long loop , test , a , b , Count , n , d , ara[50005] ;
    scanf("%lld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        scanf("%lld%lld",&n,&d) ;
        for(a=0 ; a<n ; a++)
            scanf("%ld%ld",&b,&ara[a]) ;
        sort(ara,ara+n) ;
        Count=1 , b=ara[0]+d ;
         for(a=1 ; a<n ; a++)
            if(ara[a] > b)
            {
                Count++ ;
                b=ara[a]+d ;
            }
            printf("Case %lld: %lld\n",loop,Count) ;
           // memset(ara,0,sizeof ara) ;
    }
}
