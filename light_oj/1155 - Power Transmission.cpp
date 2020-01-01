#include<bits/stdc++.h>
using namespace std;
#define MAXX 207
#define INF (1<<29)

int source, sink , N , M , capacity[MAXX][MAXX] ;
vector<int>V[MAXX] ;

int findPath()
{
    bool visited[MAXX];
    int parent[MAXX];
    memset(parent, -1 , sizeof parent);
    memset(visited, 0 , sizeof visited);
    queue<int>Q;
    Q.push(source);
    visited[source] = true;
    bool found = false;
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        for(int i=0 ; i<V[u].size() ; i++)
        {
            int v = V[u][i];
            if(!visited[v] && capacity[u][v])
            {
                visited[v] = true;
                Q.push(v);
                parent[v] = u;
                if(v == sink)
                {
                    found = true;
                    break;
                }
            }
        }

        if(found)
            break ;
    }

    if(!found) return 0 ;

    int v = sink ;
    int pathCapacity = INF ;
 //   printf(":(  %d\n",pathCapacity) ;
    while(parent[v] != -1)
    {
        int u = parent[v] ;
     //   printf("%d\n",v) ;
        pathCapacity = min(pathCapacity, capacity[u][v] ) ;
        v = u ;
    }
     //printf(":D %d\n",pathCapacity) ;
    if(!pathCapacity) return 0 ;

    v = sink ;
    while(parent[v] != -1)
    {
        int u = parent[v] ;
        capacity[u][v] -= pathCapacity ;
        capacity[v][u] += pathCapacity ;
        v = u ;
    }

    if(found)
        return pathCapacity ;
}

int FLOW()
{
    int result = 0;
    while(true)
    {
        int pathCapacity=findPath() ;
     //   printf("%d\n",pathCapacity) ;
        if(!pathCapacity) break ;
        result += pathCapacity;
    }
    return result;
}

int main()
{
    int loop, test , B, D , u, v, c ;
    scanf("%d", &test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        scanf("%d", &N) ;
        memset(capacity, 0 , sizeof capacity) ;
        for(int i=0; i<=N+1; i++)
            V[i].clear() ;

        source = 0 ;
        sink = 2*N+1 ;

        for(int i=1; i<=N; i++)
        {
            u = 2*i - 1 ;
            v = u + 1 ;
            V[u].push_back(v) ;
            V[v].push_back(u) ;
            scanf("%d", &capacity[u][v]) ;
        }

        scanf("%d", &M) ;
        for(int i=0 ; i<M ; i++)
        {
            scanf("%d %d %d", &u, &v, &c) ;
            u = 2*u ;
            v = 2*v - 1 ;
            V[u].push_back(v) ;
            V[v].push_back(u) ;
            capacity[u][v] = c ;
        }

        scanf("%d %d", &B, &D) ;
        for(int i=0 ; i<B ; i++)
        {
            scanf("%d", &u) ;
            u = 2*u  - 1;
            V[source].push_back(u) ;
            V[u].push_back(source) ;
            capacity[ source ][u] = INF ;
        }

        for(int i=0 ; i<D ; i++)
        {
            scanf("%d", &v) ;
            v = 2*v;
            V[v].push_back(sink) ;
            V[sink].push_back(v) ;
            capacity[v][sink] = INF ;
        }

        printf("Case %d: %d\n", loop, FLOW()) ;
    }
    return 0 ;
}
/*
2
4
30 27 82 15
5
2 4 20
3 2 55
3 1 92
2 1 92
3 4 28
2 1
3 4 1
5
96 9 96 9 29
10
5 3 72
3 1 58
2 3 33
2 1 89
4 2 59
5 4 85
1 5 67
2 5 30
1 4 48
3 4 70
2 2
1 5 3 4
*/

/*
Case 1: 30
Case 2: 38
*/
