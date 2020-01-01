#include<bits/stdc++.h>
using namespace std;
long test,p;
long i,n,b;
double f[1000010];

int main()
{
    scanf("%ld",&test) ;
    for(i = 1; i <= 1000000; i++)
        f[i] = log((i)) + f[i-1];
    for(p = 1; p <= test; p++)
    {
        //cin >> n >> b;
        scanf("%ld%ld",&n,&b) ;
        //cout << "Case " << p << ": " << (long)(f[n]/(f[b]-f[b-1])+1) << endl;
        printf("Case %ld: %ld\n",p,(long)(f[n]/(f[b]-f[b-1])+1)) ;
    }
    return 0;
}

