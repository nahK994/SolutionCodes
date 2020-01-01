#include<bits/stdc++.h>
using namespace std ;
#define Max 99999999
long dist[50005] , n , fNode , lNode , par[50005] ;
vector<long>V[50005] ;
queue<long>Q ;
stack<long>S ;

void bfs()
{
    long a , b ;
    for(a=1 ; a<=50000 ; a++)
    {
        sort(V[a].begin() , V[a].end()) ;
        dist[a] = Max ;
        par[a]=0 ;
    }

    dist[fNode]=0 ;
    Q.push(fNode) ;
    while(!Q.empty())
    {
        a=Q.front() ;
        Q.pop() ;
        if(a == lNode) continue ;
        for(b=0 ; b<V[a].size() ; b++)
            if(dist[ V[a][b] ] > dist[a]+1)
            {
                Q.push(V[a][b]) ;
                par[V[a][b]] = a ;
                dist[ V[a][b] ] = dist[a]+1 ;
            }
    }
    a=lNode ;
    while(a)
    {
        S.push(a) ;
        a=par[a] ;
    }
}
int main()
{
    long loop , test , a , b , c ;
    scanf("%ld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        scanf("%ld",&n) ;

        scanf("%ld",&fNode) ;
        b=fNode ;
        for(a=2 ; a<n ; a++)
        {
            scanf("%ld",&c) ;
            V[b].push_back(c) ;
            V[c].push_back(b) ;
            b=c ;
        }
        scanf("%ld",&lNode) ;
        V[b].push_back(lNode) ;
        V[lNode].push_back(b) ;

        bfs() ;

        printf("Case %ld:\n",loop) ;
        printf("%ld",S.top()) ;
        S.pop() ;
        while(!S.empty())
        {
            printf(" %ld",S.top()) ;
            S.pop() ;
        }
        printf("\n") ;
        for(a=1 ; a<=50000 ; a++)
            V[a].clear() ;
    }
}
