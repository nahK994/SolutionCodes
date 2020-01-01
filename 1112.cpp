#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std ;

long long S , dest , mini_cost[1000] ;
vector<long long>cost[1000] , g[1000] ;
struct data
{
    long long a , b ;
    data(long long c , long long d)
    {
        a=c ;
        b=d ;
    }
    bool operator < (const data& p) const
    {
        return p.b<b ;
    }
} ;
priority_queue<data>Q ;

void DIJKSTRA()
{
    long long A , i , j ;
    mini_cost[S]=0 ;
    Q.push(data(S,mini_cost[S])) ;
    while(!Q.empty())
    {
        data a1=Q.top() ;
        Q.pop() ;
        A=a1.a ;
        if(A==dest) break ;
        for(i=0 ; i<g[A].size() ; i++)
        {
            j=g[A][i] ;
            if(mini_cost[j]>mini_cost[A]+cost[A][i])
            {
                mini_cost[j]=mini_cost[A]+cost[A][i] ;
                Q.push(data(j,mini_cost[j])) ;
            }
        }
    }
    while(!Q.empty())
        Q.pop() ;
}

int main()
{
    long long a , b , N , m , c , test , T , i=1 ;
    cin>>test ;
    while(test--)
    {
        cin>>N>>dest>>T>>m ;
        while(m--)
        {
            cin>>a>>b>>c ;
            g[a].push_back(b) ;
            cost[a].push_back(c) ;
        }
        c=0 ;
        for(S=1 ; S<=N ; S++)
        {
            for(a=0 ; a<=N ; a++)
                mini_cost[a]=2147483647 ;
           // memset(mini_cost,63,sizeof(mini_cost)) ;
            DIJKSTRA() ;
            if(mini_cost[dest]<=T) c++ ;
            cout<<"S "<<S<<" "<<mini_cost[dest]<<endl ;
        }
        if(i>1) cout<<endl ;
        cout<<c<<endl ;
        memset(mini_cost,0,sizeof(mini_cost)) ;
        for(b=0 ; b<N ; b++)
        {
            cost[b].clear() ;
            g[b].clear() ;
        }
        i=2 ;
    }
    return 0 ;
}
