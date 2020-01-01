#include<iostream>
#include<queue>
#include<vector>
using namespace std ;

long node , edge , indegree[110] , ara[110][110] ;
 vector<long>Q ;

void ini()
{
    for(long i=1 ; i<=node ; i++)
        indegree[i]=0 ;
    for(long i=1 ; i<=node ; i++)
        for(long j=1 ; j<=node ; j++)
            ara[i][j]=0 ;
}

int main()
{
    long i , m , n , j , a ;
    while(cin>>node && cin>>edge)
    {
        ini() ;
        if(node!=0 && edge==0)
        {
            for(i=1 ; i<node ; i++)
            cout<<i<<" " ;
            cout<<i<<endl ;
            continue ;
        }
        else if(node==0 && edge==0)
        break ;
        for(i=1 ; i<=edge ; i++)
        {
            cin>>m>>n ;
            ara[m][n]=1 ;
        }
        for(i=1 ; i<=node ; i++)
        {
            m=0 ;
            for(j=1 ; j<=node ; j++)
                if(ara[j][i]==1)
                    m++ ;
            indegree[i]=m ;
        }
        do
        {
            for(i=1 ; i<=node ; i++)
                if(indegree[i]==0)
                {
                    Q.push_back(i) ;
                    indegree[i]-- ;
                }
            for(i=0 ; i<Q.size() && Q.size()<node ; i++)
            {
                a=Q[i] ;
                for(j=1 ; j<=node ; j++)
                    if(ara[a][j]==1)
                    {
                        indegree[j]-- ;
                        ara[a][j]=0 ;
                    }
            }
        }
        while(Q.size()<node) ;
        for(i=0 ; i<Q.size()-1 ; i++)
            cout<<Q[i]<<" " ;
        cout<<Q[i]<<endl ;
        for(i=1 ; i<=node ; i++)
            Q.pop_back() ;
    }
    return 0 ;
}
