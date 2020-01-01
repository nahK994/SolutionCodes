#include<stdio.h>

int main ()

{
    int a , b , c , d , sum=0 ;
    while(scanf("%d%d%d%d",&a,&b,&c,&d)!=EOF)
    {
        if(a==0 && b==0 && c==0 && d==0) break ;
        sum=sum+2*360 ;
        if(b>=a) sum=sum+(40-b+a)*9 ;
        else sum=sum+(a-b)*9 ;
        sum=sum+360 ;
        if(c>=b) sum=sum+(c-b)*9 ;
        else sum=sum+(40+c-b)*9 ;
        if(d>=c) sum=sum+(40-d+c)*9 ;
        else sum=sum+(c-d)*9 ;
        printf("%d\n",sum) ;
        sum=0 ;
    }
    return 0 ;
}
