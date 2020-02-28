#include<bits/stdc++.h>
using namespace std;

bool func(pair<long, long>a, pair<long, long>b)
{
    if(a.first <= b.first) return a.first <= b.first;
    return a.second <= b.second;
}

int main()
{
    vector<pair<long, long> >V;
    V.push_back(make_pair(1, 2));
    V.push_back(make_pair(-3, 5));
    V.push_back(make_pair(-3, -4));
    V.push_back(make_pair(5, 2));
    V.push_back(make_pair(0, 6));
    V.push_back(make_pair(-5, 10));
    V.push_back(make_pair(1, 2));
    V.push_back(make_pair(0, 2));

    for(int i=0 ; i<V.size() ; i++)
        printf("%ld %ld\n", V[i].first, V[i].second);
    printf("\n\n");
    
    sort(V.begin(), V.end());
    
    for(int i=0 ; i<V.size() ; i++)
        printf("%ld %ld\n", V[i].first, V[i].second);
}