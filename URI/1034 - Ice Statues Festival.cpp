#include<bits/stdc++.h>
using namespace std;

int main()
{
    long test, n, m, arr[1000020], a;
    vector<long>V;
    scanf("%ld", &test);
    while (test--)
    {
        scanf("%ld%ld", &n, &m);
        memset(arr, 1000000, sizeof arr);
        arr[0] = 0;

        for(int i=0 ; i<n ; i++)
        {
            scanf("%ld", &a);
            V.push_back(a);
        }

        for(int i=0 ; i<V.size() ; i++)
            for(int j=V[i] ; j<=m ; j++)
                arr[j] = min(arr[j], 1 + arr[j-V[i]]);

        printf("%ld\n", arr[m]);
        V.clear();
    }
    return 0;
}