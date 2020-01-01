#include<iostream>
#include<string.h>
using namespace std ;

#define max 210
char board1[max][max] , board2[max][max] ;
long m ;

void n()
{
    long i , j , a=0 ;
    for(i=0 ; i<m ; i++)
        for(j=0 ; j<m ; j++)
            if(board2[i][j]=='x' && board1[i][j]=='*')
            {
                a=1 ;
                break ;
            }
    if(a==1)
    {
        for(i=0 ; i<m ; i++)
            for(j=0 ; j<m ; j++)
                if(board1[i][j]=='*')
                    board2[i][j]=board1[i][j] ;
    }
}

void v(long i , long j)
{
    long A=0 ;
    if(board1[i][j-1]=='*' && j!=0)
        A++ ;
    if(board1[i][j+1]=='*' && j+1<m)
        A++ ;
    if(board1[i+1][j+1]=='*' && j+1<m && i+1<m)
        A++ ;
    if(board1[i+1][j]=='*' && i+1<m)
        A++ ;
    if(board1[i+1][j-1]=='*' && j!=0 && i+1<m)
        A++ ;
    if(board1[i-1][j+1]=='*' && i!=0 && j+1<m)
        A++ ;
    if(board1[i-1][j]=='*' && i!=0)
        A++ ;
    if(board1[i-1][j-1]=='*' && i!=0 && j!=0)
        A++ ;
    board2[i][j]=A+48 ;
}

int main()
{
    long i , j , loop , test ;
    cin>>test ;
   // cout<<endl ;
    for(loop=1 ; loop<=test ; loop++)
    {
        cin>>m ;
        if(loop>1) cout<<endl ;
        for(i=0 ; i<m ; i++)
            cin>>board1[i] ;
        for(i=0 ; i<m ; i++)
            cin>>board2[i] ;
        n() ;
        for(i=0 ; i<m ; i++)
        {
            for(j=0 ; j<m ; j++)
            {
                if(board2[i][j]=='x' && board1[i][j]=='.')
                    v(i,j) ;
            }
        }
        for(i=0 ; i<m ; i++)
            cout<<board2[i]<<endl ;
    }
    return 0 ;
}
