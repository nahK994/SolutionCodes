#include<stdio.h>
#include<stdlib.h>

int main ()

{
    long a , b , c , d , l , i , n , count=0 ;
    while(scanf("%ld%ld%ld%ld%ld",&a,&b,&c,&d,&l)!=EOF)
    {
        if(a==0 && b==0 && c==0 && d==0 && l==0) break ;
        if(d==0)
        {
            printf("0\n") ;
            continue ;
        }
        for(i=l ; i>=0 ; i--)
        {
            n=a*i*i+b*i+c ;
            n=abs(n) ;
            if(n<d) break ;
            if(n%d==0) count++ ;
        }
        printf("%ld\n",count) ;
        count=0 ;
    }
    return 0 ;
}
