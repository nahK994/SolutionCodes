#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
using namespace std ;

struct NODE
{
    long a , dis , mark ;
    NODE(long a1 , long b1 , long c1)
    {
        a=a1 ;
        dis=b1 ;
        mark=c1 ;
    }
    NODE() {}
    bool operator < (const NODE & p) const
    {
        return p.dis<dis ;
    }
};

struct EDGE
{
    long a , flag ;
    EDGE(long a1 , long b1)
    {
        a=a1 ;
        flag=b1 ;
    }
};

vector<struct EDGE>V[10005] ;
vector<long>cost[10005] ;
priority_queue<struct NODE>Q ;
long dist[10005][15] , node , limit ;

void dijkstra()
{
    long i , j , mark , d ;
    dist[0][0]=0 ;
    Q.push(NODE(0,0,0)) ;
    struct NODE q ;
    while(!Q.empty())
    {
        // printf("P\n") ;
        q=Q.top() ;
        Q.pop() ;
        i=q.a ;
        d=q.dis ;
        mark=q.mark ;
        for(j=0 ; j<V[i].size() ; j++)
        {
            //   printf("L\n") ;
            if(mark+V[i][j].flag > limit)
                continue ;
            if(dist[V[i][j].a][mark+V[i][j].flag] > cost[i][j] + d)
            {
                dist[V[i][j].a][mark+V[i][j].flag] = cost[i][j] + d ;
                Q.push(NODE(V[i][j].a , dist[V[i][j].a][mark+V[i][j].flag] , mark+V[i][j].flag)) ;
            }
        }
    }
}

long min(long a , long c)
{
    if(a<c) return a ;
    return c ;
}

int main()
{
    long loop , test , a , b , c , d , m , k ;
    scanf("%ld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        scanf("%ld%ld%ld%ld",&node,&m,&k,&limit) ;
        for(a=0 ; a<=node ; a++)
            for(c=0 ; c<=12 ; c++)
                dist[a][c]=99999999 ;
        while(m--)
        {
            scanf("%ld%ld%ld",&a,&b,&c) ;
            V[a].push_back(EDGE(b,0)) ;
            cost[a].push_back(c) ;
        }
        while(k--)
        {
            scanf("%ld%ld%ld",&a,&b,&c) ;
            V[a].push_back(EDGE(b,1)) ;
            cost[a].push_back(c) ;
        }
        dijkstra() ;
        c=99999999 ;
        for(a=0 ; a<=12 ; a++)
            c=min(c,dist[node-1][a]) ;
        if(c == 99999999)
            printf("Case %ld: Impossible\n",loop) ;
        else printf("Case %ld: %ld\n",loop,c) ;
        for(a=0 ; a<=node ; a++)
        {
            V[a].clear() ;
            cost[a].clear() ;
        }
    }
}
