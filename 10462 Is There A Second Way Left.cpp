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

long par[100000] ;
edge C ;
vector<edge>V , ans ;

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
        if(a!=b)
        {
            ans.push_back(V[i]) ;
            par[a]=b ;
            count+=V[i].w ;
            j++ ;
            if(j==n-1) break ;
        }
    }
    if(j!=n-1) return -1 ;
    /*par[1]=find(par[1]) ;
    for(i=1 ; i<=n ; i++)
        if(par[1]!=find(par[i]))
            return -1 ;*/
    return count ;
}

long MST2(long n , long start)
{
    long i , j=0 , a , b , count=0 , time=0 ;
    for(i=0 ; i<=n ; i++)
        par[i]=i ;
    for(i=0 ; i<V.size() ; i++)
    {
        if(V[i].a==ans[start].a && ans[start].b==V[i].b && V[i].w==ans[start].w && time==0)
       // if(i==start)
            {
                time=1 ;
                continue ;
            }
        a=find(V[i].a) ;
        b=find(V[i].b) ;
        if(a!=b)
        {
            par[a]=b ;
            count+=V[i].w ;
            j++ ;
            if(j==n-1) break ;
        }
    }
    if(j!=n-1) return -1 ;
    /* for(i=1 ; i<=n ; i++)
         if(find(par[1])!=find(par[i]))
             return -1 ;*/
    return count ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    long N , M , i , a , b , d , test , loop ;
    cin>>test ;
    for(loop=1 ; loop<=test ; loop++)
    {
        cin>>N>>M ;
        for(i=1 ; i<=M ; i++)
        {
            cin>>a>>b>>d ;
            C.a=a ;
            C.b=b ;
            C.w=d ;
            V.push_back(C) ;
        }
        cout<<"Case #"<<loop<<" : " ;
        a=MST(N) ;
       // cout<<"a "<<a<<endl ;
        if(a==-1)
            cout<<"No way\n" ;
        else
        {
            b=9999999 ;
            for(i=0 ; i<ans.size() ; i++)
            {
                d=MST2(N,i) ;
                if(d!=-1 && b>d)
                    b=d ;
            }
            if(b==9999999) cout<<"No second way\n" ;
            else cout<<b<<endl ;
        }
        V.clear() ;
        ans.clear() ;
        memset(par,0,sizeof(par)) ;
    }
    return 0 ;
}
