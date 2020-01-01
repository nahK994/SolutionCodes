#include<stdio.h>
#include<string.h>

int main ()

{
    long a , b , c ;
    char ch[10000] , s  ;
    while(gets(ch))
    {
        b=strlen(ch) ;
        for(a=0 ; a<b ; a++)
        {
            s=ch[a] ;
            if(s>=97 && s<=122) printf("%c",219-s) ;
            else if(s>=65 && s<=90) printf("%c",155-s) ;
            else printf("%c",s) ;
        }
        printf("\n") ;
    }
    return 0 ;
}
