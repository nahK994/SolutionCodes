#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std ;

vector<long>V[1010] ;
long ara[1010][2] , par[1010] , n ;

long rec(long u , long isGuard)
{
    if(ara[u][isGuard] != -1) return ara[u][isGuard] ;
    long sum=0 ;
    for(long i=0; i<V[u].size() ; i++)
    {
        long v=V[u][i] ;
        if(v!=par[u])
        {
            par[v]=u ;
            if(isGuard==1) sum+=rec(v,0) ;
            else sum+=max(rec(v,1),rec(v,0)) ;
        }
    }
    return ara[u][isGuard]=sum+isGuard ;
}

long max(long a , long b)
{
    if(a>b) return a ;
    return b ;
}

int main()
{
    long loop , test , a , b , c , i , j , m ;
    scanf("%ld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        scanf("%ld%ld",&n,&m) ;
        memset(ara,-1,sizeof(ara)) ;
        memset(par,-1,sizeof(par)) ;
        while(m--)
        {
            scanf("%ld%ld",&a,&b) ;
            V[a].push_back(b) ;
            V[b].push_back(a) ;
        }
        b=0 ;
        for(a=1 ; a<=n ; a++)
            if(par[a] == -1)
        b += max(rec(a,0),rec(a,1)) ;
        printf("Case %ld: %ld\n",loop,b) ;
        for(a=1 ; a<=n ; a++)
            V[a].clear() ;

    }
    return 0 ;
}
