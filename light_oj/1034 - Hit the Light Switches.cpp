#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std ;

vector<long>v[200100] , v2[200100] ;
long color[200100] , flag , count , indegree[200100] ;

void dfs(long a)
{
    long i ;
    color[a]=1 ;
    for(i=0 ; i<v[a].size() ; i++)
        if(color[v[a][i]]==0)
            dfs(v[a][i]) ;
}

void pre_dfs(long a)
{
    long i ;
    color[a]=2 ;
    for(i=0 ; i<v2[a].size() ; i++)
        if(color[v2[a][i]]==0)
            pre_dfs(v2[a][i]) ;
     for(i=0 ; i<v[a].size() ; i++)
        if(color[v[a][i]]==0)
            dfs(v[a][i]) ;
}

int main()
{
    long loop , test , a , b , c , m , n , min ;
    scanf("%ld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        memset(color,0,sizeof(color)) ;
        memset(indegree,0,sizeof(indegree)) ;

        scanf("%ld%ld",&n,&m) ;

        for(a=1 ; a<=m ; a++)
        {
            scanf("%ld%ld",&b,&c) ;
            v[b].push_back(c) ;
            v2[c].push_back(b) ;
            indegree[c]++ ;
        }

        count=0 ;

        for(a=1 ; a<=n ; a++)
            if(color[a]==0 && indegree[a]==0)
            {
                count++ ;
                dfs(a) ;
            }
         for(a=1 ; a<=n ; a++)
            if(color[a]==0)
            {
                count++ ;
                pre_dfs(a) ;
            }

        printf("Case %ld: %ld\n",loop,count) ;
        for(a=1 ; a<=n ; a++)
        {
            v[a].clear() ;
            v2[a].clear() ;
        }
    }
    return 0 ;
}
