#include<bits/stdc++.h>
using namespace std;

long color[100010], val[100010];
vector<long>V[100010], A, B;
long counter;

void dfs(long a)
{
    color[a] = 1;
    for(int i=0 ; i<V[a].size() ; i++)
        if(!color[ V[a][i] ])
        {
            dfs(V[a][i]);
            val[a] += val[ V[a][i] ];
        }
}

int main()
{
    long N, a, b, c;

    scanf("%ld", &N);
    scanf("%ld%ld", &a, &b);
    for(int i=1 ; i<=N-1 ; i++)
    {
        scanf("%ld%ld", &a, &b);
        V[a].push_back(b);      V[b].push_back(a);
        //Pair.push_back(make_pair(a, b));
        A.push_back(a);     B.push_back(b);
    }

    for(int i=0 ; i<=N ; i++)
        val[i] = 1;

    dfs(1);

    for(int i=0 ; i<N-1 ; i++)
    {
        counter = min(val[ A[i] ], val[ B[i] ]);
        printf("%ld\n", counter*(N-counter));
    }

    return 0;
}