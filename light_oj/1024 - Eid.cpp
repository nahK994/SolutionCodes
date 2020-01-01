#include<bits/stdc++.h>
#define sz 10000

using namespace std;
int sv[sz];



string multiply( string a, long long b )
{
    // a contains the biginteger in reversed form
    int carry = 0;
    for( int i = 0; i < a.size(); i++ )
    {
        carry += (a[i] - 48) * b;
        a[i] = ( carry % 10 + 48 );
        carry /= 10;
    }
    while( carry )
    {
        a += ( carry % 10 + 48 );
        carry /= 10;
    }
    return a;
}


int main()
{
    int test,n ;
    long long x,mul;
    string lcm,temp, s ;
    char ans[1000000] ;
    vector <int> prime;

    sv[1]=1 ;
    for (int i = 2; i <= sz; i++)
    {
        if(sv[i] == 0)
        {
            prime.push_back(i);
            for (int j = 2*i ; j <= sz; j += i)
            {
                sv[j] = 1;
            }
        }
    }

    scanf("%d", &test);

    for (int loop = 1; loop <= test; loop++)
    {
        long long fact[10000];
        memset(fact, 0, sizeof fact);
        scanf("%d", &n);
        lcm = "1";

        for(int j = 0; j < n; j++)
        {

            scanf("%lld", &x);
            // cout << "=== " << x << endl;
            for (int i = 0; i < prime.size() and  prime[i] <= x ; i++)
            {
                mul = 1 ;
                while(x % prime[i] == 0)
                {
                    // cout << mul << "inside \n";
                    mul = mul * prime[i] ;
                    x = x / prime[i] ;
                }
                fact[i] = max(fact[i], mul) ;
            }
        }

        for (int i = 0; i < prime.size(); i++)
        {
            if(fact[i] != 0)
            {
                lcm = multiply(lcm, fact[i]);
            }

        }
        s = lcm;
        for (int i = 0, j = s.size() - 1; i < s.size(); i++, j--)
            ans[i] = s[j] ;
        ans[s.size()] = '\0';
        printf("Case %d: %s\n", loop, ans);
    }
}
