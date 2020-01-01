#include<stdio.h>
#include<string.h>
int ara[5000][7000] , n ;
struct info
{
    long weight , load ;
} data[1500] ;

long rec(long a , long L)
{
    if(a == n+1) return 0 ;
    if(ara[a][L] != -1) return ara[a][L] ;
    long b = 0 , c = 0 , w ;

    b = rec(a+1,L) ;

    w = (L-data[a].weight < data[a].load) ? L-data[a].weight : data[a].load ;
    if(w>0)
    c = 1+rec(a+1,w) ;

    ara[a][L] = (b>c)? b : c ;
    return ara[a][L] ;
}

int main()
{
     long a ;
     while(scanf("%ld",&n) != EOF)
     {
         if(n == 0) break ;
           for(a=1 ; a<=n ; a++)
            scanf("%ld%ld",&data[a].weight,&data[a].load) ;
            memset(ara,-1, sizeof ara) ;

           a = rec(0,7000) ;
           printf("%ld\n",a) ;
     }
     return 0 ;
}
