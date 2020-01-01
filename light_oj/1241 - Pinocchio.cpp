#include<stdio.h>
#include<math.h>
#include<string.h>

int main()
{
    long loop , test , n , i , j , a , ara[55] , counter ;
    float b ;
    scanf("%ld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        counter=0 ;
        scanf("%ld",&n) ;
        for(i=0 ; i<n ; i++)
        scanf("%ld",&ara[i]) ;
        b=(ara[0]-2)/5.0 ;
        counter+=ceil(b) ;
        for(i=0 ; i<n-1 ; i++)
        {
            b=(ara[i+1]-ara[i])/5.0 ;
            counter+=ceil(b) ;
        }
        printf("Case %ld: %ld\n",loop,counter) ;
        memset(ara,0,sizeof(ara)) ;
    }
    return 0 ;
}
