#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
#include<string.h>

using namespace std ;

struct edge
{
    long a , b , w ;
    bool operator < (const edge& p) const
    {
        return p.w>w ;
    }
} ;

vector<edge>V ;
edge c ;
long par[5000] , N ;

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
    long i , j , a , b , node , edge , test , d=1 , e ;
    string ch2 , ch1 ;
    cin>>test ;
    while(test--)
    {
        e=1 ;
        cin>>node>>edge ;
        for(j=1 ; j<=edge ; j++)
        {
            cin>>ch1>>ch2>>i ;
            if(mp[ch1]==0) mp[ch1]=e++ ;
            if(mp[ch2]==0) mp[ch2]=e++ ;
            a=mp[ch1] ;
            b=mp[ch2] ;
            c.a=a ;
            c.b=b ;
            c.w=i ;
            V.push_back(c) ;
        }
        a=MST(node) ;
        if(d>1) cout<<endl ;
        cout<<a<<endl ;
        memset(par,0,sizeof(par)) ;
        V.clear() ;
        mp.clear() ;
        d=2 ;
    }
    return 0 ;
}
