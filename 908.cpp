#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>

using namespace std ;

struct edge
{
    long a , b , w ;
    bool operator < (const edge&p) const{ return p.w>w ;}
} ;

long par[2000000] ;
edge C ;
vector<edge>V ;

long find(long n)
{
    if(par[n]==n) return n ;
    return par[n]=find(par[n]) ;
}

long MST(long n)
{
    long i , j=0 , a , b , count=0 ;
    for(i=1 ; i<=n ; i++)
        par[i]=i ;
    sort(V.begin(),V.end()) ;
    for(i=0 ; i<V.size() ; i++)
    {
        a=find(V[i].a) ;
        b=find(V[i].b) ;
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
    long N , K , M , i , j , a , b , d , c=1 ;
    while(cin>>N)
    {
        j=0 ;
        for(i=1 ; i<N ; i++)
        {
            cin>>a>>b>>d ;
            j=j+d ;
        }
        cin>>K ;
        for(i=1 ; i<=K ; i++)
        {
            cin>>a>>b>>d ;
            C.a=a ;
            C.b=b ;
            C.w=d ;
            V.push_back(C) ;
        }
        cin>>M ;
        for(i=1 ; i<=M ; i++)
        {
            cin>>a>>b>>d ;
            C.a=a ;
            C.b=b ;
            C.w=d ;
            V.push_back(C) ;
        }
        a=MST(M+K) ;
        if(c>1) cout<<endl ;
        cout<<j<<endl ;
        cout<<a<<endl ;
        V.clear() ;
        memset(par,0,sizeof(par)) ;
        c=2 ;
    }
    return 0 ;
}
