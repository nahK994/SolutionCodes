#include<stdio.h>

int main ()

{
    int i , j , a , b , c ;
    scanf("%d",&j) ;
    for(i=1 ; i<=j ; i++)
    {
        scanf("%d%d%d",&a,&b,&c) ;
        if(a<=20 && b<=20 && c<=20)
        printf("Case %d: good\n",i) ;
        else printf("Case %d: bad\n",i) ;
    }
    return 0 ;
}
