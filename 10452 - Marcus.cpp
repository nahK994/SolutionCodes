#include<stdio.h>
#include<string.h>

char ch[20][20] , q[]="@IEHOVA#" , ara[20] ;
long row , col , flag ;

void rec(long a , long x , long y)
{
    if(ch[x][y] == '#')
    {
        flag=1 ;
        return ;
    }
    ch[x][y]='0' ;
    if(x-1 >= 0 && !flag && q[a+1] == ch[x-1][y])
    {
        ara[a] = 1 ;  // up
        rec(a+1,x-1,y) ;
    }
    if(y-1 >= 0 && !flag && q[a+1] == ch[x][y-1])
    {
        ara[a] = 2 ;  // left
        rec(a+1,x,y-1) ;
    }
    if(y+1 < col && !flag && q[a+1] == ch[x][y+1])
    {
        ara[a] = 3 ;  // right
        rec(a+1,x,y+1) ;
    }
}

int main()
{
    long test , a , b , c ;
    scanf("%ld",&test) ;
    while(test--)
    {
        flag=0 ;
        memset(ara,-1,sizeof ara) ;
        scanf("%ld%ld",&row,&col) ;
        for(a=0 ;  a<row ; a++)
            scanf("%s",ch[a]) ;

        for(a=0 ; a<row ; a++)
        {
            for(b=0 ; b<col ; b++)
                if(ch[a][b] == '@')
                    break ;
            if(ch[a][b] == '@')
                break ;
        }
        rec(0,a,b) ;
        if(ara[0] == 1)
            printf("forth") ;
        else if(ara[0] == 2)
            printf("left") ;
        else
            printf("right") ;
        for(a=1 ; ara[a] != -1 ; a++)
            if(ara[a] == 1)
                printf(" forth") ;
            else if(ara[a] == 2)
                printf(" left") ;
            else
                printf(" right") ;
        printf("\n") ;
    }
}

/*
2
6 5
PST#T
BTJAS
TYCVM
YEHOF
XIBKU
N@RJB
5 4
JA#X
JVBN
XOHD
DQEM
T@IY
*/
