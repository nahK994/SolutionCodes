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

long par[1000] ;
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
    for(i=0 ; i<n ; i++)
        par[i]=i ;
    sort(V.begin(),V.end()) ;
    for(i=0 ; i<V.size() ; i++)
    {
        a=find(V[i].a) ;
        b=find(V[i].b) ;
        //   cout<<V[i].a<<" "<<V[i].b<<" "<<V[i].w<<endl ;
        if(a!=b)
        {
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
    long loop , test , i , j , sum , a , n ;
    cin>>test ;
    for(loop=1 ; loop<=test ; loop++)
    {
        sum=0 ;
        cin>>n ;
        for(i=0 ; i<n ; i++)
        for(j=0 ; j<n ; j++)
        {
           cin>>a ;
           sum+=a ;
           if(a==0 || i==j) continue ;
           C.a=i ;
           C.b=j ;
           C.w=a ;
           V.push_back(C) ;
        }
        a=MST(n) ;
        i=0 ;
        for(j=0 ; j<n ; j++)
        if(find(j)==j) i++ ;
        cout<<"Case "<<loop<<": " ;
        if(i>1) cout<<"-1\n" ;
        else cout<<sum-a<<endl ;
        memset(par,0,sizeof(par)) ;
        V.clear() ;
    }
    return 0 ;
}
