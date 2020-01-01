#include<iostream>
#include<string.h>
using namespace std ;

long board[50][50] ;

long add(long row , long i)
{
    long j , sum=0 ;
    for(j=i ; j<=row ; j++)
    sum=sum+board[i][j]+board[row][j] ;
    for(j=i+1 ; j<row ; j++)
    sum=sum+board[j][i]+board[j][row] ;
    return sum ;
}

int main()
{
    long loop=1 , row , a , i , j , sum ;
    while(cin>>row && row!=0)
    {
        for(i=0 ; i<=20 ; i++)
        memset(board,0,sizeof(board)) ;
        sum=0 ;
        for(i=1 ; i<=row ; i++)
        for(j=1 ; j<=row ; j++)
        cin>>board[i][j] ;
        a=1 ;
        cout<<"Case "<<loop<<":" ;
        while(a<row)
        {
            sum=0 ;
            sum=add(row,a) ;
            cout<<" "<<sum ;
            a++ ;
            row-- ;
        }
        if(a==row) cout<<" "<<board[a][row] ;
        cout<<endl ;
        loop++ ;
    }
    return 0 ;
}
