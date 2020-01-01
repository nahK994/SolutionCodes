#include <bits/stdc++.h>

using namespace std;

const int MAX = 1005;

int a[MAX],b[MAX],n,m;
vector<int>g[MAX];

void buildGraph()
{
    for(int i=1; i<=n; i++)
    {
        g[i].clear();
        for(int j=1; j<=m; j++)
        {
            if(a[i] == 0)
                continue;
            if(b[j]%a[i] == 0)
                g[i].push_back(j);
        }
    }
}

int par[MAX];
bool vis[MAX];

int dfs(int u)
{
    if(vis[u] == true)
        return 0;
    vis[u] = true;
    for(int i=0; i<(int)g[u].size(); i++)
    {
        int v = g[u][i];
        if(par[v] == -1 || dfs(par[v]))
        {
            par[v] = u;
            return 1;
        }
    }
    return 0;
}

int hungary()
{
    int ret = 0;
    memset(par, -1, sizeof par);
    for(int i=1; i<=n; i++)
    {
        memset(vis,0,sizeof vis);
        ret += dfs(i);
    }
    return ret;
}

int main()
{
    int test, cases=1;
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d", &n);
        for(int i=1; i<=n; i++)
            scanf("%d", a+i);
        scanf("%d", &m);
        for(int i=1; i<=m; i++)
            scanf("%d", b+i);
        buildGraph();
        int ans = hungary();
        printf("Case %d: %d\n",cases++,ans);
    }
    return 0;
}
