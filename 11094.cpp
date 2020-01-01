#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>
using namespace std ;

char board[100][100] , ch ;
long W , H , count ;

void DFS(long i , long j)
{
    if(board[i][j]==ch)
        return ;
    board[i][j]=ch ;
    count++ ;
    if(i>0 && board[i-1][j]!=ch)
        DFS(i-1,j) ;
    if(i+1<H && board[i+1][j]!=ch)
        DFS(i+1,j) ;
    if(j+1<W && board[i][j+1]!=ch)
        DFS(i,j+1) ;
    if(j>0 && board[i][j-1]!=ch)
        DFS(i,j-1) ;
    if(j==0&&board[i][W-1]!=ch)
        DFS(i,W-1) ;
    if(j==W-1&&board[i][0]!=ch)
        DFS(i,0) ;
}

int main()
{
    long a , i , j , m , n , max ;
    while(scanf("%ld%ld",&H,&W)!=EOF)
    {
        a=0 ;
        max=0 ;
        count=0 ;
        for(i=0 ; i<H ; i++)
            cin>>board[i] ;
        cin>>m>>n ;
        ch=board[m][n] ;
        for(i=0 ; i<H ; i++)
        {
            for(j=0 ; j<W ; j++)
                if(ch!=board[i][j])
                {
                    ch=board[i][j] ;
                    a=1 ;
                    break ;
                }
            if(a==1)
                break ;
        }
        DFS(m,n) ;
        count=0 ;
        for(i=0 ; i<H ; i++)
        {
            for(j=0 ; j<W ; j++)
                if(board[i][j]!=ch)
                {
                    count=0 ;
                    DFS(i,j) ;
                    if(count>max)
                        max=count ;
                }
        }
        cout<<max<<endl ;
        /*for(i=0 ; i<H ; i++)
            cout<<board[i]<<endl ;*/
        for(i=0 ; i<H ; i++)
        memset(board[i],0,sizeof(board[i])) ;
    }
    return 0 ;
}
