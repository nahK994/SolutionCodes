#include<iostream>
#include<queue>
#include<vector>
#include<string.h>
#include<math.h>
#include<stdio.h>
#include<algorithm>

using namespace std ;

struct EDGE
{
    long a , b ;
    double w ;
    bool operator < (const EDGE &p) const
    {
        return p.w>w ;
    }
} ;

struct NODE
{
    double X , Y ;
} ;

NODE A[1000] ;
vector<EDGE>V ;
EDGE Q ;
long par[1000] ;

long find(long n)
{
    if(par[n]==n) return n ;
    return par[n]=find(par[n]) ;
}

double MST(long n)
{
    long i , j=0 , a , b ;
    double count=0 ;
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
                par[b]=a ;
                if(count<V[i].w) count=V[i].w ;
                if(find(1)==find(2)) break ;
            }
    }
    return count ;
}

int main()
{
    long node , edge , i , ii=1 , a , b , n ;
    double x1 , y1 , w1 ;
    while(cin>>node)
    {
        if(node==0) break ;
        for(i=1 ; i<=node ; i++)
        {
            cin>>x1>>y1 ;
            A[i].X=x1 ;
            A[i].Y=y1 ;
        }
        for(i=1 ; i<=node-1 ; i++)
        {
            for(a=i+1 ; a<=node ; a++)
            {
                w1=(A[i].X - A[a].X)*(A[i].X - A[a].X)+(A[i].Y - A[a].Y)*(A[i].Y - A[a].Y) ;
                w1=sqrt(w1) ;
                Q.a=i ;
                Q.b=a ;
                Q.w=w1 ;
                V.push_back(Q) ;
            }
        }
        x1=MST(node) ;
        cout<<"Scenario #"<<ii<<endl ;
        printf("Frog Distance = %0.3lf\n\n",x1) ;
        memset(par,0,sizeof(par)) ;
        V.clear() ;
        ii++ ;
    }
    return 0 ;
}
