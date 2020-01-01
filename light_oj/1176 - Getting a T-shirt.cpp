#include<bits/stdc++.h>
using namespace std;


vector < vector <int> > g;

int a[800][800];
int parent[800];
int n;
int m;
int s;
int colors;
int destination;

int bfs()
{
    int vis[800],top,x;

    memset(vis, 0, sizeof vis);

    queue <int> q;
    q.push(s);
    vis[s] = 1;

    while(!q.empty())
    {
        top = q.front();
        q.pop();
        for (int i = 0; i < g[top].size(); i++)
        {
            x = g[top][i];
            if(a[top][x] > 0 and vis[x] == 0)
            {
                q.push(x);
                vis[x] = 1;
                parent[x] = top;
            }
        }
    }

    return vis[destination] == 1 ;
}


int main()
{
    int t, k;
    string c;
    map <string, int> mp;

    mp["XXL"] = 1;
    mp["XL"] = 2;
    mp["L"] = 3;
    mp["M"] = 4;
    mp["S"] = 5;
    mp["XS"] = 6;

    cin >> t;

    for (int cs = 1; cs <= t; cs++)
    {
        int ans, p,flow;
        ans = flow = 0 ;

        cin >> n >> m ;

        s = m + 6 + 1;
        destination = s + 1;

        vector < vector <int> > tv(800);
        memset(a, 0, sizeof a);
        swap(tv, g);

        for (int i = 1; i <= m; i++)
        {
            a[s][i] = 1;
            g[s].push_back(i);
            g[i].push_back(s);

            cin >> c;
            k = mp[c] + m;
            a[i][k] = 1;
            g[i].push_back(k);
            g[k].push_back(i);

            cin >> c;
            k = mp[c] + m;
            a[i][k] = 1;
            g[i].push_back(k);
            g[k].push_back(i);
        }

        for (int i = 1; i <= 6; i++)
        {
            k = i + m;
            a[k][destination] = n;
            g[k].push_back(destination);
            g[destination].push_back(k);
        }


        while(bfs())
        {
            k = destination;
            flow = INT_MAX;

            while(k != s)
            {
                p = parent[k];
                flow = min(flow, a[p][k]);
                k = parent[k];
            }

            k = destination;

            while(k != s)
            {
                p = parent[k];
                a[k][p] += flow;
                a[p][k] -= flow;
                k = parent[k];
            }

            ans += flow;
        }

        if(ans == m)
            printf("Case %d: YES\n", cs);
        else
            printf("Case %d: NO\n", cs);

    }
}
