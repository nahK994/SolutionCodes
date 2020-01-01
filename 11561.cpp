#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>
using namespace std ;

long count , W , H ;
char board[1000][1000] ;

void DFS(long i , long j)
{
   if(board[i][j]=='#')
   return ;
   if(board[i][j]=='G')
   count++ ;
   board[i][j]='#' ;
   if((j>0 && board[i][j-1]=='T') || (j+1<W && board[i][j+1]=='T') || (i>0 && board[i-1][j]=='T') || (i+1<H && board[i+1][j]=='T'))
   return ;
   if(j>0 && board[i][j-1]!='#')
   DFS(i,j-1) ;
   if(j+1<W && board[i][j+1]!='#')
   DFS(i,j+1) ;
   if(i>0 && board[i-1][j]!='#')
   DFS(i-1,j) ;
   if(i+1<H && board[i+1][j]!='#')
   DFS(i+1,j) ;
}

int main()
{
    long i , j , a , b ;
    while(cin>>W>>H)
    {
        count=0 ;
        for(i=0 ; i<H ; i++)
        {
            cin>>board[i] ;
            for(j=0 ; j<W ; j++)
            if(board[i][j]=='P')
            {
                a=i ;
                b=j ;
            }
        }
        DFS(a,b) ;
        cout<<count<<endl ;
    }
    return 0 ;
}
