#include<stdio.h>
#include<string.h>

long ara[1010][1010] ;
int main()
{
    long test , a , b , c , d ;
    char ch1[1010] , ch2[1010] ;
    while(gets(ch1) && gets(ch2))
    {
        for(a=1 ; a<=strlen(ch1) ; a++)
            for(b=1 ; b<=strlen(ch2) ; b++)
                if(ch1[a-1] == ch2[b-1])
                    ara[a][b] = ara[a-1][b-1]+1 ;
                else if(ara[a][b-1] > ara[a-1][b])
                    ara[a][b] = ara[a][b-1] ;
                else
                    ara[a][b] = ara[a-1][b] ;

        printf("%ld\n",ara[strlen(ch1)][strlen(ch2)]) ;
    }
    return 0 ;
}
