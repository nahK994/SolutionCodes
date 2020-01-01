#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std ;

char board[100][100] , contour , marking_ch ;
long row ;

void DFS(long i , long j)
{
    if(board[i][j]==contour)
        return ;
    board[i][j]=marking_ch ;
    if(i>0 && board[i-1][j]==' ')
        DFS(i-1,j) ;
    if(j>0 && board[i][j-1]==' ')
        DFS(i,j-1) ;
    if(j+1<strlen(board[i]) && board[i][j+1]==' ')
        DFS(i,j+1) ;
    if(i+1<row && board[i+1][j]==' ')
        DFS(i+1,j) ;
}

int main()
{
    long i , j , a , m , n ;
    char ch[100] ;
    while(gets(ch))
    {
        strcpy(board[0],ch) ;
        row=1 ;
        a=0 ;
        while(gets(board[row]))
        {
            if(a==0)
            {
                for(j=0 ; j<strlen(board[row]) ; j++)
                    if(board[row][j]!=' ')
                    {
                        contour=board[row][j] ;
                        a=1 ;
                        break ;
                    }
            }
            if(board[row][0]=='_') break ;
            row++ ;
        }
        for(i=0 ; i<row ; i++)
        for(j=0 ; j<strlen(board[i]) ; j++)
        if(board[i][j]!=' '&&board[i][j]!=contour)
        {
            marking_ch=board[i][j] ;
            DFS(i,j) ;
        }
        for(j=0 ; j<row+1 ; j++)
            cout<<board[j]<<endl ;

    }
    return 0 ;
}

