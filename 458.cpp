#include<stdio.h>
#include<string.h>

int main()

{
    char ch[10000] ;
    long a , b , c ;
    while(gets(ch))
    {
        for(b=0 ; b<strlen(ch) ; b++)
        printf("%c",ch[b]-7) ;
        printf("\n") ;
    }
    return 0 ;
}
