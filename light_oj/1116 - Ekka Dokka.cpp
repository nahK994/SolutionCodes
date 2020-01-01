#include<stdio.h>

int main()
{
    long loop , test , a , b , i , j , n ;
    scanf("%ld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        scanf("%ld",&n) ;
        if(n%2!=0) printf("Case %ld: Impossible\n",loop) ;
        else
        {
            for(i=2 ; ; i+=2)
            {
                j=n/i ;
                if(n%i==0 && j%2!=0) break ;
            }
            printf("Case %ld: %ld %ld\n",loop,j,i) ;
        }
    }
    return 0 ;
}
