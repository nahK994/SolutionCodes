#include<iostream>
#include<string.h>
using namespace std ;

long par[100000] , ara[100000] , node , edge ;

long find(long n)
{
    if(par[n]==n) return n ;
    return par[n]=find(par[n]) ;
}

int main()
{
    long i , a , b , test ;
    cin>>test ;
    while(test--)
    {
        cin>>node>>edge ;
        for(i=1 ; i<=node ; i++)
        {
            par[i]=i ;
            ara[i]=1 ;
        }
        while(edge--)
        {
            cin>>a>>b ;
            a=find(a) ;
            b=find(b) ;
            if(a!=b)
            {
                par[a]=b ;
                ara[b]+=ara[a] ;
            }
        }
        a=0 ;
        for(i=1 ; i<=node ; i++)
            if(a<ara[i]) a=ara[i] ;
        cout<<a<<endl ;
        memset(par,0,sizeof(par)) ;
        memset(ara,0,sizeof(ara)) ;
    }
    return 0 ;
}
