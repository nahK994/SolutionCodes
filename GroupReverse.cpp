#include<stdio.h>
#include<string.h>

int main ()

{
    char r ;
    long n ,  a , i , p , q , d , m ;
    while(scanf("%ld",&n)!=EOF)
    {
        if(n==0) break ;
        getchar() ;
        char c[1000] ;
        gets(c) ;
        a=strlen(c) ;
        d=a/n ;
        for(i=0 ; i<a ; i=i+d)
            {
                for(p=i,q=i+d-1 ; q>p ; p++,q--)
                {
                    r=c[p] ;
                    c[p]=c[q] ;
                    c[q]=r ;
                }
            }
        for(m=0 ; m<a ; m++) printf("%c",c[m]) ;
        printf("\n") ;

    }
    return 0 ;
}
