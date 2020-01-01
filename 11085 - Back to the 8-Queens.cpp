#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string>
#include <iostream>
#include <fstream>
using namespace std ;
char ch[10][10] , q[10][10] ;
long col[100] , count1 , max1 ;
struct HiHi
{
    long a , b;
    HiHi()
    {
        a=-1;
        b=-1;
    };
} hihi[100];

bool diagonal_cheak(long i , long j)
{
    for(long a=0 ; a<i ; a++)
        if(hihi[a].a != -1 && abs(i-hihi[a].a) == abs(j-hihi[a].b))
            return false ;
    return true ;
}

void rec(long Row)
{
    if(Row == 8)
    {
        count1=0 ;
        for(long i=0 ; i<8 ; i++)
            for(long j=0 ; j<8 ; j++)
                if(ch[i][j] != 'q' && q[i][j] == 'q')
                    count1++ ;
         if(max1>count1)
            max1=count1 ;
        return ;
    }

    for(long a=0 ; a<8 ; a++)
        if(col[a]==0 && diagonal_cheak(Row,a))
        {
            col[a]=1 ;
            ch[Row][a] = 'q' ;
            hihi[Row].a=Row ;
            hihi[Row].b=a ;
            rec(Row+1) ;
            ch[Row][a] = '.' ;
            col[a]=0 ;
        }
}

int main()
{
    long loop=0 , test , i , j , ara[10] ;
    memset(ch , 0 , sizeof ch) ;
    while(scanf("%ld%ld%ld%ld%ld%ld%ld%ld",&ara[1],&ara[2],&ara[3],&ara[4],&ara[5],&ara[6],&ara[7],&ara[8]) != EOF)
    {
        max1=10 ;
        memset(col , 0 , sizeof col) ;
        for(i=0 ; i<8 ; i++)
            for(j=0 ; j<8 ; j++)
                ch[i][j]=q[i][j]='.' ;
        for(i=1 ; i<=8 ; i++)
            q[ara[i]-1][i-1] = 'q' ;
        rec(0) ;
        printf("Case %ld: %ld\n",++loop,max1) ;
    }
}
