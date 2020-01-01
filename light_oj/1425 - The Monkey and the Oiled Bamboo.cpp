#include<bits/stdc++.h>
using namespace std ;

#define sc(a) scanf("%ld",&a)
#define scc(a,b) scanf("%ld%ld",&a,&b)
long ara[100005] ;

int main()
{
    long loop , test , n , Max , i , j ;
    sc(test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        Max=0 ;
        sc(n) ;
        ara[0]=0 ;
        for(i=1 ; i<=n ; i++)
            sc(ara[i]) ;

        for(i=n ; i>=1 ; i--)
            if(ara[i]-ara[i-1] > Max)
                Max=ara[i]-ara[i-1] ;
            else if(ara[i]-ara[i-1] == Max)
                Max++ ;

        printf("Case %ld: %ld\n",loop,Max) ;
    }
    return 0 ;
}
