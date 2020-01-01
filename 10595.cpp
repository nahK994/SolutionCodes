#include<iostream>
#include<queue>
using namespace std ;

#define max 1010
long ara[max][max] , path[max] ;

void ini()
{
    long i , j ;
    for(i=1 ; i<1010 ; i++)
        for(j=1 ; j<1010 ; j++)
            ara[i][j]=0 ;
    for(i=0 ; i<=1010 ; i++)
        path[i]=0 ;
}

void BFS(long Node)
{
    queue<long>Q ;
    long root=0 , a ;
    Q.push(root) ;
    while(Q.empty()==false)
    {
        root=Q.front() ;
        for(a=1 ; a<Node ; a++)
        {
            if(ara[root][a]==1)
            {
                Q.push(a) ;
                if(path[a]==0)
                    path[a]=path[root]+1 ;
                ara[root][a]=ara[a][root]=0 ;
            }
        }
        Q.pop() ;
    }
}

int main()
{
    long loop , test , node , edge , m , n , a ;
    cin >> test ;
   // cout<< endl ;
    ini() ;
    for(loop=1 ; loop<=test ; loop++)
    {
        a=1 ;
        cin >> node >> edge ;
        while(a<=edge)
        {
            cin >> m >> n ;
            ara[m][n]=ara[n][m]=1 ;
            a++ ;
        }
        BFS(node) ;
        for(a=1 ; a<node ; a++)
        {
            cout << path[a] ;
            path[a]=0 ;
           // if(loop==test && a==node-1) break ;
            cout<<endl ;
        }
        if(loop!=test) cout<<endl ;

    }
    return 0 ;
}
