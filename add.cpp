#include<stdio.h>
#include<string.h>

int main ()

{
    char ch1[10000] , ch2[10000] ;
    /*gets(ch1) ;
    gets(ch2) ;*/
    while(gets(ch1),gets(ch2))
    {
      char ch3[100000] ;
      long q , x , y , t , n , c=0 , n1=strlen(ch1) , n2=strlen(ch2) , p ;
      if(n1>n2)
      {
        for(q=n1-1,p=n2-1,x=0 ; q>=0 ; q--,x++)
           {
              if(p>=0)
              {
                  y=c+ch1[q]+ch2[p]-96 ;
                  p-- ;
              }
              else y=c+ch1[q]-48 ;
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
          if(c!=0) ch3[x]=c+48 ;
      }
      else if(n2>n1)
      {
        for(q=n2-1,p=n1-1,x=0 ; q>=0 ; q--,x++)
           {
              if(p>=0)
              {
                  y=c+ch2[q]+ch1[p]-96 ;
                  p-- ;
              }
              else y=c+ch2[q]-48 ;
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
          if(c!=0) ch3[x]=c+48 ;
      }
      else
      {
        for(p=n1-1,x=0 ; p>=0 ; p--,x++)
        {
            y=c+ch1[p]+ch2[p]-96 ;
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
        if(c!=0) ch3[x]=c+48 ;
      }
      n=strlen(ch3) ;
      for(t=n-1 ; t>=0 ; t--) printf("%c",ch3[t]) ;
      printf("\n") ;
    }
    return 0 ;
}
