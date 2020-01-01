#include<stdio.h>
#include<string.h>

int main ()

{
    long o ;
    while(scanf("%ld",&o)!=EOF)
    {
      if(o==1)
        {
            printf("The Fibonacci number for 1 is 1\n") ;
            continue ;
        }
      char ch1[100000] , ch2[100000] ,ch3[100000] ;
      ch1[0]=48 ;
      ch2[0]=49 ;
      long xx=1 , n , t ;
      while(xx<o)
      {
      long q , x , y , c=0 , n1=strlen(ch1) , n2=strlen(ch2) , p ;
      if(n1>n2)
      {
        for(q=0,p=0,x=0 ; q<n1 ; q++,x++)
           {
              if(p<n2)
              {
                  y=c+ch1[q]+ch2[p]-96 ;
                  p++ ;
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
        for(q=0,p=0,x=0 ; q<n2 ; q++,x++)
           {
              if(p<n1)
              {
                  y=c+ch2[q]+ch1[p]-96 ;
                  p++ ;
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
        for(p=0,x=0 ; p<n1 ; p++,x++)
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
      if(xx%2!=0) strcpy(ch1,ch3) ;
      else strcpy(ch2,ch3) ;
      memset(ch3,0,sizeof(ch3)) ;
      xx++ ;
      }
      if(o%2==0)
      {
          n=strlen(ch1) ;
          printf("The Fibonacci number for %ld is ",o) ;
          for(t=n-1 ; t>=0 ; t--) printf("%c",ch1[t]) ;
          printf("\n") ;
      }
      else
      {
          n=strlen(ch2) ;
          printf("The Fibonacci number for %ld is ",o) ;
          for(t=n-1 ; t>=0 ; t--) printf("%c",ch2[t]) ;
          printf("\n") ;
      }
      memset(ch1,0,sizeof(ch1));
      memset(ch2,0,sizeof(ch2));
    }
    return 0 ;
}

