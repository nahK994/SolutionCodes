#include<stdio.h>
#include<math.h>

int main ()

{
          long a , i , j ;
          while ( scanf("%ld",&a) !=EOF  )
         {
               if( a==0 )
                      {
                            break ;
                      }
              printf("%ld = ",a) ;
               if( a<0 )
                {
                      printf("-1 x ") ;
                      a=a*-1 ;
                }
            j=sqrt(a) ;
            j=floor(j) ;
           for( i=2 ; i<=j ; i++ )
                   {
                          if(a%i==0)
                             {
                                 a=a/i ;
                                 if(a==1)
                                 {
                                     printf("%ld\n",i) ;
                                     break ;
                                 }
                                 else printf("%ld x ",i) ;
                                 i=i-1 ;
                             }
                   }
               if(a!=1)
                  {
                      printf("%ld\n",a) ;
                  }
         }
         return 0 ;
}
