#include<stdio.h>

int main ()

{
      long i , j , a , b , c ;
      scanf("%ld",&j) ;
      for( i=1 ; i<=j ; i++ )
           {
                scanf("%ld%ld%ld",&a,&b,&c) ;
                if( a+b>c && b+c>a && a+c>b )
                printf("OK\n") ;
                else printf("Wrong!!\n") ;
           }
      return 0 ;
}
