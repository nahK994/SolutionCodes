#include<iostream>
#include<string.h>
using namespace std ;

#define max 210
char board[max][max] ;
long m , n ;

void DFS(long root , long path)
{
    if(board[root][path]!='@')
        return ;
    board[root][path]='*' ;
    if(path>0 && board[root][path-1]=='@')
        DFS(root,path-1) ;
    if(path+1<n && board[root][path+1]=='@')
        DFS(root,path+1) ;
    if(root+1<m && path+1<n && board[root+1][path+1]=='@')
        DFS(root+1,path+1) ;
    if(root+1<m && board[root+1][path]=='@')
        DFS(root+1,path) ;
    if(root+1<m && path>0 && board[root+1][path-1]=='@')
        DFS(root+1,path-1) ;
    if(root>0 && path+1<n && board[root-1][path+1]=='@')
        DFS(root-1,path+1) ;
    if(root>0 && board[root-1][path]=='@')
        DFS(root-1,path) ;
    if(root>0 && path>0 && board[root-1][path-1]=='@')
        DFS(root-1,path-1) ;
}

int main()
{
    long i , j , A ;
    while(cin>>m && cin>>n && m!=0 && n!=0)
    {
        A=0 ;
        for(i=0 ; i<m ; i++)
            cin>>board[i] ;
        for(i=0 ; i<m ; i++)
            for(j=0 ; j<n ; j++)
            {
                if(board[i][j]=='@')
                {
                    A++ ;
                    DFS(i,j) ;
                }
            }
        cout<<A<<endl ;
    }
    return 0 ;
}
