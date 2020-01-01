#include<iostream>
#include<queue>
#include<string.h>

using namespace std ;

long node , edge , ara1[150][150] , ara2[150] , ara3[150] ;
queue<long>Q ;
vector<long>V[150] ;

void BFS1(long n)
{
    long i , j , a ;
    Q.push(n) ;
    while(!Q.empty())
    {
        a=Q.front() ;
        Q.pop() ;
        for(i=0 ; i<V[a].size() ; i++)
        {
            j=V[a][i] ;
            if(ara1[a][j]==1 && ara2[j]==0)
            {
                ara1[a][j]=ara1[j][a]=2 ;
                ara2[j]=ara2[a]+1 ;
                Q.push(j) ;
            }
        }
    }
}

void BFS2(long n)
{
    long i , j , a ;
    Q.push(n) ;
    while(!Q.empty())
    {
        a=Q.front() ;
        Q.pop() ;
        for(i=0 ; i<V[a].size() ; i++)
        {
            j=V[a][i] ;
            if((ara1[a][j]==2 || ara1[a][j]==1) && ara3[j]==0)
            {
                ara1[a][j]=ara1[j][a]=0 ;
                ara3[j]=ara3[a]+1 ;
                Q.push(j) ;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    long loop , test , a , b , max ,i;
    cin>>test ;
    for(loop=1 ; loop<=test ; loop++)
    {
        max=0 ;
        cin>>node>>edge ;
        for(a=0 ; a<node ; a++)
            ara2[a]=ara3[a]=0 ;
        while(edge--)
        {
            cin>>a>>b ;
            V[a].push_back(b) ;
            V[b].push_back(a) ;
            ara1[a][b]=ara1[b][a]=1 ;
        }
        cin>>a>>b ;
        BFS1(a) ;
        BFS2(b) ;
        for(a=0 ; a<node ; a++)
            if(ara2[a]+ara3[a]>max)
            {
                max=ara2[a]+ara3[a] ;
                i=a ;
            }
        cout<<"Case "<<loop<<": "<<max<<endl ;
        for(a=0 ; a<node ; a++)
        {
            memset(ara1[a],0,sizeof(ara1[a])) ;
            V[a].clear() ;
        }
        memset(ara2,0,sizeof(ara2)) ;
        memset(ara3,0,sizeof(ara3)) ;
    }
    return 0 ;
}
