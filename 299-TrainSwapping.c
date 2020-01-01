#include<stdio.h>

int main ()

{
      int i , j , a , b , c , d , e , t , count ;
      int ara[60] ;
      scanf("%d",&j) ;
      for(i=1 ; i<=j ; i++)
      {
          count=0 ;
          scanf("%d",&c) ;
          for(b=0 ; b<c ; b++)
          scanf("%d",&ara[b]) ;
          for(d=0 ; d<c-1 ; d++)
          for(e=0 ; e<c-1 ; e++)
          if(ara[e]>ara[e+1])
          {
              t=ara[e] ;
              ara[e]=ara[e+1] ;
              ara[e+1]=t ;
              count++ ;
          }
          printf("Optimal train swapping takes %d swaps.\n",count) ;
      }
      return 0 ;
}
