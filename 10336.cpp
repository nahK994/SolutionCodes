#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std ;

char board[100][100] , ch ;
long W , H ;

void DFS(long i , long j)
{
    if(board[i][j]=='1')
        return ;
    board[i][j]='1' ;
    if(i>0 && board[i-1][j]==ch)
        DFS(i-1,j) ;
    if(j>0 && board[i][j-1]==ch)
        DFS(i,j-1) ;
    if(j+1<W && board[i][j+1]==ch)
        DFS(i,j+1) ;
    if(i+1<H && board[i+1][j]==ch)
        DFS(i+1,j) ;
}

int main()
{
    long loop , test , i , j , ara[30] , max , a ;
    for(i=0 ; i<26 ; i++)
        ara[i]=0 ;
    cin>>test ;
    for(loop=1 ; loop<=test ; loop++)
    {
        cin>>H>>W ;
        for(i=0 ; i<H ; i++)
            cin>>board[i] ;
        cout<<"World #"<<loop<<endl ;
        for(i=0 ; i<H ; i++)
        {
            for(j=0 ; j<W ; j++)
            {
                if(board[i][j]!='1')
                {
                    ch=board[i][j] ;
                    //cout<<ch<<endl ;
                    DFS(i,j) ;
                    ara[ch-97]++ ;
                }
            }
        }
        for(i=0 ; i<26 ; i++)
        {
            max=0 ;
            for(j=0 ; j<26 ; j++)
            {
                if(ara[j]>max)
                {
                    max=ara[j] ;
                    a=j ;
                }
            }
            if(max==0)
                break ;
            printf("%c: %ld\n",a+97,max) ;
            ara[a]=0 ;
        }
    }
    return 0 ;
}


