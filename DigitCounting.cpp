#include<stdio.h>

int main ()

{
      long a , i , sum=0 , b ;

      scanf("%ld",&a) ;

      for( i=1 ; i>=1 ; i++ )

            {
                 b=a%10 ;

                 sum=sum+b ;

                 a=a/10 ;
             }

      return 0 ;
}
