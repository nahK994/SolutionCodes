#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<stack>
using namespace std ;

vector<long>v[1000] ;
map<string,long>mp ;
map<long,string>mp1 ;
stack<long>st ;
queue<long>Q ;
long root , dest , visited[1000] ;

void BFS()
{
    Q.push(root) ;
    visited[root]=-1 ;
    long a , i , b=0 , j ;
    while(!Q.empty() && b==0)
    {
        a=Q.front() ;
        Q.pop() ;
        for(i=0 ; i<v[a].size() ; i++)
        {
            j=v[a][i] ;
            if(visited[j]==0)
            {
                Q.push(j) ;
                visited[j]=a ;
            }
            if(j==dest)
            {
                b=1 ;
                break ;
            }
        }
    }
    visited[root]=0 ;
    while(!Q.empty())
        Q.pop() ;
}

int main()
{
    long a , i , j=1 , n , n1 , l , b , test ;
    string ch1 , ch2 ;
    cin>>test ;
    while(test)
    {
        cin>>n>>n1 ;
        i=1 ;
        while(n)
        {
            cin>>ch1 ;
            if(mp[ch1]==0)
            {
                mp[ch1]=i ;
                mp1[i]=ch1 ;
                i++ ;
            }
            cin>>ch2 ;
            if(mp[ch2]==0)
            {
                mp[ch2]=i ;
                mp1[i]=ch2 ;
                i++ ;
            }
            a=mp[ch1] ;
            b=mp[ch2] ;
            v[a].push_back(b) ;
            v[b].push_back(a) ;
            n-- ;
        }
        if(j>1) cout<<endl ;
            j=2 ;
        while(n1)
        {
            for(a=0 ; a<=i ; a++)
                visited[a]=0 ;
            cin>>ch1>>ch2 ;
            root=mp[ch1] ;
            dest=mp[ch2] ;
            BFS() ;
            a=dest ;
            while(a!=root)
            {
                st.push(a) ;
                a=visited[a] ;
            }
            st.push(a) ;
            while(st.size()!=0)
            {
                a=st.top() ;
                ch1=mp1[a] ;
                cout<<ch1[0] ;
                st.pop() ;
            }
            cout<<endl ;
            n1-- ;
        }
        for(a=1 ; a<=i ; a++)
            v[a].clear() ;
        mp.clear() ;
        mp1.clear() ;
        memset(visited,0,sizeof(visited)) ;
        test-- ;
    }
    return 0 ;
}

