#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>

using namespace std ;

struct edge
{
    long a , b , w ;
    bool operator < (const edge&p) const
    {
        return p.w>w ;
    }
} ;

long par[100000] , A , airports ;
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
    for(i=0 ; i<=n ; i++)
        par[i]=i ;
    sort(V.begin(),V.end()) ;
    for(i=0 ; i<V.size() ; i++)
    {
        a=find(V[i].a) ;
        b=find(V[i].b) ;
        //   cout<<V[i].a<<" "<<V[i].b<<" "<<V[i].w<<endl ;
        if(a!=b)
        {
            if(V[i].w>=A)
                airports++ ;
            else
                count=count+V[i].w ;
            par[a]=b ;
            j++ ;
            if(j==n-1) return count ;
        }
    }
    return count ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    long N , M , i , a , b , d , test , loop ;
    cin>>test ;
    for(loop=1 ; loop<=test ; loop++)
    {
        airports=0 ;
        cin>>N>>M>>A ;
        for(i=1 ; i<=M ; i++)
        {
            cin>>a>>b>>d ;
            C.a=a ;
            C.b=b ;
            C.w=d ;
            V.push_back(C) ;
        }
        a=MST(N) ;
        d=0 ;
        for(i=1 ; i<=N ; i++)
        {
            b=find(i) ;
            if(b==i)
                airports++ ;
        }
        cout<<"Case #"<<loop<<": "<<A*airports+a<<" "<<airports<<endl ;
        V.clear() ;
        memset(par,0,sizeof(par)) ;
    }
    return 0 ;
}
