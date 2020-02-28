#include<bits/stdc++.h>
using namespace std;

int main()
{
    long test, loop, a, b, c, W, n, maxWeight, sum;
    vector<long> Weight, Price;
    scanf("%ld", &test);
    for(loop=1; loop<=test ; loop++)
    {
        scanf("%ld", &n);
        sum = 0;
        maxWeight = 0;

        Price.push_back(0);
        Weight.push_back(0);
        for(int i=1 ; i<=n ; i++)
        {
            scanf("%ld%ld", &a, &b);
            Price.push_back(a);
            Weight.push_back(b);

            if(b > maxWeight) maxWeight = b;
        }
        
        long ara[1000][1000];
        
        scanf("%ld", &c);
        while(c--)
        {
            scanf("%ld", &W);

            for(int i=0 ; i<n+1 ; i++)
                for(int j=0 ; j<W+1; j++)
                    ara[i][j] = 0;

            for(int i=1 ; i<Price.size() ; i++)
            {
                for(int j=0 ; j<Weight[i] ; j++)
                    ara[i][j] = ara[i-1][j];
                for(int j=Weight[i] ; j<=W ; j++)
                    ara[i][j] = max(ara[i-1][j], ara[i-1][j-Weight[i]] + Price[i]);

                /*
                for(int i=0 ; i<Price.size() ; i++)
                {
                    for(int j=0 ; j<=W ; j++)
                        printf(" %ld", ara[i][j]);
                    printf("\n");
                }
                printf("\n");
                */
            }
            sum += ara[n][W];
        }
        printf("ans = %ld\n", sum);
        Weight.clear();
        Price.clear();
    }
}

// https://onlinejudge.org/external/101/p10130.pdf
/*
1
3
72 17
44 23
31 24
1
26

2
3
72 17
44 23
31 24
1
26
6
64 26
85 22
52 4
99 18
39 13
54 9
4
23
20
20
26
*/