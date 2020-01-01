#include<stdio.h>
#include<math.h>

int main ()

{
          long a , i , j , count , p ;
          while ( scanf("%ld",&a) !=EOF  )
         {
            count=0 ;
            if( a==0 )
               break ;
            j=a/2 ;
            j=ceil(j) ;
           for( i=2 ; i<=j ; i++ )
                {
                    for(p=2 ; p<i ; p++)
                         {
                             if(i%p==0)
                                break ;
                         }
                    if( p==i && a%i==0 )
                       count++ ;
                }
            printf("%ld : %ld\n",a,count) ;
        }
         return 0 ;
}

