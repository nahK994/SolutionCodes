#include<stdio.h>

int main ()

{
      int i , j ;

      scanf("%d",&j) ;

      for( i=1 ; i<=j ; i++ )

            {
                  int d1 , m1 , y1 , d2 , m2 , y2 ;

                  char a ;

                  scanf("%d%c%d%c%d%d%c%d%c%d",&d1,&a,&m1,&a,&y1,&d2,&a,&m2,&a,&y2) ;

                  if( (m1*30+d1-m2*30-d2)>=0 )

                     {
                         if( y1-y2>130 )

                         printf("Case #%d: Check birth date\n", i ) ;

                         else if( y1-y2<0 )

                         printf("Case #%d: Invalid birth date\n", i ) ;

                         else printf("Case #%d: %d\n", i , y1-y2) ;
                     }

                  else if( (m1*30+d1-m2*30-d2)<0 )

                     {
                            if( y1-y2-1>130 )

                           printf("Case #%d: Check birth date\n", i ) ;

                           else if( y1-y2-1>=0 )

                           printf("Case #%d: %d\n", i , y1-y2-1) ;

                           else printf("Case #%d: Invalid birth date\n", i ) ;
                     }

            }

         return 0 ;

}
