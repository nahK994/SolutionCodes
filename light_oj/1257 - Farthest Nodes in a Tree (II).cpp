#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll>V[30050] , cost[30050] ;
queue<ll>Q ;
ll distances[30050] , distances1[30050] , distances2[30050] ;

ll bfs(ll a , ll max)
{
    memset(distances,-1,sizeof(distances)) ;
    distances[a]=0 ;

    ll i , j , s , aa ;
    Q.push(a) ;
    while(!Q.empty())
    {
        s=Q.front() ;

        for(i=0 ; i<V[s].size() ; i++)
        {
              aa=V[s][i] ;
            if(distances[aa]!=-1) continue ;

            distances[aa]=cost[s][i]+distances[s] ;
            Q.push(aa) ;

            if(distances[aa]>max)
            {
                max=distances[aa] ;
                j=aa ;
            }
        }
        Q.pop() ;
    }
    return j ;
}

ll bfs1(ll a , ll max)
{
    memset(distances1,-1,sizeof(distances1)) ;
    distances1[a]=0 ;

    ll i , j , s , aa ;
    Q.push(a) ;
    while(!Q.empty())
    {
        s=Q.front() ;

        for(i=0 ; i<V[s].size() ; i++)
        {
              aa=V[s][i] ;
            if(distances1[aa]!=-1) continue ;

            distances1[aa]=cost[s][i]+distances1[s] ;
            Q.push(aa) ;

            if(distances1[aa]>max)
            {
                max=distances1[aa] ;
                j=aa ;
            }
        }
        Q.pop() ;
    }
    return j ;
}

void bfs2(ll a , ll max)
{
    memset(distances2,-1,sizeof(distances2)) ;
    distances2[a]=0 ;

    ll i , j , s , aa ;
    Q.push(a) ;
    while(!Q.empty())
    {
        s=Q.front() ;

        for(i=0 ; i<V[s].size() ; i++)
        {
              aa=V[s][i] ;
            if(distances2[aa]!=-1) continue ;

            distances2[aa]=cost[s][i]+distances2[s] ;
            Q.push(aa) ;

        }
        Q.pop() ;
    }

}

int main()
{
    ll loop , test , a , b , c , i , j , node , edge ;
    scanf("%lld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        scanf("%lld",&node) ;
        for(i=1 ; i<node ; i++)
        {
            scanf("%lld%lld%lld",&a,&b,&c) ;
            V[a].push_back(b) ;
            cost[a].push_back(c) ;
            V[b].push_back(a) ;
            cost[b].push_back(c) ;
        }
        a=bfs(0,0) ;
        b=bfs1(a,0) ;
        bfs2(b,0) ;
        printf("Case %lld:\n",loop) ;
        for(i=0 ; i<node ; i++)
        {
            if(distances1[i]>distances2[i])
                  printf("%lld\n",distances1[i]) ;
            else printf("%lld\n",distances2[i]) ;
            V[i].clear() ;
            cost[i].clear() ;
        }
    }
    return 0 ;
}
