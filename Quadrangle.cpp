#include<stdio.h>

int main ()

{
      long i , j , a , b , c , d ;

      scanf("%ld",&j) ;

      for( i=1 ; i<=j ; i++ )

            {
                 scanf("%ld%ld%ld%ld",&a,&b,&c,&d) ;

                  if(a==b && b==c && c==d && d==a)

                 printf("square\n") ;

                 else if((a==c && b==d) || (a==b && c==d) || (a==d && b==c) )

                 printf("rectangle\n") ;

                 else if(((a+b+c)>d) && ((a+b+d)>c) && ((b+c+d)>a) && ((a+d+c)>b) )

                printf("quadrangle\n") ;

                else printf("banana\n") ;
            }

         return 0 ;

}
