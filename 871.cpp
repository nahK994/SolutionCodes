#include<stdio.h>
#include<string.h>
#include<iostream>

//#define read_ freopen("input.txt","r",stdin);
//#define write_ freopen("output.txt","w",stdout);

using namespace std ;

long row , count ;
char ch[100][100] ;

void DFS(long i , long j)
{
    if(ch[i][j]!='1')
        return ;
    count++ ;
    ch[i][j]='2' ;
    if(i>0 && j>0 && ch[i-1][j-1]=='1')
            DFS(i-1,j-1) ;
    if(i>0 && ch[i-1][j]=='1')
            DFS(i-1,j) ;
    if(i>0 && j+1<strlen(ch[i-1]) && ch[i-1][j+1]=='1')
             DFS(i-1,j+1) ;
    if(j>0 && ch[i][j-1]=='1')
            DFS(i,j-1) ;
    if(j+1<strlen(ch[i]) && ch[i][j+1]=='1')
            DFS(i,j+1) ;
    if(j>0 && i+1<row && ch[i+1][j-1]=='1')
            DFS(i+1,j-1) ;
    if(i+1<row && ch[i+1][j]=='1')
            DFS(i+1,j) ;
    if(i+1<row && j+1<strlen(ch[i+1]) && ch[i+1][j+1]=='1')
            DFS(i+1,j+1) ;
}

int main()
{
//    read_;
//    write_;
    char ch1[100] ;
    long test , j , sum , i ;
    cin>>test ;
    char c=getchar() ;
    c=getchar() ;
    while(test--)
    {
        sum=0 ;
        row=0;
        while(gets(ch1))
        {
            if(strlen(ch1)==0) break ;
            strcpy(ch[row],ch1) ;
            row++;
        }
        for(i=0 ; i<row ; i++)
        {
            count=0 ;
            for(j=0 ; j<strlen(ch[i]) ; j++)
            {
                if(ch[i][j]=='1')
                    DFS(i,j) ;
                if(count>sum)
                    sum=count ;
                    count=0 ;
            }
        }
        if(test!=0) cout<<sum<<endl<<endl ;
        else cout<<sum<<endl ;
        for(i=0 ; i<row ; i++)
        memset(ch[i],0,sizeof(ch[i])) ;
    }
    return 0 ;
}
