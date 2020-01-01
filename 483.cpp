#include<stdio.h>
#include<string.h>

//char ch[1000] ;

char strrev(char ch[1000] , long a , long b)
{
    char c ;
    long i ;
    for( ; a<b ; a++,b--)
    {
        c=ch[a] ;
        ch[a]=ch[b] ;
        ch[b]=c ;
    }
}

int main()
{
    long i , j , a , b ;
    char ch[1000] ;
    while(gets(ch))
    {
        a=0 ;
        j=strlen(ch) ;
        for(i=0 ; i<j ; i++)
        {
            if(ch[i]==32)
            {
                strrev(ch,a,i-1) ;
                a=i+1 ;
            }
        }
        strrev(ch,a,j-1) ;
        printf("%s\n",ch) ;
    }
    return 0 ;
}
