#include<stdio.h>
#include<algorithm>

using namespace std;

int main ()

{
    int i , j , a ;

    int ara[3] ;

    scanf("%d",&j) ;

    for( i=1 ; i<=j ; i++ )

          {
                for( a=0 ; a<3 ; a++ )

                      {
                           scanf("%d",&ara[a]) ;
                      }

                sort(ara,ara+3) ;

                printf("Case %d: %d\n", i , ara[1]) ;

          }

    return 0 ;

}
