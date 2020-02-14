#include<bits/stdc++.h>
using namespace std;

int main()
{
    long n, q, a, b, aa, bb, sum, cc, dd;
    vector<long>V;

    scanf("%ld", &n);
    for(long i=0 ; i<n ; i++)
    {
        scanf("%ld", &a); 
        V.push_back(a);
    }
    sort(V.begin(), V.end());
 
    scanf("%ld", &q);
    while(q--)
    {
        scanf("%ld%ld", &b, &a);
        
        if(b) a++;

        aa = 0;
        bb = V.size()-1;
        sum = 0;

        while(aa<=bb)
        {
            long mid = (aa+bb)/2;
            if(V[mid] < a) aa = mid+1;
            else if(V[mid] > a) bb = mid-1;
            else 
                bb = mid-1;
        }
        //printf("bb = %ld\n", bb);

        printf("%ld\n", V.size()-1-bb);
    }
    return 0;
}