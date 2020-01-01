#include<stdio.h>
#include<string.h>

long ara[30][3] , min_cost[30][3] , n ;

long min(long a , long b)
{
      if(a<b) return a ;
      return b ;
}

int main()
{
      long loop , test , a , b , c ;
      scanf("%ld",&test) ;
      for(loop=1 ; loop<=test ; loop++)
      {

            scanf("%ld",&n) ;
            for(a=0 ; a<n ; a++)
                  scanf("%ld%ld%ld",&ara[a][0],&ara[a][1],&ara[a][2]) ;

             for(a=1 ; a<n ; a++)
             {
                   ara[a][0]+=min(ara[a-1][1],ara[a-1][2]) ;
                   ara[a][1]+=min(ara[a-1][0],ara[a-1][2]) ;
                   ara[a][2]+=min(ara[a-1][0],ara[a-1][1]) ;
             }
             a=min(ara[n-1][0],ara[n-1][1]) ;
             a=min(ara[n-1][2],a) ;

             printf("Case %ld: %ld\n",loop,a) ;
      }
}

