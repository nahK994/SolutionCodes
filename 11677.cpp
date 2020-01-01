#include<stdio.h>

int main()
{
    long h1 , m1 , h2 , m2 , a ;
    while(scanf("%ld%ld%ld%ld",&h1,&m1,&h2,&m2)!=EOF)
    {
        if(h1==0 && m1==0 && h2==0 && m2==0)
        break ;
        a=(h2*60+m2)-(h1*60+m1) ;
        if(a<0) a=24*60+a ;
        printf("%ld\n",a) ;
    }
    return 0 ;
}
