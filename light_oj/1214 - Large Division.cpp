#include<stdio.h>
#include<string.h>

int main()
{
    long long i , sum , loop , test , j ;
    char ch[1000] ;
    scanf("%lld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        scanf("%s%lld",ch,&j) ;
        if(j<0) j=-1*j ;
        sum=0 ;

        if(ch[0]=='-')
            i=1 ;
        else i=0 ;

        for( ; i<strlen(ch) && sum<j ; i++)
            sum=10*sum+(ch[i]-48) ;
        for( ; i<strlen(ch) ; i++)
        {
            sum%=j ;
            sum=10*sum+(ch[i]-48) ;
        }
        sum%=j ;
        if(sum==0) printf("Case %lld: divisible\n",loop) ;
        else printf("Case %lld: not divisible\n",loop) ;
    }

    return 0 ;
}
