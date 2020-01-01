#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
using namespace std ;

struct NODE
{
    long a , dis ;
    NODE(long a1 , long b1)
    {
        a=a1 ;
        dis=b1 ;
    }
    NODE() {}
    bool operator < (const NODE & p) const
    {
        return p.dis<dis ;
    }
};
vector<long>V[5005] , cost[5005] ;
priority_queue<struct NODE>Q ;
long node , edge , dist1[5005] , dist2[5005] ;

void dijkstra()
{
    long i , j , a , d ;
    for(i=0 ; i<=node ; i++)
        dist1[i]=dist2[i]=999999999999 ;
        dist1[0]=0 ;
    Q.push(NODE(1,0)) ;
    while(!Q.empty())
    {
        a=Q.top().a ;
        d=Q.top().dis ;
        Q.pop() ;
        for(i=0 ; i<V[a].size() ; i++)
            if(dist1[ V[a][i] ] > d + cost[a][i])
            {
                dist2[ V[a][i] ] = dist1[ V[a][i] ] ;
                dist1[ V[a][i] ] = d + cost[a][i] ;
                Q.push(NODE(V[a][i],dist1[ V[a][i] ])) ;
            }
            else if(dist2[V[a][i]] > d + cost[a][i] && dist1[V[a][i]] < d + cost[a][i])
            {
                dist2[ V[a][i] ] = d + cost[a][i] ;
                Q.push(NODE(V[a][i],dist2[ V[a][i] ])) ;
            }
    }
}

int main()
{
    long loop , test , a , b , c , d , e ;
    scanf("%ld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        scanf("%ld%ld",&node,&edge) ;
        while(edge--)
        {
            scanf("%ld%ld%ld",&a,&b,&c) ;
            V[a].push_back(b) ;
            cost[a].push_back(c) ;
            V[b].push_back(a) ;
            cost[b].push_back(c) ;
        }
        dijkstra() ;
        printf("Case %ld: %ld\n",loop,dist2[node]) ;
        for(a=0 ; a<=node ; a++)
        {
            V[a].clear() ; cost[a].clear() ;
        }
    }
}
