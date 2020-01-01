#include<stdio.h>
#include<string.h>
int main()
{
    char ch[1000] ;
    long long i , j , sum , c , a , b ;
    while(gets(ch))
    {
        if(ch[0]=='-') break ;
        j=strlen(ch) ;
        sum=0 ;
        c=1 ;
        if(ch[0]=='0' && ch[1]=='x')
        {
            for(j=j-1 ; j>1 ; j--)
            {
                if(ch[j]>=48 && ch[j]<=57) sum=sum+(ch[j]-48)*c ;
                else sum=sum+(ch[j]-55)*c ;
                c=16*c ;
            }
            printf("%lld\n",sum) ;
        }
        else
        {
            if(ch[0]=='0')
            {
                printf("0x0\n") ;
                continue ;
            }
            b=0 ;
            for(j=j-1 ; j>=0 ; j--)
            {
                sum=sum+c*(ch[j]-48) ;
                c=c*10 ;
            }
            printf("0x") ;
            while(sum!=0)
            {
                a=sum%16 ;
                if(a<=9) ch[b]=a+48 ;
                else ch[b]=65+(a-10) ;
                sum=sum/16 ;
                b++ ;
            }
            b-- ;
            for( ; b>=0 ; b--)
            {
                printf("%c",ch[b]) ;
            }
            printf("\n") ;
        }
    }
    return 0 ;
}
