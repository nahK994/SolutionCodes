#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN = 1e7+5;
const int M = 1e6+5;
typedef long long LL;
int p[M];
bool prime[MAXN];
int cnt = 0;
void isprime()
{
    cnt = 0;
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    for(LL i=2; i<MAXN; i++)
    {
        if(prime[i])
        {
            p[cnt++] = i;
            for(LL j=i*i; j<MAXN; j+=i)
                prime[j] = false;
        }
    }
}
int main()
{
    isprime();
    int T,n;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        scanf("%d",&n);
        int sum = 0;
        for(int i=0; i<cnt&&p[i]<=n; i++)
            if(prime[n-p[i]])
                sum++;
        sum >>= 1;
        if(prime[n/2])
            sum++;
        printf("Case %d: %d\n",cas,sum);
    }
    return 0;
}
