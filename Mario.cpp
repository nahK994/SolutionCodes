#include<stdio.h>

int main ()

{
      int i , j , b , a , d , x , y , z , count1=0 , count2=0 ;

      int ara[49] ;

      scanf("%d",&j) ;

      for( i=1 ; i<=j ; i++ )

            {
                  scanf("%d",&b) ;

                  for( a=0 ; a<b ; a++ )

                        {
                              scanf("%d",ara[a]) ;
                        }

                  for( x=1 ; x<b ; x++ )

                        {
                              z=ara[x]-ara[0] ;

                              if( z>0 )

                              {
                                  count1++ ;
                              }

                              else if(z<0)

                              {
                                  count2++ ;
                              }
                        }

                  printf("Case %d: %d %d\n", i , count1 , count2 ) ;

            }

            return 0 ;

}
