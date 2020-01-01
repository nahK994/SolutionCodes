#include<stdio.h>

int main ()

{
    long n , i , a , b , x , y , j , ara[100000] ;
    while(scanf("%ld",&n)!=EOF)
    {
         if(n==0) break ;
         scanf("%ld%ld",&x,&y) ;
         for(i=0 ; i<2*n ; i=i+2)
         {
             scanf("%ld%ld",&ara[i],&ara[i+1]) ;
             a=ara[i]-x ;
             b=ara[i+1]-y ;
             if(a==0 || b==0) printf("divisa\n") ;
             else if(a>0 && b>0) printf("NE\n") ;
             else if(a<0 && b<0) printf("SO\n") ;
             else if(a>0 && b<0) printf("SE\n") ;
             else printf("NO\n") ;
         }
    }
    return 0 ;
}
