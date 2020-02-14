#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n, a, b, c;
    vector<long long>V, A;

    scanf("%lld", &n);
    for(a=1 ; a<=n ; a++)
    {
        scanf("%lld", &b);
        V.push_back(b);
        A.push_back(b);
    }

    sort(V.begin(), V.end());
    
    b = c = 0;
    for(a=0 ; a<n ; a++)
    {
        if(A[a] != V[a]) b++;
        if(A[a] != V[ V.size()-1-a ]) c++; 
    }

    if(b>c) printf("%lld\n", c/2);
    else printf("%lld\n", b/2);
}