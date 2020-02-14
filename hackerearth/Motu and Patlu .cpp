#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long loop, test, a, b, n, patluIndex, motuIndex, motuConsumed;
    vector<long long>patlu, motu;
    scanf("%lld", &test);
    for(loop=1 ; loop<=test ; loop++)
    {
        scanf("%lld", &n);
        for(int i=0 ; i<n ; i++)
        {
            scanf("%lld", &a);
            patlu.push_back(a);
        }

        motu.push_back(patlu[0]);
        for(int i=1 ; i<n ; i++)
            motu.push_back(patlu[i]+motu[i-1]);
        
        patluIndex = n-1;
        motuIndex = motuConsumed = 0;
        
        for( ; patluIndex>motuIndex ; patluIndex--)
        {
            a = motuIndex;
            b = patluIndex-1;
            motuConsumed += 2*patlu[patluIndex];

            while(a<b)
            {
                long long mid = (a+b)/2;
                if(motu[mid] < motuConsumed) a = mid+1;
                else if(motu[mid] > motuConsumed) b = mid-1;
                else a = b = mid;
            }

            if(motu[a]-motuConsumed == 0) motuIndex = a+1;
            else motuIndex = a;

            if(motuIndex == patluIndex) motuIndex--;
        }
        printf("%lld %lld\n", motuIndex+1, n-motuIndex-1);
        if(motuIndex+1 > n-motuIndex-1) printf("Motu\n");
        else if(motuIndex+1 < n-motuIndex-1) printf("Patlu\n");
        else printf("Tie\n");

        motu.clear();
        patlu.clear();
    }
}