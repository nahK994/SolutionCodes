#include<stdio.h>
#include<string.h>

int main ()

{
    char c[1000] ;
    long i=1 ;
    while(gets(c))
    {
        if(c[0]=='*') break ;
        else if(c[0]=='H') printf("Case %ld: Hajj-e-Akbar\n",i) ;
        else printf("Case %ld: Hajj-e-Asghar\n",i) ;
        i++ ;
    }
    return 0 ;
}
