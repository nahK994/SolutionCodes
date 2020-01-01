#include<bits/stdc++.h>
using namespace std;

int main()
{
    long loop, test, q, n, a, b, c, c1, mid;
    vector<pair<long, long> >V, revV;
    scanf("%ld",&test);
    for(loop=1 ; loop<=test ; loop++)
    {
        V.clear();
        revV.clear();
        scanf("%ld%ld",&n,&q);
        for(int i=0 ; i<n ; i++)
        {
            scanf("%ld%ld",&a,&b);
            V.push_back(make_pair(a,b));
            revV.push_back(make_pair(b,a));
        }
        sort(V.begin(), V.end());
        sort(revV.begin(), revV.end());

        printf("Case %ld:\n",loop);
        while(q--)
        {
            scanf("%ld",&a);
            b=0 ;
            c=V.size()-1;
            if(V[0].first > a) c=0;
            else if(V[ V.size()-1 ].first < a) c=V.size();
            else
            {
                while(b+1 != c)
                {
                    mid=(b+c)/2;
                    if(V[mid].first > a)
                        c=mid;
                    else if(V[mid].first <= a)
                        b=mid;
                }
            }

            b=0 ;
            c1=revV.size()-1;
            if(revV[0].first > a) b=revV.size();
            else if(revV[ revV.size()-1 ].first < a) b=0;
            else
            {
                while(b+1 != c1)
                {
                    mid=(b+c1)/2;
                    if(revV[mid].first >= a)
                        c1=mid;
                    else if(revV[mid].first < a)
                        b=mid;
                }
                b=revV.size()-1-b;
            }
            printf("%ld\n", c+b-V.size());
        }
    }
    return 0;
}
