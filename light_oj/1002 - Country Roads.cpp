#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
#include<string.h>
#include<queue>

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
vector<long> B[100000] , cost[100000] ;
queue<long>Q ;
edge c ;
long par[1000] , ans[1000] , N , ara[700][700] ;

long find(long n)
{
    if(par[n]==n) return n ;
    return par[n]=find(par[n]) ;
}

void MST(long n)
{
    long i , j=0 , a , b , c , d , w ;
    for(i=0 ; i<n ; i++)
    {
        par[i]=i ;
        ans[i]=-1 ;
    }
    sort(V.begin(),V.end()) ;
    for(i=0 ; i<V.size() ; i++)
    {
        c=V[i].a ;
        d=V[i].b ;
        w=V[i].w ;
        a=find(c) ;
        b=find(d) ;
        if(a!=b)
        {
            B[c].push_back(d) ;
            cost[c].push_back(w) ;
            B[d].push_back(c) ;
            cost[d].push_back(w) ;
            ara[c][d]=1 ;
            ara[d][c]=1 ;
            par[a]=b ;
            j++ ;
            if(j==n-1) break ;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    long i , j , a , b , node , edge , loop , test ;
    cin>>test ;
    for(loop=1 ; loop<=test ; loop++)
    {
        cin>>node>>edge ;
        for(j=1 ; j<=edge ; j++)
        {
            cin>>a>>b>>i ;
            c.a=a ;
            c.b=b ;
            c.w=i ;
            V.push_back(c) ;
        }
        cin>>N ;
        MST(node) ;
        ans[N]=0 ;
        Q.push(N) ;
        while(!Q.empty())
        {
            a=Q.front() ;
            Q.pop() ;
            for(i=0 ; i<B[a].size() ; i++)
            {
                b=B[a][i] ;
                if(ara[a][b]==1)
                {
                    Q.push(b) ;
                    if(cost[a][i]>ans[a]) ans[b]=cost[a][i] ;
                    else ans[b]=ans[a] ;
                    ara[b][a]=-1 ;
                }
            }
        }
        cout<<"Case "<<loop<<":\n" ;
        for(i=0 ; i<node ; i++)
            if(ans[i]==-1) cout<<"Impossible\n" ;
            else cout<<ans[i]<<endl ;
        V.clear() ;
        for(i=0 ; i<node ; i++)
        {
            B[i].clear() ;
            cost[i].clear() ;
            memset(ara[i],0,sizeof(ara[i])) ;
        }
        memset(ans,0,sizeof(ans)) ;
    }
    return 0 ;
}
