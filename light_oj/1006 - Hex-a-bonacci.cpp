#include<stdio.h>
#include<string.h>

int main()
{
    long long n, caseno = 0, cases, i , ara[10050] ;
    scanf("%lld", &cases);
    while( cases-- )
    {
        memset(ara,0,sizeof(ara)) ;
        scanf("%lld %lld %lld %lld %lld %lld %lld", &ara[0], &ara[1], &ara[2], &ara[3], &ara[4], &ara[5], &n);
        for(i=6 ; i<=n ; i++) ara[i]=(ara[i-1]+ara[i-2]+ara[i-3]+ara[i-4]+ara[i-5]+ara[i-6])%10000007 ;
        printf("Case %lld: %lld\n", ++caseno, ara[n] % 10000007);
    }
    return 0;
}
