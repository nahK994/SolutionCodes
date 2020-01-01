#include<stdio.h>
#include<string.h>

int main ()

{
    char ch1[10000] , ch2[10000] ;
    gets(ch1) ;
    gets(ch2) ;
    /*while(gets(ch1),gets(ch2))
    {*/
      char ch3[100000] ;
      long q , x , y , t , n , c=0 , n1=strlen(ch1) , n2=strlen(ch2) , p , a=0 , b , d ;
      if(n1>n2) a=1 ;
      else if(n2>n1) a=2 ;
      else if(n1==n2)
      {
          for(b=n1 ; b>=0 ; b--)
          if(ch1[b]>ch2[b])
          {
              a=1 ;
              break ;
          }
          else if(ch1[b]<ch2[b])
          {
              a=2 ;
              break ;
          }
      }
      if(a==1)
      {
        for(q=n1-1,p=n2-1,x=0 ; q>=0 ; q--,p--,x++)
           {
              if(ch1[q]-(ch2[p]+c)>=0 && p>=0)
              {
                  y=ch1[q]-(ch2[p]+c) ;
                  c=0 ;
              }
              else if(ch1[q]-(ch2[p]+c)<0 && p>=0)
              {
                  y=10+ch1[q]-(ch2[p]+c) ;
                  c=1 ;
              }
              else if(ch1[q]-c-48>=0 && p<0)
              {
                  y=ch1[q]-c-48 ;
                  c=1 ;
              }
              else if(ch1[q]-c-48<0 && p<0)
              {
                  y=10+(ch1[q]-48)-c ;
                  c=1 ;
              }
              ch3[x]=(y%10)+48 ;
           }
      }
      else if(a==2)
      {
           for(q=n2-1,p=n1-1,x=0 ; q>=0 ; q--,p--,x++)
           {
              if(ch2[q]-(ch1[p]+c)>=0 && p>=0)
              {
                  y=ch2[q]-(ch1[p]+c) ;
                  c=0 ;
              }
              else if(ch2[q]-(ch1[p]+c)<0 && p>=0)
              {
                  y=10+ch2[q]-(ch1[p]+c) ;
                  c=1 ;
              }
              else if(ch2[q]-c-48>=0 && p<0)
              {
                  y=ch2[q]-c-48 ;
                  c=1 ;
              }
              else if(ch2[q]-c-48<0 && p<0)
              {
                  y=10+(ch2[q]-48)-c ;
                  c=1 ;
              }
              ch3[x]=(y%10)+48 ;
           }
      }
      else
      {
         ch3[0]=48 ;
      }
      n=strlen(ch3) ;
      d=n-1 ;
      while(ch3[d]==48)
      d-- ;
      for(t=d ; t>=0 ; t--) printf("%c",ch3[t]) ;
      printf("\n") ;
      return 0 ;
}

