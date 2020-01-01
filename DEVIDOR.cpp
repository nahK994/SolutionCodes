#include<stdio.h>
#include<math.h>

int main ()

{
      long lowest_value, highest_value, a, b, n,count=0, max=0, d, i, j ;

      scanf("%ld",&j) ;

      for( i=1 ; i<=j ; i++ )

         {
             max=0;

          scanf("%ld%ld",&lowest_value,&highest_value) ;

          for( a=lowest_value ; a<=highest_value ; a++ )

               {
                  count=0 ;

                  n=sqrt(a) ;

                  for( b=1 ; b<=n ; b++ )

                        {
                              if( a%b==0 )

                              {
                                  count=count+2 ;
                              }

                        }

				         if( n*n==a )

                           {
                                count=count-1 ;
                           }

                              if( count>max )

                              {
                                  d=a ;

                                  max=count ;
                              }

                      }

                   printf("Between %ld and %ld, %ld has a maximum of %ld divisors.\n", lowest_value, highest_value, d, max) ;

           }

              return 0 ;

}
