#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long loop, test, a, b, n, k, aa, bb;
    vector<long long>V;
    scanf("%lld", &test);
    for(loop = 1 ; loop<=test ; loop++)
    {
        scanf("%lld%lld", &n, &k);
        for(int i=0 ; i<n ; i++)
        {
            scanf("%lld", &a);
            V.push_back(a);
        }

        b = 0;
        if(V[0] > k || -1*V[0] > k) b++;

        for(int i=1 ; i<V.size() ; i++)
        {
            V[i]+=V[i-1];
            if(V[i] > k || -1*V[i] > k) b++;
        }
        
        sort(V.begin(), V.end());
        for(int i=0 ; i<V.size()-1 ; i++)
        {
            aa = i+1;
            bb = V.size()-1;
            if(V[i]+k >= V[V.size()-1]) break;

            while(aa<=bb)
            {
                long long mid = (aa+bb)/2;
                if(V[mid] < V[i]+k) aa = mid+1;
                else if(V[mid] > V[i]+k) bb = mid-1;
                else aa = mid+1;
            }

            b+=(n-aa);
        }

        printf("%lld\n", b);
        V.clear();
    }

    return 0;
}