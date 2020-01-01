#include<stdio.h>

int main ()

{
     long i , j , a , b ;
     long ara[100000] ;
     while(scanf("%ld%ld",&a,&b)!=EOF)
     {
        if(b<=1 || a<b)
        printf("Boring!\n") ;
        else
        {
        for(i=0 ; i>=0 ; i++)
        {
             ara[i]=a ;
             if(a==1)
             break ;
             else if(a%b==0)
             a=a/b ;
             else if(a%b!=0)
             break ;
        }
        if(ara[i]==1)
        {
             for(j=0 ; j<=i ; j++)
             {
                  if(j!=i)
                  printf("%ld ",ara[j]) ;
                  else printf("%ld\n",ara[j]) ;
             }
        }
        else printf("Boring!\n") ;
        }
     }
     return 0 ;
}


