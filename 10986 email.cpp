#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std ;

long S , T , mini_cost[300000] ;
vector<long>cost[300000] , g[300000] ;
struct data
{
    long a , b ;
    data(long c , long d)
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
    long A , i , j , b=0 ;
    mini_cost[S]=0 ;
    Q.push(data(S,mini_cost[S])) ;
    while(!Q.empty())
    {
        data a1=Q.top() ;
        Q.pop() ;
        A=a1.a ;
         if(A==T) break ;
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
    long loop , j , a , b , N , n , m , c ;
    cin>>N ;
    for(loop=1 ; loop<=N ; loop++)
    {
        cin>>n>>m>>S>>T ;
        memset(mini_cost,0,sizeof(mini_cost)) ;
        for(j=0 ; j<n ; j++)
            mini_cost[j]=99999999 ;
        j=m ;
        while(j)
        {
            cin>>a>>b>>c ;
            g[a].push_back(b) ;
            g[b].push_back(a) ;
            cost[a].push_back(c) ;
            cost[b].push_back(c) ;
            j-- ;
        }
        cout<<"Case #"<<loop<<": " ;
        if(m==0)
        {
            cout<<"unreachable\n" ;
            continue ;
        }
        DIJKSTRA() ;
        if(mini_cost[T]!=99999999)
            cout<<mini_cost[T]<<endl ;
        else
            cout<<"unreachable\n" ;
        for(j=0 ; j<n ; j++)
        {
            cost[j].clear() ;
            g[j].clear() ;
        }
    }
    return 0 ;
}
