#include<stdio.h>
#include<string.h>

int main()
{
    long i=0 , j ;
    char ch[1000] , c1=39 , c2=96 ;   // ` = 96 r ' = 39
    while(gets(ch))
    {
        j=0 ;
        while(j<strlen(ch))
        {
            if(ch[j]==34 && i%2==0)
            {
                printf("%c%c",c2,c2) ;
                i=1 ;
            }
            else if(ch[j]==34 && i%2!=0)
            {
                 printf("%c%c",c1,c1) ;
                i=0 ;
            }
            else printf("%c",ch[j]) ;
            j++ ;
        }
        printf("\n") ;
    }
    return 0 ;
}
