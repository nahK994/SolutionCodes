#include<stdio.h>
#include<string.h>

int main ()

{
      long a ;
      while(scanf("%ld",&a)!=EOF)
      {
      long y=1 , b ;
      if(a==0)
      {
          printf("1 -> 1\n") ;
          continue ;
      }
      else
      {
          for(b=1 ; b<=a ; b++)
          {
             y=y*b ;
             while(y%10==0) y=y/10 ;
             y=y%100000 ;
          }
          y=y%10 ;
      }
      if(a<10) printf("    %ld -> %ld\n",a,y) ;
      else if(a<100) printf("   %ld -> %ld\n",a,y) ;
      else if(a<1000) printf("  %ld -> %ld\n",a,y) ;
      else if(a<10000) printf(" %ld -> %ld\n",a,y) ;
      else printf("%ld -> %ld\n",a,y) ;
      }
      return 0 ;
}



