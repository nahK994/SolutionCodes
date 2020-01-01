#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<string.h>
#include<stdio.h>
using namespace std ;

struct nodes
{
    long A , B ;
    double w ;
    bool operator < (const nodes& p) const
    {
        return p.w>w ;
    }
} ;

struct edges
{
    double X , Y ;
} ;

edges A[10000] ;
nodes C ;
vector<nodes>V ;
long par[10000] , node , dest ;
double towns , roads , railroads ;

long find(long n)
{
    if(par[n]==n) return n ;
    return par[n]=find(par[n]) ;
}

void MST()
{
    long i , a , b , j=0 ;
    for(i=1 ; i<=node ; i++) par[i]=i ;
    sort(V.begin(),V.end()) ;
    for(i=0 ; i<V.size() ; i++)
    {
        a=find(V[i].A) ;
        b=find(V[i].B) ;
        if(a!=b)
        {
            par[a]=b ;
            if(V[i].w>dest)
            {
                towns++ ;
                railroads+=V[i].w ;
            }
            else
                roads+=V[i].w ;
            j++ ;
            if(j==node-1) break ;
        }
    }
}

int main()
{
     ios_base::sync_with_stdio(false);
    long loop , test , i , a , b , roads1 , railroads1 ;
    double x , y , G ;
    cin>>test ;
    for(loop=1 ; loop<=test ; loop++)
    {
        cin>>node>>dest ;
        towns=0 ;
        roads=0 ;
        railroads=0 ;
        for(i=1 ; i<=node ; i++)
        {
            cin>>x>>y ;
            A[i].X=x ;
            A[i].Y=y ;
        }
        for(i=1 ; i<=node-1 ; i++)
        {
            for(a=i+1 ; a<=node ; a++)
            {
                G=(A[i].X-A[a].X)*(A[i].X-A[a].X)+(A[i].Y-A[a].Y)*(A[i].Y-A[a].Y) ;
                G=sqrt(G) ;
                C.A=i ;
                C.B=a ;
                C.w=G ;
                V.push_back(C) ;
            }
        }
        MST() ;
        towns++ ;
        if(roads==0&&railroads==0) towns=0 ;
        double aa=(long)roads ;
        double bb=(long)railroads ;
        roads1=roads ;
        railroads1=railroads ;
        if(roads-aa>=0.5) roads1++ ;
        if(railroads-bb>=0.5) railroads1++ ;
        cout<<"Case #"<<loop<<": "<<towns<<" "<<roads1<<" "<<railroads1<<endl ;
        memset(par,0,sizeof(par)) ;
        memset(A,0,sizeof(A)) ;
        V.clear() ;
    }
    return 0 ;
}
