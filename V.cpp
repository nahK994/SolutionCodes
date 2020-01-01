#include<stdio.h>
#include<string.h>
#include<string>
#include<vector>
#include<iostream>

using namespace std ;

int main ()

{
      vector<string>fn ;
      string ch1 , ch2 ;
      char ch3[100000] ;
      ch1[0]=48 ;
      ch2[0]=49 ;
      long xx=1 , n , t , o ;
      while(xx<5000)
      {
      long q , x , y , c=0 , n1=ch1.length() , n2=ch1.length() , p ;
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
      if(xx%2!=0) ch1.copy(ch3,n1,0) ;
      else ch2.copy(ch3,n2,0) ;
      memset(ch3,0,sizeof(ch3)) ;
      if(xx%2==0) fn.push_back(ch1) ;
      else fn.push_back(ch2) ;
      xx++ ;
    }
    scanf("%ld",&o) ;
    if(o==1) printf("The Fibonacci number for 1 is 1\n") ;
    else cout<<"The Fibonacci number for "<<o<<" is "<<fn.at(o)<<"\n" ;
    return 0 ;
}

