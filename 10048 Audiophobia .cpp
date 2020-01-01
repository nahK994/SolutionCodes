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
long par[1000] , N , root , dest ;

long find(long n)
{
    if(par[n]==n) return n ;
    return par[n]=find(par[n]) ;
}

long MST(long n)
{
    long i , a , b , count=0 ;
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
            if(find(root)==find(dest)) break ;
        }
    }
    return count ;
}

int main()
{
    long i , j , a , b , C=1 , node , edge , ii=1 , S ;
    while(cin>>node>>edge>>S)
    {
        if(node==0 && edge==0 && S==0) break ;
        for(j=1 ; j<=edge ; j++)
        {
            cin>>a>>b>>i ;
            c.a=a ;
            c.b=b ;
            c.w=i ;
            V.push_back(c) ;
        }
        if(C>1) cout<<endl ;
        cout<<"Case #"<<ii<<endl ;
        for(i=1 ; i<=S ; i++)
        {
            cin>>root>>dest ;
            a=MST(node) ;
            if(find(root)==find(dest))
            cout<<a<<endl ;
            else cout<<"no path\n" ;
        }
        memset(par,0,sizeof(par)) ;
        V.clear() ;
        ii++ ;
        C=2 ;
    }
    return 0 ;
}


