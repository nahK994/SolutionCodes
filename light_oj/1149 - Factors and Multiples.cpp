#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std ;

vector<long>V[500] ;
long par[500] , ara1[500] , ara2[500] , visited[500] ;

long dfs(long n)
{
    if(visited[n] == 1) return 0 ;
    visited[n] = 1 ;

    for(long a = 0 ; a<V[n].size() ; a++)
    {
        long b = V[n][a] ;
        if(par[b] == -1 || dfs(par[b]))
        {
            par[b] = n ;
            return 1 ;
        }
    }
    return 0 ;
}

int main()
{
    long loop , test , a , b , c , m , n ;
    scanf("%ld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        scanf("%ld",&n) ;
        for(a=0 ; a<n ; a++)
            scanf("%ld",&ara1[a]) ;

        scanf("%ld",&m) ;
        for(a=0 ; a<m ; a++)
            scanf("%ld",&ara2[a]) ;

        for(a=0 ; a<n ; a++)
        {
            V[a].clear() ;
            if(ara1[a] != 0)
            for(b=0 ; b<m ; b++)
                if(ara2[b]%ara1[a] == 0)
                    V[a].push_back(b) ;
        }

        c=0 ;
        memset(par,-1,sizeof par) ;
        for(a=0 ; a<n ; a++)
        {
            memset(visited,0,sizeof visited) ;
            c+=dfs(a) ;
        }

        printf("Case %ld: %ld\n",loop,c) ;
    }
    return 0 ;
}
