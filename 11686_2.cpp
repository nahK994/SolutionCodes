#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
using namespace std ;

long indegree[1000010] ;
vector<long>V[1000010] , ans ;

int main()
{
    long node , edge , i , j , a , min ;
    while(cin>>node>>edge)
    {
        if(node==0 && edge==0) break ;
        for(i=1 ; i<=node ; i++)
            indegree[i]=0 ;
        for(i=1 ; i<=edge ; i++)
        {
            cin>>a>>j ;
            V[a].push_back(j) ;
            indegree[j]++ ;
        }
        do
        {
            min=999999999 ;
            for(i=1 ; i<=node ; i++)
            {
                if(min>indegree[i])
                    min=indegree[i] ;
                if(indegree[i]==0)
                {
                    ans.push_back(i) ;
                    indegree[i]=999999999 ;
                    for(j=0 ; j<V[i].size() ; j++)
                    {
                        a=V[i][j] ;
                        indegree[a]-- ;
                    }
                }
            }
        }
        while(min==0) ;
        if(min==999999999)
        {
            for(i=0 ; i<ans.size() ; i++)
                cout<<ans[i]<<endl ;
        }
        else cout<<"IMPOSSIBLE\n" ;
        memset(indegree,0,sizeof(indegree)) ;
        ans.clear() ;
        for(i=1 ; i<=node ; i++) V[i].clear() ;
    }
    return 0 ;
}
