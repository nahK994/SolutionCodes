#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
#include<string.h>

using namespace std ;

struct edge
{
    long long a , b , w ;
    bool operator < (const edge& p) const
    {
        return p.w>w ;
    }
} ;

vector<edge>V ;
edge c ;
long par[1000] , N ;

long find(long n)
{
    if(par[n]==n) return n ;
    return par[n]=find(par[n]) ;
}

long MST(long n)
{
    long i , j=0 , a , b , count=0 ;
    for(i=0 ; i<=n ; i++) par[i]=i ;
    sort(V.begin(),V.end()) ;
    for(i=0 ; i<V.size() ; i++)
    {
        a=V[i].a ;
        b=V[i].b ;
        a=find(a) ;
        b=find(b) ;
        if(a!=b)
        {
            par[a]=b ;
            count=count+V[i].w ;
            j++ ;
            if(j==n-1) return count ;
        }
    }
    return count ;
}

int main()
{
    map<string,long>mp ;
    long i , j , a , b , node , edge ;
    string ch2 , ch1 ;
    while(cin>>node>>edge)
    {
        for(j=1 ; j<=node ; j++)
        {
            cin>>ch1 ;
            mp[ch1]=j ;
        }
        if(node==0 && edge==0) break ;
        for(j=1 ; j<=edge ; j++)
        {
            cin>>ch1>>ch2>>i ;
            a=mp[ch1] ;
            b=mp[ch2] ;
            c.a=a ;
            c.b=b ;
            c.w=i ;
            V.push_back(c) ;
        }
        cin>>ch1 ;
        N=mp[ch1] ;
        a=MST(node) ;
        for(i=1 ; i<=node ; i++) par[i]=find(par[i]) ;
        for(i=1 ; i<=node ; i++) if(par[N]!=par[i]) a=-1 ;
        if(a==-1) cout<<"Impossible\n" ;
        else cout<<a<<endl ;
        memset(par,0,sizeof(par)) ;
        V.clear() ;
        mp.clear() ;
    }
    return 0 ;
}
