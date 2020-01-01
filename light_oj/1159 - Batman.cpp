#include<stdio.h>
#include<string.h>

long max(long a , long b , long c)
{
    if(a>b)
        if(a>c)
            return a ;
        else return c ;
    else if(b>c)
        return b ;
    else return c ;
}

int main()
{
    long loop , test , a , b , c , ara[60][60][60] ;
    char ch1[60] , ch2[60] , ch3[60] ;
    scanf("%ld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        scanf("%s %s %s",ch1,ch2,ch3) ;
        memset(ara,0,sizeof(ara)) ;
        for(a=1 ; a<=strlen(ch1) ; a++)
            for(b=1 ; b<=strlen(ch2) ; b++)
                for(c=1 ; c<=strlen(ch3) ; c++)
                    if(ch1[a-1]==ch2[b-1] && ch2[b-1]==ch3[c-1])
                        ara[a][b][c] = 1 + ara[a-1][b-1][c-1] ;
                    else ara[a][b][c] = max(ara[a][b][c-1] , ara[a][b-1][c] , ara[a-1][b][c]) ;

          printf("Case %ld: %ld\n",loop,ara[strlen(ch1)][strlen(ch2)][strlen(ch3)]) ;
    }
    return 0 ;
}
