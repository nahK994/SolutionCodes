#include<bits/stdc++.h>
using namespace std ;

int main()
{
    long long loop , test , a , b , c , n , m , cost[250] , mini_cost[250] ;
    vector<long long>data1 , data2 ;
    scanf("%lld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        scanf("%lld",&n) ;
        for(a=1 ; a<=n ; a++)
            scanf("%lld",&cost[a]) ;

        for(a=1 ; a<=n ; a++)
            mini_cost[a]=999999999 ;
        mini_cost[1]=0 ;

        scanf("%lld",&m) ;
        for(c=1 ; c<=m ; c++)
        {
            scanf("%lld%lld",&a,&b) ;
            data1.push_back(a) ;
            data2.push_back(b) ;
        }
        for(a=1 ; a<=n ; a++)
        {
            int update=0 ;
            for(b=0 ; b<m ; b++)
            {
                long A=data1[b] , B=data2[b] ;
                {
                    update=1 ;
                    if(mini_cost[B] > mini_cost[A] + (cost[B]-cost[A])*(cost[B]-cost[A])*(cost[B]-cost[A]) && mini_cost[A] != 999999999)
                        mini_cost[B] = mini_cost[A] + (cost[B]-cost[A])*(cost[B]-cost[A])*(cost[B]-cost[A]) ;
                }
            }
            if(!update) break ;
        }
        scanf("%lld",&m) ;
        printf("Case %lld:\n",loop) ;
        for(a=1 ; a<=m ; a++)
        {
            scanf("%lld",&b) ;
            if(mini_cost[b]<3 || mini_cost[b] == 999999999) printf("?\n") ;
            else printf("%lld\n",mini_cost[b]) ;
        }
          data1.clear() ;
          data2.clear() ;
    }
}
