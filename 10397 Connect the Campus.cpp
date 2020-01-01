#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<math.h>
#include<stdio.h>
#include<string.h>

using namespace std ;

struct edge
{
    long a , b ;
    float w ;
   // float x , y , w ;
    bool operator < (const edge& p) const
    {
        return p.w>w ;
    }
} ;

struct NODE
{
    float X , Y ;
} ;

long par[1000] ;
edge C ;
NODE A[1000] ;
vector<edge>V ;

long find(long n)
{
    if(par[n]==n) return n ;
    return par[n]=find(par[n]) ;
}

double MST(long n)
{
    long j=0 , i , a , b ;
    double count=0 ;
    //for(i=1 ; i<=n ; i++) par[i]=i ;
    sort(V.begin(),V.end()) ;
    for(i=0 ; i<V.size() ; i++)
    {
        a=find(V[i].a) ;
        b=find(V[i].b) ;
        if(a!=b)
        {
            par[a]=b ;
            count=count+V[i].w ;
           // printf("%0.2f %0.2f\n",V[i].w,count) ;
            j++ ;
            if(j==n-1) return count ;
        }
    }
    return count ;
}

int main()
{
    long test , node , i , j , a , b ;
    double x , y , w , x1 , y1 ;
    while(cin>>node)
    {
        for(i=1 ; i<=node ; i++)
        {
            cin>>x>>y ;
            A[i].X=x ;
            A[i].Y=y ;
        }
        for(i=1 ; i<=node-1 ; i++)
        {
            x=A[i].X ;
            y=A[i].Y ;
            for(j=i+1 ; j<=node ; j++)
            {
               x1=A[j].X ;
               y1=A[j].Y ;
               w=(float)(x-x1)*(x-x1)+(y-y1)*(y-y1) ;
               w=(float)sqrt(w) ;
              // printf("%0.2f\n",w) ;
               C.a=i ;
               C.b=j ;
               C.w=w ;
               V.push_back(C) ;
            }
        }
        for(i=1 ; i<=node ; i++) par[i]=i ;
        cin>>i ;
        for(j=1 ; j<=i ; j++)
        {
            cin>>a>>b ;
            a=find(a) ;
            b=find(b) ;
            par[a]=b ;
        }
        w=MST(node) ;
        //if(a>1) printf("\n") ;
        printf("%0.2lf\n",w) ;
        V.clear() ;
        memset(par,0,sizeof(par)) ;
        a=2 ;
    }
    return 0 ;
}
