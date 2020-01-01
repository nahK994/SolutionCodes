#include<iostream>
#include<queue>

using namespace std ;

#define max 500
long ara[max][max] , path[max] , visited[max] , nod , n ;

void ini(long nod)
{
    long i , j ;
     for(i=0 ; i<nod ; i++)
         for(j=0 ; j<nod ; j++)
             ara[i][j]=0 ;
    for(i=0 ; i<nod ; i++)
        visited[i]=0 ;
}

bool BFS()
{
    queue<long>Q ;
    long a , root=n ;
    Q.push(root) ;
    visited[root]=2 ;
    while(!Q.empty())
    {
        root=Q.front() ;
        for(a=0 ; a<nod ; a++)
        {
            if(ara[root][a]==1 && visited[a]==0)
            {
                Q.push(a) ;
                if(visited[root]==2)
                    visited[a]=3 ;
                else
                    visited[a]=2 ;
            }
        }
        for(a=0 ; a<nod ; a++)
            if(ara[root][a]==1 && visited[root]==visited[a])
                return false ;
        Q.pop() ;
    }
    return true ;
}

int main()
{
    long loop , test , edge , m , a , root , des ;
    bool cheak ;
    while(cin>>nod && nod!=0)
    {
        cin>>edge ;
        a=1 ;
        ini(nod) ;
        while(a<=edge)
        {
            cin >> m >> n ;
            ara[m][n]=ara[n][m]=1 ;
            a++ ;
        }
        cheak=BFS() ;
        if(cheak==true)
            cout << "BICOLORABLE." << endl ;
        else
            cout << "NOT BICOLORABLE." << endl ;
    }
    return 0 ;
}

