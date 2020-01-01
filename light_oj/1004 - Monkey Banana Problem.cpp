#include<stdio.h>
#include<string.h>

long max[200][200] , ara[200][200] , n ;

int main()
{
    long loop , test , a , b , c , i , j ;
    scanf("%ld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        scanf("%ld",&n) ;
        b=1 ;

        for(i=1 ; i<=n ; i++)
            for(j=1 ; j<=i ; j++)
                scanf("%ld",&ara[i][j]) ;

        for( ; i<=2*n-1 ; i++,b++)
            for(j=1 ; j<=n-b ; j++)
                scanf("%ld",&ara[i][j]) ;

        for(i=1 ; i<=2*n-1 ; i++)
            memset(max[i],0,sizeof(max[i])) ;

        max[1][1] = ara[1][1] ;
        for(i=2 ; i<=n ; i++)
        {
            for(j=1 ; j<=i ; j++)
            {
                if(j-1<1) a = 0 ;
                else a = max[i-1][j-1] ;

                if(j>i-1) b = 0 ;
                else b = max[i-1][j] ;

                if(a>b) max[i][j] = a + ara[i][j] ;
                else max[i][j] = b + ara[i][j] ;
            }
        }

        c = 2 ;
        max[2*n-1][1] += ara[2*n-1][1] ;
        for(i=2*n-2 ; i>=n ; i--,c++)
        {
            for(j=1 ; j<=c ; j++)
            {
                if(j-1<1) a = 0 ;
                else a = max[i+1][j-1] ;

                if(i+1+j>2*n) b = 0 ;
                else b = max[i+1][j] ;

                if(a>b) max[i][j] += a + ara[i][j] ;
                else max[i][j] += b + ara[i][j] ;
            }
        }
        c=0 ;
        for(i=1 ; i<=n ; i++)
            if(c<max[n][i]-ara[n][i])
                c = max[n][i]-ara[n][i] ;
        printf("Case %ld: %ld\n",loop,c) ;
    }
    return 0 ;
}
