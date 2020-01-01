#include<stdio.h>

int main()
{
    double H , U , D , F , a , b , c ;
    long count ;
    while(scanf("%lf%lf%lf%lf",&H,&U,&D,&F)!=EOF)
    {
      if(H==0) break ; count=a=0 ;
      F=F*U/100;
      while(1)
      {
          count++ ;
          if(U>0) a+=U ;
          U-=F ;
          if(a>H) break ;
          a-=D ;
          if(a<0) break ;
      }
      if(a>0) printf("success on day %ld\n",count) ;
      else printf("failure on day %ld\n",count) ;
    }
    return 0 ;
}
