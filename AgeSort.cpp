#include<stdio.h>
#include<algorithm>

using namespace std ;

int main()

{
      long a , b , c ;
      while(scanf("%ld",&a)!=EOF)
                {
                    int ara[2000000]={0} ;
                    if(a==0)
                       break ;
                    for( b=0 ; b<a ; b++ )
                         {
                               scanf("%ld",&ara[b]) ;
                         }
                    sort( ara , ara+a ) ;
                    for( c=0 ; c<a ; c++ )
                         {
                             if(c==a-1)
                             printf("%ld",ara[c]) ;
                             else printf("%ld ",ara[c]) ;
                         }
                    printf("\n") ;
                }
              return 0 ;
}
