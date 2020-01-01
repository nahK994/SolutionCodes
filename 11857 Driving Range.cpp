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
long par[500000] , N ;

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
            if(count<V[i].w) count=V[i].w ;
            //count=count+V[i].w ;
            j++ ;
            if(j==n-1) return count ;
        }
    }
    return count ;
}

int main()
{
    long i , j , a , b , node , edge ;
    //cin>>test ;
    while(cin>>node>>edge)
    {
        for(j=1 ; j<=edge ; j++)
        {
            cin>>a>>b>>i ;
            c.a=a ;
            c.b=b ;
            c.w=i ;
            V.push_back(c) ;
        }
        if(node==0 && edge==0) break ;
        a=MST(node) ;
        b=0 ;
        for(i=0 ; i<node ; i++)
        if(i==find(i)) b++ ;
        if(b==1) cout<<a<<endl ;
        else cout<<"IMPOSSIBLE\n" ;
        memset(par,0,sizeof(par)) ;
        V.clear() ;
    }
    return 0 ;
}
