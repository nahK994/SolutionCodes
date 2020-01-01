#include<stdio.h>

int main()
{
    long a , b , c , d ;
    while(scanf("%ld%ld%ld%ld",&a,&b,&c,&d)!=EOF)
    {
         if(a==0 && b==0 && c==0 && d==0)
         break ;
         else if(a==c && b==d) printf("0\n") ;
         else if(a-c-b+d==0 || a-c+b-d==0 || a==c || b==d) printf("1\n") ;
         else printf("2\n") ;
    }
    return 0 ;
}
