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
    long i , j , a , b , node , edge , loop , test ;
    cin>>test ;
    string ch2 , ch1 ;
    for(loop=1 ; loop<=test ; loop++)
    {
        cin>>edge ;
        node=1 ;
       // if(node==0 && edge==0) break ;
        for(j=1 ; j<=edge ; j++)
        {
            cin>>ch1>>ch2>>i ;
            if(mp[ch1]==0) mp[ch1]=node++ ;
            if(mp[ch2]==0) mp[ch2]=node++ ;
            c.a=mp[ch1] ;
            c.b=mp[ch2] ;
            c.w=i ;
            V.push_back(c) ;
        }
        node-- ;
        b=0 ;
       /* cin>>ch1 ;
        N=mp[ch1] ;*/
        a=MST(node) ;
        for(i=1 ; i<=node ; i++) par[i]=find(par[i]) ;
        for(i=1 ; i<=node ; i++) if(i==par[i]) b++ ;
        if(b>1) cout<<"Case "<<loop<<": Impossible"<<endl ;
        else cout<<"Case "<<loop<<": "<<a<<endl ;
        memset(par,0,sizeof(par)) ;
        V.clear() ;
        mp.clear() ;
    }
    return 0 ;
}

