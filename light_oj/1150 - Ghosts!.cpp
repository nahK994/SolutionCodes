#include<bits/stdc++.h>
#define INF             1<<30
#define eps             1e-9
#define MOD             1000000007
#define MAX             101

using namespace std;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};

vector < int > G[MAX];
vector < pair< pair<int, int>, int> > E;
bool visited[MAX];
int Left[MAX], Right[MAX];
int high, low;

bool dfs(int u)
{
    if(visited[u]) return false;
    visited[u] = true;

    for(int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if(Right[v] == -1 || dfs(Right[v]))
        {
            Right[v] = u, Left[u] = v;
            return true;
        }
    }
    return false;
}

int match(int n)
{
    memset(Left, -1 , sizeof Left) ;
    memset(Right, -1 , sizeof Right) ;
    int i, ret = 0;
    bool done;

    do
    {
        done = true;
        memset(visited , false , sizeof visited) ;
        for(i = 0; i < n; i++)
            if(Left[i] == -1 && dfs(i))
                done = false;
    }
    while(!done);
    for(i = 0; i < n; i++)
        ret += (Left[i] != -1);
    return ret;
}

int bin_search(int l, int r, int gh, int hu)
{
    int mid;
    while(l < r)
    {
        mid = (l + r) >> 1;
        for(int i=0 ; i<gh ; i++)
            G[i].clear() ;

        for(int i=0 ; i<E.size() ; i++)
            if(E[i].second <= mid)
                G[E[i].first.first].push_back(E[i].first.second);

        if(match(gh) == hu)
            r = mid;
        else
            l = mid+1;
    }
    return r;
}

int cost[26][26];
int grid[26][26], ghosts[51], humans[51];
char str[26][26];
map<int, int>tmp;

void bfs(int x, int y, int n)
{
    int g = grid[x][y];
    memset(cost, -1 , sizeof cost);
    cost[x][y] = 0;

    queue< pair<int,int> >Q;
    Q.push(pair<int,int>(x, y));
    pair<int,int> u;

    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        int h;

        for(int k=0 ; k<4 ; k++)
        {
            int tx = u.first + dx[k];
            int ty = u.second + dy[k];
            if(tx >= 0  && tx < n && ty >= 0 && ty < n && str[tx][ty] != '#' && cost[tx][ty] == -1)
            {
                h = grid[tx][ty];
                cost[tx][ty] = cost[u.first][u.second] + 1;
                if(str[tx][ty] == 'H')
                {
                    E.push_back(pair< pair<int,int>, int>(pair<int,int>(g, h), cost[tx][ty]));
                    high = max(high, cost[tx][ty]);
                    low = min(low, cost[tx][ty]);
                }
                Q.push(pair<int,int>(tx, ty));
            }
        }
    }
}

int main()
{
    int tc, cs = 1, n, m, a, b;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d", &n);
        int cnt = 0, hu = 0, gh = 0;
        for(int i=0 ; i<n ; i++)
        {
            scanf("%s", str[i]);
            for(int j=0 ; j<n ; j++)
            {
                    if(str[i][j] == 'H')
                        grid[i][j] = hu++;
                    else if(str[i][j] == 'G')
                        grid[i][j] = gh++;
            }
        }

        low = INF;
        high = -1;
        for(int i=0 ; i<n ; i++)
            for(int j=0 ; j<n ; j++)
                if(str[i][j] == 'G')
                    bfs(i, j, n);

        printf("Case %d: ", cs++);

        for(int i=0 ; i<gh ; i++)
            G[i].clear() ;

        for(int i=0 ; i<E.size() ; i++)
            if(E[i].second <= high)
                G[E[i].first.first].push_back(E[i].first.second);

        if(match(gh) < hu)
            puts("Vuter Dol Kupokat");
        else printf("%d\n", bin_search(low, high, gh, hu) * 2 + 2);
        E.clear();
    }
    return 0;
}

