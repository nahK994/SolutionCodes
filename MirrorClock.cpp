#include<stdio.h>

int main ()

{
      int i , j ;

      scanf("%d",&j) ;

      for( i=1 ; i<=j ; i++ )

            {

                  int a , b ;

                  char o ;

                  scanf("%d%c%d",&a,&o,&b) ;

                  if(a!=12)

                     {
                          int c=60*a+b ;

                          c=720-c ;

                          int d=c/60 ;

                          float e=((c/60.0)-d)*60.0 ;

                          printf("%d %c% 0.0f\n",d,o,e) ;
                     }

              else if(a>=12)

                      {
                            int c=60*a+b ;

                            c=1440-c ;


                      }

            }

           return 0 ;

}
