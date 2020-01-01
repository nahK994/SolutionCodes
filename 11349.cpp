#include<stdio.h>
#include<string.h>
int main()
{
    long ara[200][200] , loop , test , a , b , flag , n ;
    char c , v , ch[10] ;
    scanf("%ld",&test) ;
    c=getchar() ;
    for(loop=1 ; loop<=test ; loop++)
    {
        flag=1 ;
        gets(ch) ;
        if(ch[strlen(ch)-3]=='1') n=100 ;
        else if(ch[strlen(ch)-2]>='0' && ch[strlen(ch)-2]<='9') n=10*(ch[strlen(ch)-2]-48)+ch[strlen(ch)-1]-48 ;
        else n=ch[strlen(ch)-1]-48 ;
        // printf("n = %ld\n",n) ;
        for(a=1 ; a<=n ; a++)
            for(b=1 ; b<=n ; b++)
            {
                scanf("%ld",&ara[a][b]) ;
                if(ara[a][b]<0) flag=0 ;
            }
        c=getchar() ;
        if(flag)
        {
            for(a=1 ; a<=n/2 ; a++)
                for(b=1 ; b<=n ; b++)
                    if(ara[a][b]!=ara[n+1-a][n+1-b])
                    {
                        flag=0 ;
                        break ;
                    }
            if(n%2)
                for(b=1 ; b<=n ; b++)
                    if(ara[(n/2)+1][b]!=ara[(n/2)+1][n+1-b])
                    {
                        flag=0 ;
                        break ;
                    }
        }
        if(flag) printf("Test #%ld: Symmetric.\n",loop) ;
        else printf("Test #%ld: Non-symmetric.\n",loop) ;
    }
    return 0 ;
}
