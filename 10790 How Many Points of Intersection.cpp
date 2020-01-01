#include<stdio.h>

long long p(long a , long b)

{
    a=(double)a*(a-1)*0.5 ;
    b=(double)b*(b-1)*0.5 ;
    return a*b ;
}

int main ()

{
    long a , b ;
    long long c , i=1 ;
    while(scanf("%ld%ld",&a,&b)!=EOF)
    {
        if(a==0 && b==0) break ;
        c=p(a,b) ;
        printf("Case %lld: %lld\n",i,c) ;
        i++ ;
    }
    return 0 ;
}
