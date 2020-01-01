#include<stdio.h>
#include<iostream>
using namespace std ;

char board[200][200] ;
long n ;

void DFS(long i , long j)
{
    if(board[i][j]=='.') return ;
    board[i][j]='.' ;
    if(i>0 && board[i-1][j]!='.') DFS(i-1,j) ;
    if(i+1<n && board[i+1][j]!='.') DFS(i+1,j) ;
    if(j>0 && board[i][j-1]!='.') DFS(i,j-1) ;
    if(j+1<n && board[i][j+1]!='.') DFS(i,j+1) ;
}

int main()
{
    long i , j , count , loop , test ;
    cin>>test ;
    for(loop=1 ; loop<=test ; loop++)
    {
        count=0 ;
        cin>>n ;
        for(i=0 ; i<n ; i++)
            cin>>board[i] ;
        for(i=0 ; i<n ; i++)
            for(j=0 ; j<n ; j++)
                if(board[i][j]=='x')
                {
                    count++ ;
                    DFS(i,j) ;
                }
        cout<<"Case "<<loop<<": "<<count<<endl ;
    }
    return 0 ;
}
