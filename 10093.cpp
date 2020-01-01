#include<stdio.h>
#include<string.h>

int main()
{
    char ch[100000] ;
    long sum , ans , max , a , i ;
    while(scanf("%s",ch)!=EOF)
    {
        sum=0 ; ans=-1 ; max=0 ;
        for (i=0 ; i<strlen(ch) ; i++)
        {
            if (ch[i]>='A' && ch[i]<='Z')
                a=ch[i]-'A'+10 ;
            else if (ch[i]>='a' && ch[i]<='z')
                a=ch[i]-'a'+36 ;
            else if (ch[i]>='0' && ch[i]<='9')
                a=ch[i]-'0' ;
            else
                continue ;
            if (a>max)
                max=a ;
            sum+=a ;
        }
        if (!max)
            max=1 ;
        for (i=max ; i<=61 ; i++)
        {
            if (!(sum%i))
            {
                ans=i+1 ;
                break ;
            }
        }
        if (ans == -1)
            printf("such number is impossible!\n") ;
        else
            printf("%ld\n",ans) ;
    }
    return 0 ;
}
