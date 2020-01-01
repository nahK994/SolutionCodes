#include <stdio.h>
#include <string.h>

char ch[1000] , ch1[1000] , ans[1000] , line_color[128][1000] , color[128] ;
long V[128] , length ;

void rec(long i)
{
    long a ;
    if(i==length)
    {
        ans[i]=0 ;
        puts(ans) ;
    }
    else
    {
        for(a=0 ; a<length ; a++)
            if(!color[a] && !line_color[ch[a]][i])
            {
                line_color[ch[a]][i]=1 ; color[a]=1 ;
                ans[i]=ch[a] ;
                rec(i+1) ;
                color[a]=0 ;
            }
        for(a=0 ; a<26 ; a++)
            line_color[a+'a'][i]=line_color[a+'A'][i]=0 ;
    }
}

int main()
{
    long test , a , b , i ;
    scanf("%ld",&test) ;
    char g=getchar() ;
    while(test--)
    {
        gets(ch1) ;
        for(i=0 ; i<128 ; i++)
        {
            V[i]=0 ;
            color[i]=0 ;
        }
        for(i=0 ; i<128 ; i++)
                line_color[i][0]=0 ;
        for(i=0 ; i<strlen(ch1) ; i++)
            V[ch1[i]]++ ;
        a=0 ;
        for(i=0 ; i<26 ; i++)
            if(V[i+'A'])
            {
                while(V[i+'A'])
                {
                    ch[a++]=i+'A' ;
                    V[i+'A']-- ;
                }
                if(V[i+'a'])
                {
                    while(V[i+'a'])
                    {
                        ch[a++]=i+'a' ;
                        V[i+'a']-- ;
                    }
                }
            }
            else if(V[i+'a'])
                while(V[i+'a'])
                {
                    ch[a++]=i+'a' ;
                    V[i+'a']-- ;
                }
        ch[a]='\0' ;
        length=strlen(ch) ;
        rec(0) ;
        memset(ch1,0,sizeof(ch1)) ;
        memset(ch,0,sizeof(ch)) ;
        memset(ans,0,sizeof(ans)) ;
    }
    return 0;
}
