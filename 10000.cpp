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
        return p.w>w ;
    }
} ;

long max_cost[1000] , front , node ;
priority_queue<EDGE>Q ;
vector<long>V[1000] ;

void dijkstra()
{
    long A , i , j ;
    max_cost[front]=0 ;
    Q.push(EDGE(front,max_cost[front])) ;
    while(!Q.empty())
    {
        EDGE ed=Q.top() ;
        Q.pop() ;
        A=ed.a ;
        for(i=0 ; i<V[A].size() ; i++)
        {
            j=V[A][i] ;
            if(max_cost[j]<max_cost[A]+1)
            {
                max_cost[j]=max_cost[A]+1 ;
                Q.push(EDGE(j,max_cost[j])) ;
            }
        }
    }
}

int main()
{
    long i , j=1 , a , b , c ;
    while(cin>>node && node!=0)
    {
        //cout<<"node = "<<node<<" front = "<<front<<endl ;
        //if(node==0) break ;
        cin>>front ;
        for(i=1 ; i<=150 ; i++)
            max_cost[i]=0 ;
        while(1)
        {
            cin>>a>>b ;
            V[a].push_back(b) ;
            if(a==0 && b==0) break ;
        }
        dijkstra() ;
        a=0 ;
        for(i=1 ; i<=150 ; i++)
        if(a<max_cost[i])
        {
            a=max_cost[i] ;
            b=i ;
        }
        cout<<"Case "<<j<<": The longest path from "<<front<<" has length "<<a<<", finishing at "<<b<<".\n\n" ;
        for(i=1 ; i<=150 ; i++)
            V[i].clear() ;
        //memset(mini_cost,0,sizeof(mini_cost)) ;
        j++ ;
    }
    return 0 ;
}
