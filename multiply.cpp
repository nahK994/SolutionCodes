#include<stdio.h>
#include<string.h>

int main ()

{
      char ch1[10000] ;
      gets(ch1) ;
      char ch3[100000] ;
      long q , x1 , x , t , y , n , c=0 , n1=strlen(ch1) , a , b ;
      scanf("%ld",&x1) ;
      for(q=n1-1,x=0 ; q>=0 ; q--,x++)
           {
               y=(ch1[q]-48)*x1+c ;
               if(y>9)
               {
                  ch3[x]=(y%10)+48 ;
                  c=y/10 ;
               }
               else
               {
                   ch3[x]=y+48 ;
                   c=0 ;
               }
           }
      for( ; c!=0 ; x++)
      {
          ch3[x]=(c%10)+48 ;
          c=c/10 ;
      }
      n=strlen(ch3) ;
      for(t=n-1 ; t>=0 ; t--) printf("%c",ch3[t]) ;
      printf("\n") ;
      return 0 ;
}

