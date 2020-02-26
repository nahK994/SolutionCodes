#include<bits/stdc++.h>
using namespace std;

int main()
{
    long node, edge, a, b, c;
    vector<pair<pair<long, long>, long> >V;
    scanf("%ld%ld", &node, &edge);
    
    long ara[node+1];

    for(int i=1 ; i<=edge ; i++)
    {
        scanf("%ld%ld%ld", &a, &b, &c);
        V.push_back(make_pair(make_pair(a, b), c));
    }
    
    long negetiveCycle = 0;
    
    for(int i=0 ; i<=node ; i++)
        ara[i] = 99999999;
    ara[1] = 0;

    for(int k=1 ; k<node ; k++)
        for(int i=0 ; i<edge ; i++)
            if(ara[ V[i].first.second ] > ara[ V[i].first.first ] + V[i].second)
                ara[ V[i].first.second ] = ara[ V[i].first.first ] + V[i].second;

    for(int i=0 ; i<edge ; i++)
        if(ara[ V[i].first.second ] > ara[ V[i].first.first ] + V[i].second)
        {
            negetiveCycle = 1;
            ara[ V[i].first.second ] = ara[ V[i].first.first ] + V[i].second;
        }
    
    if(negetiveCycle) 
        printf("Negetive Cycle found\n");
    else
    {
        for(int i=1 ; i<=node ; i++)
            printf("%ld --> %ld\n", i, ara[i]);    
    }
    
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