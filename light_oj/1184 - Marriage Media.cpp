#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
using namespace std ;

struct A
{
    long height , age , p ;
} Men[80] , Women[80] ;

vector<long>V[80] ;

long vis[80] , par[80] , m , n ;

long dfs(long u)
{
    if(vis[u] == 1) return 0 ;

    vis[u] = 1 ;

    for(int i=0 ; i<V[u].size() ; i++)
    {
        int a = V[u][i] ;
        if(par[a] == -1 || dfs(par[a]))
        {
            par[a] = u ;
            return 1 ;
        }
    }

    return 0 ;
}

int main()
{
    long loop , test , a , b , c , ans ;
    scanf("%ld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        scanf("%ld%ld",&m,&n) ;
        for(a=1 ; a<=m ; a++)
            scanf("%ld%ld%ld",&Men[a].height,&Men[a].age,&Men[a].p) ;
        for(a=1 ; a<=n ; a++)
            scanf("%ld%ld%ld",&Women[a].height,&Women[a].age,&Women[a].p) ;

        for(a=1 ; a<=m ; a++)
            V[a].clear() ;

        for(a=1 ; a<=m ; a++)
            for(b=1 ; b<=n ; b++)
                if(abs(Men[a].height-Women[b].height)<=12 && abs(Men[a].age-Women[b].age)<=5 && Men[a].p == Women[b].p)
                    V[a].push_back(b) ;

        ans=0 ;
        memset(par,-1, sizeof par) ;
        for(a=1 ; a<=m ; a++)
        {
            memset(vis,0,sizeof vis) ;
            ans+=dfs(a) ;
        }
        printf("Case %ld: %ld\n",loop,ans) ;
    }
    return 0 ;
}
