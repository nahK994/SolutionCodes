#include<bits/stdc++.h>
using namespace std;

int main()
{
    long loop, test, node, edge, a, b, dist[100000];
    vector<long>V[100000], cost[100000];
    queue<long>Q;
    scanf("%ld", &test);
    for(loop=1 ; loop<=test ; loop++)
    {
        scanf("%ld%ld", &node, &edge);
        while(edge--)
        {
            scanf("%ld%ld", &a, &b);
            V[a].push_back(b);
            V[b].push_back(a);

            cost[a].push_back(b);
            cost[b].push_back(a);
        }

        memset(dist, 0, sizeof dist);

        for(int i=2 ; i<=node ; i++)
            dist[i] = 99999999;
        
        Q.push(1);
        while(!Q.empty())
        {
            a = Q.front();
            Q.pop()
            for(int i=0 ; i<V[a].size() ; i++)
                if(dist[ V[a][i] ] > dist[a]+1)
                    dist[ V[a][i] ] = dist[a]+1;
        }

        printf("%ld\n", dist[node-1]);

        for(int i=0 ; i<=node ; i++)
        {
            V[i].clear();
            cost[i].clear();
        }
    }
}