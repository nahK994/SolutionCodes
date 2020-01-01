#include<stdio.h>
#include<string.h>

int main ()

{
      long a ;
      while(scanf("%ld",&a)!=EOF)
      {
      if(a==0) break ;
      long x1=1 , t , x=0 , sum=0 , ara[10] , j , l ;
      for(j=0 ; j<10 ; j++) ara[j]=0 ;
      char ch[100000]={0} ;
      ch[0]=49 ;
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
      for(t=x-1 ; t>=0 ; t--)
      {
         l=ch[t]-48 ;
         ara[l]++ ;
      }
      printf("%ld! --\n",a) ;
      printf("   (0)") ;
      if(ara[0]>9 && ara[0]<100) printf("  %ld",ara[0]) ;
      else if(ara[0]<10) printf("   %ld",ara[0]) ;
      else printf(" %ld",ara[0]) ;
      printf("   (1)") ;
      if(ara[1]>9 && ara[1]<100) printf("  %ld",ara[1]) ;
      else if(ara[1]<10) printf("   %ld",ara[1]) ;
      else printf(" %ld",ara[1]) ;
      printf("   (2)") ;
      if(ara[2]>9 && ara[2]<100) printf("  %ld",ara[2]) ;
      else if(ara[2]<10) printf("   %ld",ara[2]) ;
      else printf(" %ld",ara[2]) ;
      printf("   (3)") ;
      if(ara[3]>9 && ara[3]<100) printf("  %ld",ara[3]) ;
      else if(ara[3]<10) printf("   %ld",ara[3]) ;
      else printf(" %ld",ara[3]) ;
      printf("   (4)") ;
      if(ara[4]>9 && ara[4]<100) printf("  %ld",ara[4]) ;
      else if(ara[4]<10) printf("   %ld",ara[4]) ;
      else printf(" %ld",ara[4]) ;
      printf("\n") ;
      printf("   (5)") ;
      if(ara[5]>9 && ara[5]<100) printf("  %ld",ara[5]) ;
      else if(ara[5]<10) printf("   %ld",ara[5]) ;
      else printf(" %ld",ara[5]) ;
      printf("   (6)") ;
      if(ara[6]>9 && ara[6]<100) printf("  %ld",ara[6]) ;
      else if(ara[6]<10) printf("   %ld",ara[6]) ;
      else printf(" %ld",ara[6]) ;
      printf("   (7)") ;
      if(ara[7]>9 && ara[7]<100) printf("  %ld",ara[7]) ;
      else if(ara[7]<10) printf("   %ld",ara[7]) ;
      else printf(" %ld",ara[7]) ;
      printf("   (8)") ;
      if(ara[8]>9 && ara[8]<100) printf("  %ld",ara[8]) ;
      else if(ara[8]<10) printf("   %ld",ara[8]) ;
      else printf(" %ld",ara[8]) ;
      printf("   (9)") ;
      if(ara[9]>9 && ara[9]<100) printf("  %ld\n",ara[9]) ;
      else if(ara[9]<10) printf("   %ld\n",ara[9]) ;
      else printf(" %ld",ara[9]) ;
     }
      return 0 ;
}
