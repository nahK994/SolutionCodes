#include<stdio.h>
#include<string.h>
#include<stdlib.h>
long ans[110][50000] , ara[110] , n ;

long min(long a , long b)
{
    if(a<b) return a ;
    return b ;
}

long rec(long a , long left , long right)
{
    if(ans[a][left] != -1)
        return ans[a][left] ;

    if(a == n-1)
        return ans[a][left] = min( abs(left+ara[a]-right) , abs(left-right-ara[a]) ) ;

    ans[a+1][left+ara[a]] = rec(a+1 , left+ara[a] , right) ;
    ans[a+1][left] = rec(a+1 , left , right+ara[a]) ;

    return ans[a][left] = min(ans[a+1][left+ara[a]] , ans[a+1][left]) ;
}

int main()
{
    long test , a , b , c , sum ;
    char ch[500] , cc ;
    scanf("%ld",&test) ;
    char sd = getchar() ;
    while(test--)
    {
        sum=0 ;
        memset(ans , -1 , sizeof ans) ;
        gets(ch) ;
        n=0 ;
        for(a=0 ; a<strlen(ch) ; a++)
        {
            sum = 0 ;
            cc = ch[a] ;
             while(cc != ' ' && a<strlen(ch))
             {
                 sum = 10*sum+(cc-48) ;
                 cc=ch[++a] ;
             }
             ara[n++] = sum ;
        }
        /*for(a=0 ; a<n ; a++)
            printf("%ld\n",ara[a]) ;*/
        a=rec(0,0,0) ;
        if(a == 0)
        printf("YES\n") ;
        else printf("NO\n") ;
    }
}

