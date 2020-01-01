#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll>V[30050] , cost[30050] ;
queue<ll>Q ;
ll distances[30050] , color[30050] ;

ll bfs1(ll a , ll max)
{
    memset(distances,0,sizeof(distances)) ;
    memset(color,0,sizeof(color)) ;
    ll i , j , s ;
    Q.push(a) ;
    while(!Q.empty())
    {
        s=Q.front() ;
        color[s]=-1 ;
        for(i=0 ; i<V[s].size() ; i++)
        {
            if(color[V[s][i]]==-1) continue ;
            distances[V[s][i]]=cost[s][i]+distances[s] ;
            Q.push(V[s][i]) ;
            if(distances[V[s][i]]>max)
            {
                max=distances[V[s][i]] ; j=V[s][i] ;
            }
        }
        Q.pop() ;
    }
    return j ;
}

ll bfs2(ll a , ll max)
{
    memset(distances,0,sizeof(distances)) ;
    memset(color,0,sizeof(color)) ;
    ll i , j , s ;
    Q.push(a) ;
    while(!Q.empty())
    {
        s=Q.front() ;
        color[s]=-1 ;
        for(i=0 ; i<V[s].size() ; i++)
        {
            if(color[V[s][i]]==-1) continue ;
            distances[V[s][i]]=cost[s][i]+distances[s] ;
            Q.push(V[s][i]) ;
            if(distances[V[s][i]]>max)
                max=distances[V[s][i]] ;
        }
        Q.pop() ;
    }
    return max ;
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
          a=bfs1(0,0) ;
        //  printf("%lld\n",a) ;
          b=bfs2(a,0) ;
          printf("Case %lld: %lld\n",loop,b) ;
          for(i=0 ; i<node ; i++)
          {
              V[i].clear() ; cost[i].clear() ;
          }
     }
     return 0 ;
}
