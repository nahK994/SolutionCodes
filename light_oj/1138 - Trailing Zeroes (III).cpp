#include<bits/stdc++.h>
using namespace std ;

long long asdf(long long a)
{
    long long Count = 0 ;
    while(a)
        Count+=a/=5 ;
    return Count ;
}

int main()
{
    long long loop , test , a , b , c , d , e ;
    scanf("%lld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        a=0 , b=1000000000 ;
        scanf("%lld",&e) ;
        while(a<b)
        {
            c=(a+b)/2 ;
            if(asdf(c) > e)
                b=c-1 ;
                else if(asdf(c) < e)
                    a=c+1 ;
                else a=b=c ;
        }
        c=c-(c%5) ;
        if(asdf(c) == e)
            printf("Case %lld: %lld\n",loop,c) ;
        else printf("Case %lld: impossible\n",loop) ;
    }
    return 0 ;
}

/*
8
1
151
99999981
99999988
99999998
12
11
10
*/
/*
Case 1: 5
Case 2: 615
Case 3: 399999960
Case 4: 399999990
Case 5: 400000005
Case 6: 50
Case 7: impossible
Case 8: 45
*/
