#include<iostream>
#include<queue>
#include<vector>
#include<string.h>

using namespace std ;

struct EDGE
{
    long a , w ;
    EDGE(long u , long v)
    {
        a=u ;
        w=v ;
    }
    bool operator < (const EDGE& p) const
    {
        return p.w<w ;
    }
} ;

long destination , mini_cost[1000] ;
priority_queue<EDGE>Q ;
vector<long>V[1000] , cost[1000] ;

void dijkstra()
{
    long A , i , j ;
    mini_cost[1]=0 ;
    Q.push(EDGE( 1 , mini_cost[1] )) ;
    while(!Q.empty())
    {
        EDGE ed=Q.top() ;
        Q.pop() ;
        A=ed.a ;
        for(i=0 ; i<V[A].size() ; i++)
        {
            j=V[A][i] ;
            if(mini_cost[j]>mini_cost[A]+cost[A][i])
            {
                mini_cost[j]=mini_cost[A]+cost[A][i] ;
                Q.push(EDGE(j,mini_cost[j])) ;
            }
        }
    }
}

int main()
{
    long node , edge , i , a , b , c , loop , test ;
    cin>>test ;
    for(loop=1 ; loop<=test ; loop++)
    {
        cin>>node>>edge ;
        for(i=1 ; i<=node ; i++)
            mini_cost[i]=99999999 ;
        for(i=1 ; i<=edge ; i++)
        {
            cin>>a>>b>>c ;
            V[a].push_back(b) ;
            cost[a].push_back(c) ;
            V[b].push_back(a) ;
            cost[b].push_back(c) ;
        }
        dijkstra() ;
        c=0 ;
        b=0 ;
        cout<<"Case "<<loop<<": " ;
        if(mini_cost[node]!=99999999)
        cout<<mini_cost[node]<<endl ;
        else cout<<"Impossible\n" ;
        for(i=1 ; i<=node ; i++)
        {
            cost[i].clear() ;
            V[i].clear() ;
        }
        memset(mini_cost,0,sizeof(mini_cost)) ;
    }
    return 0 ;
}

