#include<stdio.h>
#include<string.h>

int main()
{
    long st[20] , re[20] , rest , i , a=1 ;
    while(scanf("%ld",&st[0])!=EOF)
    {
        if(st[0]<0) break ;
        for(i=1 ; i<=12 ; i++) scanf("%ld",&st[i]) ;
        for(i=1 ; i<=12 ; i++) scanf("%ld",&re[i]) ;
        rest=0 ;
        printf("Case %ld:\n",a++) ;
        for(i=1 ; i<=12 ; i++)
        {
            if(rest+st[i-1]>=re[i])
            {
                printf("No problem! :D\n") ;
                rest=rest+st[i-1]-re[i] ;
            }
            else
            {
                printf("No problem. :(\n") ;
                rest+=st[i-1] ;
            }
        }
        memset(st,0,sizeof(st)) ;
        memset(re,0,sizeof(re)) ;
    }
    return 0 ;
}
