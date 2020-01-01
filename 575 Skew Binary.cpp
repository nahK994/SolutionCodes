#include<stdio.h>
#include<string.h>

int main ()

{
    char p[100] ;
    while(gets(p))
    {
       long c=strlen(p)-1 ;
       if(c==0 && p[c]==48) break ;
       long sum=0 , product=1 ;
       while(c>=0)
       {
           product=product*2 ;
           sum=sum+(p[c]-48)*(product-1) ;
           c-- ;
       }
       printf("%ld\n",sum) ;
       p[100]={0} ;
    }
    return 0 ;
}
