#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
using namespace std ;

vector<long>V[2000] ;
queue<long>Q ;
long ara[2000] , cities[2000] , color[2000] , color_ans[2000] , ans , k , n , m ;

void bfs(long a)
{
    long b , c , i , j ;
    Q.push(a) ;
    color[a]=1 ;
    ara[a]++ ;
    while(!Q.empty())
    {
        a=Q.front() ;
        Q.pop() ;
        for(i=0 ; i<V[a].size() ; i++)
        {
            if(!color[V[a][i]])
            {
                color[V[a][i]]=1 ;
                ara[V[a][i]]++ ;
                Q.push(V[a][i]) ;
            }
        }
    }
}

int main()
{
    long loop , test , a , b , c , i , j ;
    scanf("%ld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {

        scanf("%ld%ld%ld",&k,&n,&m) ;

        ans=0 ;
        memset(ara,0,sizeof(ara)) ;
        memset(cities,0,sizeof(cities)) ;
        memset(color_ans,0,sizeof(color_ans)) ;
        for(i=1 ; i<=n ; i++)
            V[i].clear() ;
         b=1 ;
        for(i=1 ; i<=k ; i++)
        {
            scanf("%ld",&a) ;
            cities[b++]=a ;
        }

        for(i=1 ; i<=m ; i++)
        {
            scanf("%ld%ld",&a,&b) ;
            V[a].push_back(b) ;
        }

        for(i=1 ; i<=k ; i++)
            {
                memset(color,0,sizeof(color)) ;
                bfs(cities[i]) ;
            }

        for(i=1 ; i<=n ; i++)
        if(ara[i]==k)
            ans++ ;

        printf("Case %ld: %ld\n",loop,ans) ;
    }
    return 0 ;
}
