#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std ;

int main()
{
    long scen , dis[100000] , i ;
    while(scanf("%ld",&scen)!=EOF)
    {
        if(scen==0) break ;
        for(i=0 ; i<scen ; i++)
            scanf("%ld",&dis[i]) ;
        sort(dis,dis+scen) ;
        for(i=0 ; i<scen-1 ; i++)
            if(dis[i+1]-dis[i]>200)
                break ;
        if(i==scen-1 && 1422-dis[scen-1]<=100) printf("POSSIBLE\n") ;
        else printf("IMPOSSIBLE\n") ;
        memset(dis,0,sizeof(dis)) ;
    }
    return 0 ;
}

