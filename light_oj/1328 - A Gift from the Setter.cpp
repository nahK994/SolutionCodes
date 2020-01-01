#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std ;

int main()
{
    long loop, test , k , c , min , m , n , ara[100005] , sum[100005] ;
    scanf("%ld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        scanf("%ld%ld%ld%ld",&k,&c,&n,&ara[0]) ;
        for(m=1 ; m<n ; m++)
            ara[m] = (k * ara[m-1] + c) % 1000007 ;

         sort(ara , ara+n) ;   //  Don`t know Why this needed
        sum[n-1] = 0 ;
        for(m=n-2 ; m>=0 ; m--)
           sum[m]=sum[m+1]+ara[m+1] ;

        c=0 ;
        n-- ;
        for(m=0 ; m<n ; m++)
           c+=abs((n-m)*ara[m] - sum[m]) ;

        printf("Case %ld: %ld\n",loop,c) ;
    }
    return 0 ;
}
