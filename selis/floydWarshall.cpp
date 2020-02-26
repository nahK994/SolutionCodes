#include<bits/stdc++.h>
using namespace std;

int main()
{
    long node, edge, a, b, c;
    scanf("%ld%ld", &node, &edge);
    
    long ara[node+1][node+1];

    for(int i=0 ; i<=node ; i++)
        for(int j=0 ; j<=node ; j++)
            ara[i][j] = 99999999;

    for(int i=1 ; i<=node ; i++)
        ara[i][i] = 0;

    for(int i=1 ; i<=edge ; i++)
    {
        scanf("%ld%ld%ld", &a, &b, &c);
        ara[a][b] = ara[b][a] = c;
    }

    for(int k=1 ; k<=node ; k++)
        for(int i = 1 ; i<=node ; i++)
            for(int j=1 ; j<=node ; j++)
                if(ara[i][j] > ara[i][k] + ara[k][j])
                    ara[i][j] = ara[i][k] + ara[k][j];
    
    for(int i=1 ; i<=node ; i++)
        for(int j=1 ; j<=node ; j++)
            printf("%ld - %ld --> %ld\n", i, j, ara[i][j]);
    
    return 0;
}
/*
6 6
1 2 1
2 3 2
2 4 4
2 6 6
2 5 5
3 5 2
*/