#include<stdio.h>
#include<string.h>

long aa(char c)
{
    if(c!='a' && c!='e' && c!='i' && c!='o' && c!='u') return 1 ;
    return 0 ;
}

int main()
{
    char ch1[100] , ch2[100] , s ;
    long i , j , a , b , test ;
    scanf("%ld",&test) ;
    while(test--)
    {
        scanf("%s%s",ch1,ch2) ;
        if(strlen(ch1)!=strlen(ch2))
        {
            printf("No\n") ;
            continue ;
        }
        a=0 ;
        for(i=0 ; i<strlen(ch1) ; i++)
        if((aa(ch1[i])==1 || aa(ch2[i])==1) && ch1[i]!=ch2[i])
        {
            a=1 ;
            break ;
        }
        if(a==0) printf("Yes\n") ;
        else printf("No\n") ;
    }
    return 0 ;
}
