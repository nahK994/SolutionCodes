#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

const int N = 110;
const int INF = 0x3f3f3f3f;
typedef long long ll;
struct edge
{
    int to, cap, next;
} g[N*100];
int head[N], iter[N], level[N];
int n, m, cnt, _case = 0;
void add_edge(int v, int u, int cap)
{
    g[cnt].to = u, g[cnt].cap = cap, g[cnt].next = head[v], head[v] = cnt++;
    g[cnt].to = v, g[cnt].cap = 0, g[cnt].next = head[u], head[u] = cnt++;
}
bool bfs(int s, int t)
{
    memset(level, -1, sizeof level);
    level[s] = 0;
    queue<int> que;
    que.push(s);
    while(! que.empty())
    {
        int v = que.front();
        que.pop();
        for(int i = head[v]; i != -1; i = g[i].next)
        {
            int u = g[i].to;
            if(g[i].cap > 0 && level[u] < 0)
            {
                level[u] = level[v] + 1;
                que.push(u);
            }
        }
    }
    return level[t] == -1;
}
int dfs(int v, int t, int f)
{
    if(v == t) return f;
    for(int &i = iter[v]; i != -1; i = g[i].next)
    {
        int u = g[i].to;
        if(g[i].cap > 0 && level[v] < level[u])
        {
            int d = dfs(u, t, min(g[i].cap, f));
            if(d > 0)
            {
                g[i].cap -= d, g[i^1].cap += d;
                return d;
            }
        }
    }
    return 0;
}
int dinic(int s, int t)
{
    int flow = 0, f;
    while(true)
    {
        if(bfs(s, t)) return flow;
        memcpy(iter, head, sizeof head);
        while(f = dfs(s, t, INF), f > 0)
            flow += f;
    }
}
int main()
{
    int t, a, b, c;
    scanf("%d", &t);
    while(t--)
    {
        cnt = 0;
        memset(head, -1, sizeof head);
        scanf("%d%d", &n, &m);
        for(int i = 2; i <= n - 1; i++)
        {
            scanf("%d", &a);
            add_edge(i, n + i, a);
        }

        add_edge(1, n + 1, INF);
        add_edge(n, n + n, INF);
        for(int i = 1; i <= m; i++)
        {
            scanf("%d%d%d", &a, &b, &c);
            add_edge(a + n, b, c);
            add_edge(b + n, a, c);
        }
        printf("Case %d: %d\n", ++_case, dinic(1, n));
    }
    return 0;
}
