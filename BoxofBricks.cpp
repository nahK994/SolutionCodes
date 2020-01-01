#include<stdio.h>

int main ()

{
      int n , i , j , b , c=1 , sum , avr , count , h ;
      int ara[105] ;
      while(scanf("%d",&n)!=EOF)
              {
                   if(n==0)
                   break ;
                   else
                    {
                       count=0 ;
                       sum=0 ;
                       for(i=0 ; i<n ; i++)
                       scanf("%d",&ara[i]) ;
                       for(j=0 ; j<n ; j++)
                       sum=sum+ara[j] ;
                       avr=sum/n ;
                       for(b=0 ; b<n ; b++)
                        {
                             if(ara[b]-avr>0)
                             {
                                 h=ara[b]-avr ;
                                 count=count+h ;
                             }
                        }
                       printf("Set #%d\n",c) ;
                       printf("The minimum number of moves is %d.\n\n",count) ;
                       c++ ;
                     }
              }
        return 0 ;
}
