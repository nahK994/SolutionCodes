#include<stdio.h>
#include<algorithm>

using namespace std ;

int main ()

{
    int i , j , b , c ;

    int ara[10] ;

    int a ;

    scanf("%d",&j) ;

    for( i=1 ; i<=j ; i++ )

          {
              scanf("%d",&b) ;

              for( c=0 ; c<b ; c++ )

                    {
                          scanf("%d",&ara[c]) ;
                    }

               sort(ara,ara+b) ;

               a=b/2 ;

               printf("Case %d: %d\n", i , ara[a]) ;
          }

         return 0 ;

}
