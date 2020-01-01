#include<iostream>
#include<string.h>
using namespace std ;

#define max 210
char board[max][max] ;

void DFS(long root , long path)
{
    if(board[root][path]!='1')
        return ;
    board[root][path]='2' ;
    if(board[root][path-1]!=false && path!=0)
        DFS(root,path-1) ;
    if(board[root][path+1]!=false)
        DFS(root,path+1) ;
    if(board[root+1][path+1]!=false)
        DFS(root+1,path+1) ;
    if(board[root+1][path]!=false)
        DFS(root+1,path) ;
    if(board[root+1][path-1]!=false && path!=0)
        DFS(root+1,path-1) ;
    if(board[root-1][path+1]!=false && root!=0)
        DFS(root-1,path+1) ;
    if(board[root-1][path]!=false && root!=0)
        DFS(root-1,path) ;
    if(board[root-1][path-1]!=false && path!=0 && root!=0)
        DFS(root-1,path-1) ;
    return ;
}

int main()
{
    long i , j , A , m , n=1 ;
    while(cin>>m)
    {
        A=0 ;
        for(i=0 ; i<m ; i++)
            cin>>board[i] ;
        for(i=0 ; i<m ; i++)
            for(j=0 ; j<m ; j++)
            {
                if(board[i][j]=='1')
                {
                    A++ ;
                    DFS(i,j) ;
                }
            }
       cout<<"Image number "<<n<<" contains "<<A<<" war eagles."<<endl ;
       n++ ;
    }
    return 0 ;
}
