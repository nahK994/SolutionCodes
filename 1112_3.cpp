#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>
#include<queue>

/*#define mx  max
#define max 101*/
using namespace std;
vector<long> g[1000],cost[1000];
long dest , mini_cost[1000] , S ;


struct node
{
    long u,w;
    node(long a,long b)
    {
        u=a;
        w=b;
    }
    bool operator < ( const node& p ) const
    {
        return w > p.w;
    }
};

priority_queue<node>Q;
void dijkstra()
{

    long A , j , i ;
    mini_cost[S]=0;
    Q.push(node(S,mini_cost[S]));
    while(!Q.empty())
    {
        node a1=Q.top();
        Q.pop();
        A=a1.u;


        if(A==dest) break ;
        for(i=0; i<g[A].size(); i++)
        {
            j=g[A][i];

            if(mini_cost[j]>mini_cost[A]+cost[A][i])
            {

                mini_cost[j]=mini_cost[A]+cost[A][i];

                Q.push(node(j,mini_cost[j]));
            }
        }
    }
    while(!Q.empty())
        Q.pop() ;
}
int main()
{
    long N , m , test , T , i=1 , a , b , c , j ;
    cin>>test ;
    while(test--)
    {
        cin>>N>>dest>>T>>m ;

        while(m--)
        {
            cin>>a>>b>>c ;
            g[a].push_back(b);
            //g[v].push_back(u);
            cost[a].push_back(c);
            //cost[v].push_back(w);

        }

        c=0 ;
        for (S=1; S<=N ; S++)
        {
            for(a=0 ; a<=N ; a++)
                mini_cost[a]=2147483647 ;
            dijkstra();
            //cout<<"S "<<S<<" "<<mini_cost[dest]<<endl ;
            if(mini_cost[dest]<=T) c++ ;

        }

        if(i>1) cout<<endl ;
        cout<<c<<endl ;
        i=2 ;

        for (j=0; j<=N ; j++)
        {
            g[j].clear();
            cost[j].clear();
        }
        memset(mini_cost,0,sizeof(mini_cost)) ;

    }
    return 0;
}

