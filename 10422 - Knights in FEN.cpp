#include <cstdio>
#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;
typedef vector<vector<int> > vvi;
typedef vector<int> vi;
typedef pair<vvi, ii> state;

int N;
char horse;
state source, target;
char line[10];
queue<state> q;
map<state, int> dist;

int dx[] = {-1, -2, -2, -1, 1, 2,  2,  1};
int dy[] = {-2, -1,  1,  2, 2, 1, -1, -2};

bool bound(int x, int y)
{
    return x >= 0 && x < 5 &&
           y >= 0 && y < 5;
}

void bfs()
{
    dist[ source ] = 0;
    q.push(source);

    while (!q.empty())
    {
        state u = q.front();
        q.pop();
        if (dist[u] >= 11) return;
        for (int i=0 ; i<8 ; i++)
        {
            state v = u;
            int nx, ny;
            nx = u.second.first + dx[i];
            ny = u.second.second + dy[i];
            if (bound(nx, ny))
            {
                // Swap the horse and the wait space
                int temp = v.first[u.second.first][u.second.second];
                v.first[u.second.first][u.second.second] = v.first[nx][ny];
                v.first[nx][ny] = temp;

                v.second.first = nx;
                v.second.second = ny;
                if (!dist.count(v))
                {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
    }
}

int main()
{
    source.first.assign(5, vi());
    for (int i=0 ; i<5 ; i++) source.first[i].assign(5, 0);

    source.first[0][0] = source.first[1][1] = 1;
    source.first[2][2] = -1;

    for (int i=0 ; i<5 ; i++)
        for (int j=i+1 ; j<5 ; j++)
            source.first[i][j] = 1;
    source.second = ii(2, 2);
    bfs();
    scanf("%d\n", &N);
    while (N--)
    {
        target.first.assign(5, vi());
        for (int i=0 ; i<5 ; i++)
        {
            gets(line);
            for (int j=0 ; j<5 ; j++)
            {
                horse = line[j];
                if (j == 0) target.first[i].assign(5, 0);
                if (horse == '1') target.first[i][j] = 1;
                else if (horse == '0') target.first[i][j] = 0;
                else if (horse == ' ') target.first[i][j] = -1, target.second = ii(i, j);
            }
        }
        int res;
        if (dist.count(target) && (dist[target] <= 10) ) printf("Solvable in %d move(s).\n", dist[target]);
        else printf("Unsolvable in less than 11 move(s).\n");
    }
}
