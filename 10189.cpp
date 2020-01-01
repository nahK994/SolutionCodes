#include<iostream>
#include<string.h>
using namespace std ;

#define max 210
char board[max][max] ;

int main()
{
    int i , j , A , m , n , B=1 ;
    while(cin>>m && cin>>n && m!=0 && n!=0)
    {
       // board[0][0]='\0' ;
        if(B!=1)
            cout<<endl ;
        for(i=0 ; i<m ; i++)
            cin>>board[i] ;
        cout<<"Field #"<<B<<":"<<endl ;
        for(i=0 ; i<m ; i++)
        {
            for(j=0 ; j<n ; j++)
            {
                A=0 ;
                if(board[i][j]=='.')
                {
                    if(board[i][j-1]=='*' && j!=0)
                        {
                            A++ ;
                         //   cout<<"1"<<endl ;
                        }
                    if(board[i][j+1]=='*' && j+1<n)
                        {
                            A++ ;
                          //  cout<<"2"<<endl ;
                        }
                    if(board[i+1][j+1]=='*' && j+1<n && i+1<m)
                         {
                            A++ ;
                         //   cout<<"3"<<endl ;
                        }
                    if(board[i+1][j]=='*' && i+1<m)
                         {
                            A++ ;
                          //  cout<<"4"<<endl ;
                        }
                    if(board[i+1][j-1]=='*' && j!=0 && i+1<m)
                         {
                            A++ ;
                        //    cout<<"5"<<endl ;
                        }
                    if(board[i-1][j+1]=='*' && i!=0 && j+1<n)
                        {
                            A++ ;
                         //   cout<<"6"<<endl ;
                        }
                    if(board[i-1][j]=='*' && i!=0)
                         {
                            A++ ;
                          //  cout<<"7"<<endl ;
                        }
                    if(board[i-1][j-1]=='*' && i!=0 && j!=0)
                        {
                            A++ ;
                          //  cout<<"8"<<endl ;
                        }
                    board[i][j]=A+48 ;
                }
            }
            cout<<board[i]<<endl ;
        }
        //cout<<endl ;
        B++ ;
    }
    return 0 ;
}
/*

1 1
.
Field #1:
0
1 1
// newline
.
Field #2:
0
0 0
// newline by default ( we must not print an extra new line here same as the newline before )
Process returned 0
*/
