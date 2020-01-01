#include<stdio.h>
#include<math.h>

int main ()

{
      int i , j , h , k , a , sum=0 ;

      float count=0 ;

      int ara[10000] ;

      scanf("%d",&j) ;

      for( i=1 ; i<=j ; i++ )

            {
                  scanf("%d",&k) ;

                  for( h=1 ; h<=k ; h++ )

                        {
                               scanf("%d",&a) ;

                               ara[h]=a ;

                               sum=sum+a ;
                        }

                      float avarage = sum/k ;

                      for( h=1 ; h<=k ; h++ )

                            {
                                  if( ara[h]>avarage )

                                     {
                                         count++ ;
                                     }
                            }

                    printf("%0.3f%c\n",count*100/ k,37) ;

            }

           return 0 ;

}
