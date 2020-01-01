#include<iostream>
#include<string.h>
using namespace std ;

#define max 210
char board[max][max] ;

void DFS(long root , long path)
{
    if(board[root][path]=='w' || board[root][path]=='1')
        return ;
    board[root][path]='1' ;
    /* for(v=0 ; v<2 ; v++)
     {
        // if(board[root][path-v]!=false)
         if(board[root+1][path+v]!=false)
             DFS(root+1,path+v) ;
     }*/
    if(board[root][path-1]!=false)
        DFS(root,path-1) ;
    if(board[root][path+1]!=false)
        DFS(root,path+1) ;
    if(board[root+1][path+1]!=false)
        DFS(root+1,path+1) ;
    if(board[root+1][path]!=false)
        DFS(root+1,path) ;
    return ;
}

int main()
{
    long a , i , Path , N , A=1 , b ;
    char ch[210] ;
    while(cin>>N && N!=0)
    {
        b=0 ;
        a=0 ;
        for(i=0 ; i<N ; i++)
            cin>>board[i] ;
        for(Path=0 ; Path<N ; Path++)
            DFS(0,Path) ;
        for(i=0 ; i<N ; i++)
            if(board[N-1][i]=='1')
            {
                a=1 ;
                break ;
            }
            /*for(i=0 ; i<N ; i++)
            cout<<board[i]<<endl ;*/
        if(a==1)
            cout << A << " " << "B" << endl ;
        else
            cout << A << " " << "W" << endl ;
        A++ ;
    }
    return 0 ;
}
