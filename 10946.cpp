#include<iostream>
#include<map>
#include<vector>
#include<string.h>
using namespace std ;

long row , coloum , count ;
char board[100][100] , ch ;
map<char,long>mp ;
vector<char>VC ;
vector<long>VL[100] ;

void DFS(long i , long j)
{
    if(board[i][j]=='.') return ;
    board[i][j]='.' ;
    count++ ;
    if(i>0 && board[i-1][j]==ch) DFS(i-1,j) ;
    if(j>0 && board[i][j-1]==ch) DFS(i,j-1) ;
    if(j+1<coloum && board[i][j+1]==ch) DFS(i,j+1) ;
    if(i+1<row && board[i+1][j]==ch) DFS(i+1,j) ;
}

int main()
{
    long loop=1 , i , j , max , n , m , i1 ;
    while(cin>>row>>coloum && row!=0 && coloum!=0)
    {
        for(i=0 ; i<row ; i++)
            cin>>board[i] ;
        for(i=0 ; i<row ; i++)
            for(j=0 ; j<coloum ; j++)
                if(board[i][j]!='.')
                {
                    count=0 ;
                    ch=board[i][j] ;
                    DFS(i,j) ;
                    if(mp[ch]==0)
                    {
                        VC.push_back(ch) ;
                        mp[ch]=1 ;
                    }
                    n=ch ;
                    VL[n].push_back(count) ;
                }
        for(i=0 ; i<VC.size()-1 ; i++)
            for(j=i+1 ; j<VC.size() ; j++)
                if(VC[i]>VC[j])
                {
                    ch=VC[i] ;
                    VC[i]=VC[j] ;
                    VC[j]=ch ;
                }
        for(n=0 ; n<VC.size() ; n++)
        {
            m=VC[n] ;
            for(i=0 ; i<VL[m].size()-1 ; i++)
                for(j=i+1 ; j<VL[m].size() ; j++)
                    if(VL[m][i]<VL[m][j])
                    {
                        i1=VL[m][i] ;
                        VL[m][i]=VL[m][j] ;
                        VL[m][j]=i1 ;
                    }
        }
        cout<<"Problem "<<loop<<":"<<endl ;
        max=1 ;
        while(VC.size()!=0)
        {
            max=0 ;
            for(i=0 ; i<VC.size() ; i++)
            {
                j=VC[i] ;
                m=VL[j][0] ;
                if(m>max)
                {
                    i1=i ;
                    n=j ;
                    ch=j ;
                    max=m ;
                }
            }
            cout<<ch<<" "<<max<<endl ;
            VL[n].erase(VL[n].begin()) ;
            if(VL[n].size()==0) VC.erase(VC.begin()+i1) ;
        }
        mp.clear() ;
        for(i=0 ; i<row ; i++)
            memset(board[i],0,sizeof(board[i])) ;
        loop++ ;
    }
    return 0 ;
}
