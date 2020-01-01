#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
#include<string.h>
//ios_base::sync_with_stdio(false);

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
edge C ;
long par[500000] ;

long find(long n)
{
    if(par[n]==n) return n ;
    return par[n]=find(par[n]) ;
}

long MinST(long n)
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

long MaxST(long n)
{
    long i , j=0 , a , b , count=0 ;
    for(i=0 ; i<=n ; i++) par[i]=i ;
    sort(V.begin(),V.end()) ;
    for(i=V.size()-1 ; i>=0 ; i--)
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
    //ios_base::sync_with_stdio(false);
    long loop , test , i , j , a , b , c , node , edge ;
    cin>>test ;
    for(loop=1 ; loop<=test ; loop++)
    {
        cin>>node ;
        node++ ;
        while(1)
        {
            cin>>a>>b>>c ;
            if(a==0 && b==0 && c==0) break ;
            C.a=a ;
            C.b=b ;
            C.w=c ;
            V.push_back(C) ;
        }
        c=MinST(node)+MaxST(node) ;
        cout<<"Case "<<loop<<": " ;
        if(c%2!=0) cout<<c<<"/2"<<endl ;
        else cout<<c/2<<endl ;
        memset(par,0,sizeof(par)) ;
        V.clear() ;
    }
    return 0 ;
}
