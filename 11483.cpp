#include <cstdio>
#include<string.h>
int main()
{
    long n , a , i , j , loop=1 ;
    char ch[1000] , c ;
    while(scanf("%ld",&n)!=EOF)
    {
        c=getchar() ;
        if(n==0) break ;
        printf("Case %ld:\n",loop++) ;
        printf("#include<string.h>\n") ;
        printf("#include<stdio.h>\n") ;
        printf("int main()\n{\n") ;
        while(n--)
        {
            gets(ch) ;
            printf("printf\(\"") ;
            for(i=0 ; i<strlen(ch) ; i++)
            if(ch[i]=='\\') printf("\\\\") ;
            else if(ch[i]=='\"') printf("\\\"") ;
            else printf("%c",ch[i]) ;
            printf("\\n\"\);\n") ;
        }
        printf("printf\(\"\\n\"\);\n") ;
        printf("return 0;\n\}\n") ;
    }
    return 0 ;
}
