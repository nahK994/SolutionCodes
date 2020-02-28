#include<stdio.h>
#include<string.h>
int main()
{
    long loop, test , a , i , j , n , coins[500] , k[20000] ;
    scanf("%ld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        memset(coins,0,sizeof(coins)) ;
        memset(k,0,sizeof(k)) ;

        scanf("%ld%ld",&j,&n) ;
        for(i=0 ; i<j ; i++)
            scanf("%ld",&coins[i]) ;

        for(i=0 ; i<j ; i++)
        {
            k[coins[i]]++ ;
            for(a=coins[i] ; a<=n ; a++)
                k[a]=(k[a]+k[a-coins[i]])%100000007 ;
        }
       /* for(a=1 ; a<=n ; a++)
            printf("%ld -> %ld\n",a,k[a]) ;*/
        printf("Case %ld: %ld\n",loop,k[n]) ;
    }
    return 0 ;
}
