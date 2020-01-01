#include<bits/stdc++.h>
using namespace std;
#define LL long long int
#define MX pow(10,18)
int main()
{
    LL ara[100],a,b,c,d;
    ara[0]=1;
    d=MX;
  //  printf("%lld\n",d);
    for (a=1; ; a++ )
    {
        ara[a]=a*ara[a-1];
        if(ara[a]>MX)
            break;
    }
    LL kase,num,kk=1;
//    printf("%lld\n",ara[5]);
    scanf("%lld",&kase);
    for (; kase-- ; )
    {
        vector<LL>vec;
        scanf("%lld",&num);
        for (LL i=a; i>=0; i-- )
        {
            if(ara[i]<=num)
            {
                vec.push_back(i);
                num-=ara[i];
                if(num<=0)
                    break;
            }
        }
        printf("Case %lld: ",kk++);
        if(!num)
        {
            LL sz=vec.size()-1;
            printf("%lld!",vec[sz]);
            if(sz>0)
            for (LL i=sz-1; i>=0 ; i-- )
            {
                printf("+%lld!",vec[i]);
            }
            puts("");
        }
        else puts("impossible");
        // vec.clear();
    }
    return 0;
}
