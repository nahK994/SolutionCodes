#include<iostream>
#include<queue>
#include<stack>
#include<string.h>
#include<string>
#include<map>
#include<stdio.h>
using namespace std ;

struct EDGE
{
    long long a , w ;
    EDGE(long long u , long long v)
    {
        a=u ;
        w=v ;
    }
    bool operator < (const EDGE & p) const
    {
        return p.w<w ;
    }
} ;

long long destination , root , mini_cost[200000] , par[200000] ;
priority_queue<EDGE>Q ;
stack<long long>S ;
vector<long long>V[200000] , cost[200000] ;
map<string,long>mp ;
map<long,string>mp1 ;

void dijkstra()
{
    long long A , i , j  ;
    mini_cost[root]=0 ;
    Q.push(EDGE( root , mini_cost[root] )) ;
    while(!Q.empty())
    {
        EDGE ed=Q.top() ;
        Q.pop() ;
        A=ed.a ;
        /*cout<<":)  "<<mp1[A]<<" -> "<<mini_cost[A]<<endl ;
        char chh=getchar() ;*/
        for(i=0 ; i<V[A].size() ; i++)
        {
            j=V[A][i] ;
            if(mini_cost[j]>mini_cost[A]+cost[A][i])
            {
                mini_cost[j]=mini_cost[A]+cost[A][i] ;
                Q.push(EDGE(j,mini_cost[j])) ;
                par[j]=A ;
            }
        }
    }
    par[1]=0 ;
}

int main()
{
    long long node , edge , i , a , b , c , count ;
    string s1 , s2 ;
    while(cin>>node>>edge)
    {
        count=1 ;
        for(i=1 ; i<=node ; i++)
        {
            mini_cost[i]=9999999999999 ;
            par[i]=0 ;
        }
        for(i=1 ; i<=edge ; i++)
        {
            //cin>>a>>b>>c ;
            cin>>s1>>s2>>c ;
            if(mp[s1]==0)
            {
                mp[s1]=count ;
                mp1[count++]=s1 ;
            }
            if(mp[s2]==0)
            {
                mp[s2]=count ;
                mp1[count++]=s2 ;
            }
            a=mp[s1] ;
            b=mp[s2] ;
            V[a].push_back(b) ;
            cost[a].push_back(c) ;
            V[b].push_back(a) ;
            cost[b].push_back(c) ;
        }
        cin>>s1>>s2 ;
        root=mp[s1] ;
        destination=mp[s2] ;
        dijkstra() ;
        if(mini_cost[destination]==9999999999999)
            cout<<"Not Possible To Go\n"<<endl ;
        else
        {
            a=destination ;
            while(a!=0)
            {
                S.push(a) ;
                a=par[a] ;
               // cout<<"A"<<endl ;
            }
            while(S.size()!=1)
            {
                a=S.top() ;
                cout<<mp1[a]<<" " ;
                S.pop() ;
            }
            a=S.top() ;
            cout<<mp1[a]<<endl ;
            S.pop() ;
            cout<<"Cost = "<<mini_cost[destination]<<endl ;
        }
    }

    for(i=1 ; i<=node ; i++)
    {
        cost[i].clear() ;
        V[i].clear() ;
    }
    mp.clear() ; mp1.clear() ;
    memset(mini_cost,0,sizeof(mini_cost)) ;
    memset(par,0,sizeof(par)) ;

    return 0 ;
}

