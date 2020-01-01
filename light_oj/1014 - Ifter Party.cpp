#include<bits/stdc++.h>
using namespace std ;

int main()
{
    long long loop , test , a , b , c , d , e ;
    vector<long long>V ;
    scanf("%lld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        scanf("%lld%lld",&a,&b) ;
        c=a-b ;
        for(d=1 ; d<=sqrt(c) ; d++)
        if(c%d == 0 && d>b)
            {
                V.push_back(d) ;
                if((c/d)>b && d*d != c)
                V.push_back(c/d) ;
            }
        else if(d<=b && c%d == 0 && (c/d) > b)
            V.push_back(c/d) ;

        if(!V.size())
            printf("Case %lld: impossible\n",loop) ;
        else
        {
            sort(V.begin(),V.end()) ;
            printf("Case %lld:",loop) ;
            for(a=0 ; a<V.size() ; a++)
                printf(" %lld",V[a]) ;
            printf("\n") ;
            V.clear() ;
        }
    }
}
