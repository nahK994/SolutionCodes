#include<stdio.h>
#include<string.h>

int main ()

{
      long a ;
      while(scanf("%ld",&a)!=EOF)
      {
      long x1=1 , t , x=0 , sum=0 ;
      char ch[100000]={0} ;
      ch[0]=49 ;
      if(a==0)
      {
          printf("1\n") ;
          continue ;
      }
      for(x1=1 ; x1<=a ; x1++)
      {
        long q , y , c=0 , n=strlen(ch) ;
        for(q=0,x=0 ; q<n ; q++,x++)
             {
                 y=(ch[q]-48)*x1+c ;
                 if(y>9)
                 {
                    ch[x]=(y%10)+48 ;
                    c=y/10 ;
                 }
                 else
                 {
                     ch[x]=y+48 ;
                     c=0 ;
                 }
             }
        for( ; c!=0 ; x++)
        {
          ch[x]=(c%10)+48 ;
          c=c/10 ;
        }
      }
      for(t=x-1 ; t>=0 ; t--) sum=sum+ch[t]-48 ;
      printf("%ld\n",sum) ;
      }
      return 0 ;
}



