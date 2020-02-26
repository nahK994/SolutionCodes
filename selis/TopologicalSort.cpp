#include<bits/stdc++.h>
using namespace std;

int main()
{
    long node, edge, a, b, c;
    scanf("%ld%ld", &node, &edge);
    
    vector<long>V[node+1], ans;
    long inDegree[node+1];
    queue<long>Q;

    for(int i=0 ; i<=node ; i++)
        inDegree[i] = 0;

    for(int i=1 ; i<=edge ; i++)
    {
        scanf("%ld%ld", &a, &b);
        V[a].push_back(b);
        inDegree[b]++;
    }
    
    for(int i=1 ; i<=node ; i++)
        if(inDegree[i] == 0)
            Q.push(i);
    
    while(!Q.empty())
    {
        a = Q.front();
        Q.pop();
        ans.push_back(a);

        for(int i=0 ; i<V[a].size() ; i++)
        {
            inDegree[V[a][i]]--;
            if(inDegree[V[a][i]] == 0) 
                Q.push(V[a][i]);
        }
    }
    
    if(ans.size())
    {
        printf("%ld", ans[0]);
        for(int i=1 ; i<ans.size() ; i++)
            printf(" %ld", ans[i]);
        printf("\n");
    }
    else
    {
        printf(":(\n");
    }
    
    return 0;
}