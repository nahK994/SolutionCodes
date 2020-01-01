#include<iostream>
#include<string.h>
using namespace std ;

long par[100000] ;

long find(long n)
{
    if(par[n]==n) return n ;
    return par[n]=find(par[n]) ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    long i , node , edge , count=1 , a , b ;
    while(cin>>node>>edge)
    {
        if(node==0 && edge==0) break ;
        for(i=1 ; i<=node ; i++) par[i]=i ;
        while(edge--)
        {
            cin>>a>>b ;
            a=find(a) ; b=find(b) ;
            par[a]=b ;
        }
        a=0 ;
        for(i=1 ; i<=node ; i++)
        if(par[i]==i) a++ ;
        cout<<"Case "<<count++<<": "<<a<<endl ;
        memset(par,0,sizeof(par)) ;
    }
    return 0 ;
}
