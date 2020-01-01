#include<bits/stdc++.h>
using namespace std ;

#define sc(a) scanf("%ld",&a)
#define scc(a,b) scanf("%ld%ld",&a,&b)
long ara1[100] , ara2[100] , n , m ;

int main()
{
    long loop , test , i , j , Count ;
    sc(test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        Count=0 ;
        sc(n) ;

        for(i=0 ; i<n ; i++)
            sc(ara1[i]) ;
        for(i=0 ; i<n ; i++)
            sc(ara2[i]) ;

        sort(ara1,ara1+n) ;
        sort(ara2,ara2+n) ;

        for(i=0 ; i<n ; i++)
            for(j=n-1 ; j>=0 ; j--)
                if(ara1[i] > ara2[j])
                {
                    Count+=2 ;
                    ara2[j]=99999 ;
                    ara1[i]=0 ;
                    break ;
                }

        for(i=0 ; i<n ; i++)
            for(j=n-1 ; j>=0 ; j--)
                if(ara1[i] == ara2[j])
                {
                    Count++ ;
                    ara2[j]=99999 ;
                    ara1[i]=0 ;
                    break ;
                }
                printf("Case %ld: %ld\n",loop,Count) ;
    }
    return 0 ;
}
