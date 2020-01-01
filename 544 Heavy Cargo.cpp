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
        return p.w<w ;
    }
} ;

vector<edge>V ;
edge c ;
long par[1000] , N , root , dest ;

long find(long n)
{
    if(par[n]==n) return n ;
    return par[n]=find(par[n]) ;
}

long MST(long n)
{
    long i , a , b , count=200000 ;
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
            if(count>V[i].w) count=V[i].w ;
            if(find(root)==find(dest)) break ;
        }
    }
    return count ;
}

int main()
{
    map<string,long>mp ;
    long i , j , a , b , C , node , edge , ii=1 ;
    string ch2 , ch1 ;
    while(cin>>node>>edge)
    {
        C=1 ;
        if(node==0 && edge==0) break ;
        for(j=1 ; j<=edge ; j++)
        {
            cin>>ch1>>ch2>>i ;
            if(mp[ch1]==0) mp[ch1]=C++ ;
            if(mp[ch2]==0) mp[ch2]=C++ ;
            a=mp[ch1] ;
            b=mp[ch2] ;
            c.a=a ;
            c.b=b ;
            c.w=i ;
            V.push_back(c) ;
        }
        cin>>ch1>>ch2 ;
        root=mp[ch1] ;
        dest=mp[ch2] ;
        a=MST(node) ;
        //if(node==0) a=0 ;
        cout<<"Scenario #"<<ii<<endl ;
        cout<<a<<" tons\n\n" ;
        memset(par,0,sizeof(par)) ;
        V.clear() ;
        mp.clear() ;
        ii++ ;
    }
    return 0 ;
}

