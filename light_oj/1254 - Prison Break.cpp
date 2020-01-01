#include<bits/stdc++.h>
using namespace std;

struct NODE
{
    long node, cost, residueDistance;
    NODE(long a1 , long b1, long c1)
    {
        node = a1;
        cost = b1;
        residueDistance = c1;
    }
    NODE() {}
    bool operator < (const NODE & p) const
    {
        return p.cost<cost;
    }
};

vector<long>oilPrice, V[110], dis[110];
priority_queue<struct NODE>Q;
long cost[110][110];

int main()
{
    long loop, test, node, edge, a, b, c, n, ans;
    scanf("%ld", &test);
    for(loop=1 ; loop<=test ; loop++)
    {
        scanf("%ld%ld", &node, &edge);
        for(int i=0 ; i<node ; i++)
        {
            scanf("%ld", &a);
            oilPrice.push_back(a);
        }
        while(edge--)
        {
            scanf("%ld%ld%ld", &a, &b, &c);
            V[a].push_back(b);
            V[b].push_back(a);
            dis[a].push_back(c);
            dis[b].push_back(c);
        }

        printf("Case %ld:\n", loop);
        scanf("%ld", &n);
        while(n--)
        {
            scanf("%ld%ld%ld", &c, &a, &b);
            for(int i=0 ; i<node ; i++)
                for(int j=0 ; j<=c ; j++)
                    cost[i][j] = 999999999;

            cost[a][0] = 0;
            Q.push(NODE(a, 0, 0));   // node, cost, residueDistance
            ans = 999999999;
            //long aaa = 0;
            while(!Q.empty())
            {
                long node = Q.top().node, Cost = Q.top().cost, residueDistance = Q.top().residueDistance;
                Q.pop();

                if(node == b)
                {
                    printf("%ld\n", Cost);
                    ans = Cost;
                    while(!Q.empty())
                        Q.pop();
                    break;
                }

                for(int j=1 ; j<=c-residueDistance ; j++)
                    if(cost[node][j+residueDistance] > Cost + j*oilPrice[node])
                    {
                        cost[node][j+residueDistance] = Cost + j*oilPrice[node];
                        Q.push(NODE(node, cost[node][j+residueDistance], j+residueDistance));
                    }

                for(int i=0 ; i<V[node].size() ; i++)
                    if(dis[node][i] <= residueDistance && cost[V[node][i]][residueDistance-dis[node][i]] > Cost)
                    {
                        cost[V[node][i]][residueDistance-dis[node][i]] = Cost;
                        Q.push(NODE(V[node][i], cost[V[node][i]][residueDistance-dis[node][i]], residueDistance-dis[node][i]));
                    }
            }

            if(ans == 999999999) printf("impossible\n");
        }

        oilPrice.clear();
        for(int i=0 ; i<node ; i++)
        {
            V[i].clear();
            dis[i].clear();
        }
    }
}
/*
1
5 5
10 10 20 12 13
0 1 9
0 2 8
1 2 1
1 3 11
2 3 7
4
10 1 2
10 0 3
20 0 3
20 1 4




1
4 2
10 20 30 40
0 1 5
0 2 4
2
8 0 1
8 0 2
*/
