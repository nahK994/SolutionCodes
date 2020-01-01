#include<stdio.h>
#include<string.h>

char chr(char v)
{
    long a=v ;
    while(a!=0)
    {
        printf("%d",a%10) ;
        a=a/10 ;
    }
}

int main()
{
    long i , j , a ;
    char ch[1000] ;
    while(gets(ch))
    {
        j=strlen(ch) ;
        if(ch[0]<48 || ch[0]>57)
        {
            for( ; j>=0 ; j--)
            chr(ch[j]) ;
        }
        else
        {
            j-- ;
            for( ; j>=0 ; )
            {
                a=10*(ch[j]-48)+(ch[j-1]-48) ;
                if((a>=65 && a<=90) || (a>=97 && a<=99) || (a>=32 && a<=63))
                j-=2 ;
                else
                {
                    a=100*(ch[j]-48)+10*(ch[j-1]-48)+(ch[j-2]-48) ;
                    j-=3 ;
                }
                printf("%c",a) ;
            }
        }
        printf("\n") ;
    }
    return 0 ;
}
