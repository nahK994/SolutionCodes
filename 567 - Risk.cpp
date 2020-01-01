#include<algorithm>
#include<cstdio>

using namespace std;

int m, n, t, a, b;
int graph[30][30];

int main() {
    for(int T = 1;; T++) {
        for(int i = 0; i < 20; i++)
            for(int j = 0; j < 20; j++)
                if(i == j) graph[i][j] = 0;
                else graph[i][j] = 10000;

        for(int i = 0; i < 19; i++) {
            if(scanf("%d", &m) == -1) return 0;
            for(int j = 0; j < m; j++) {
                scanf("%d", &n);
                graph[i][n - 1] = 1;
                graph[n - 1][i] = 1;
            }
        }


        for(int k = 0; k < 20; k++)
            for(int i = 0; i < 20; i++)
                for(int j = 0; j < 20; j++)
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);

        scanf("%d", &t);
        printf("Test Set #%d\n", T);
        for(int i = 0; i < t; i++) {
            scanf("%d %d", &a, &b);
            printf("%2d to %2d: %d\n", a, b, graph[a - 1][b - 1]);
        }
        printf("\n");
    }
}
