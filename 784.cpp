#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std ;

char board[100][100] ;
long row ;

void DFS(long i , long j)
{
    if(board[i][j]!=' '&&board[i][j]!='*')
        return ;
    board[i][j]='#' ;
    if(i>0 && j>0 && board[i-1][j-1]==' ')
        DFS(i-1,j-1) ;
    if(i>0 && board[i-1][j]==' ')
        DFS(i-1,j) ;
    if(i>0 && j+1<strlen(board[i-1]) && board[i-1][j+1]==' ')
        DFS(i-1,j+1) ;
    if(j>0 && board[i][j-1]==' ')
        DFS(i,j-1) ;
    if(j+1<strlen(board[i]) && board[i][j+1]==' ')
        DFS(i,j+1) ;
    if(j>0 && i+1<row && board[i+1][j-1]==' ')
        DFS(i+1,j-1) ;
    if(i+1<row && board[i+1][j]==' ')
        DFS(i+1,j) ;
    if(i+1<row && j+1<strlen(board[i+1]) && board[i+1][j+1]==' ')
        DFS(i+1,j+1) ;
}

int main()
{
    long test , i , j , a , m , n ;
    cin>>test ;
    char c=getchar() ;
    while(test--)
    {
        row=0 ;
        a=0 ;
        while(gets(board[row]))
        {
            if(a==0)
            {
                for(j=0 ; j<strlen(board[row]) ; j++)
                    if(board[row][j]=='*')
                    {
                        m=row ;
                        n=j ;
                        a=1 ;
                        break ;
                    }
            }
            if(board[row][0]=='_') break ;
            row++ ;
        }
        DFS(m,n) ;
        for(j=0 ; j<row+1 ; j++)
            cout<<board[j]<<endl ;

    }
    return 0 ;
}
