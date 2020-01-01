#include<stdio.h>

int main ()

{
      int i , j , a , b , c , count1 , count2 ;
      int ara[50] ;
      scanf("%d",&j) ;
      for(i=1 ; i<=j ; i++)
      {
           count1=0 ;
           count2=0 ;
           scanf("%d",&a) ;
           for(b=0 ; b<a ; b++)
           scanf("%d",&ara[b]) ;
           for(c=0 ; c<a-1 ; c++)
           {
               if(ara[c+1]-ara[c]>0)
               count1++ ;
               else if(ara[c+1]-ara[c]<0)
               count2++ ;
           }
           printf("Case %d: %d %d\n",i,count1,count2) ;
      }
       return 0 ;
}
