#include<bits/stdc++.h>
using namespace std ;

long N , w , k , ara[105][105] ;
vector<long>V ;

long rec(long a , long b)
{
    if(a >= N || b<=0)
        return 0 ;

    if(ara[a][b] != -1) return ara[a][b] ;

    long c=rec(a+1,b) ;

    long limit=V[a]+w , Count=0 , A ;
    for(A=a ; A<N && V[A]<=limit ; A++)
        Count++ ;

     long e=Count+rec(A,b-1) ;
     return ara[a][b] = max(e,c) ;
 }

int main()
{
     long loop , test , a , b , c , d , e ;
     scanf("%ld",&test) ;
     for(loop=1 ; loop<=test ; loop++)
     {
          scanf("%ld%ld%ld",&N,&w,&k) ;
          memset(ara,-1,sizeof ara) ;

          for(a=0 ; a<N ; a++)
          {
              scanf("%ld%ld",&b,&c) ;
              V.push_back(c) ;
          }
          sort(V.begin() , V.end()) ;

          printf("Case %ld: %ld\n",loop,rec(0,k)) ;
          V.clear() ;
     }
}
