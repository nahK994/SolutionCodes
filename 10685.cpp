#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<string>
#include<string.h>
using namespace std ;

long par[10000] , ara[10000] ;
map<string,long>stol ;

long find(long n)
{
    if(par[n]==n) return n ;
    else par[n]=find(par[n]) ;
}

int main()
{
    long C , R , i , a , b ;
    string ch1 , ch2 ;
    while(cin>>C>>R)
    {
        memset(par,0,sizeof(par)) ;
        memset(ara,0,sizeof(ara)) ;
        stol.clear() ;
        for(i=1 ; i<=C ; i++)
        {
            cin>>ch1 ;
            stol[ch1]=i ;
            par[i]=i ;
            ara[i]=0 ;
        }
        if(C==0&&R==0) break ;
        if(R==0)
        {
            cout<<"1"<<endl ;
            continue ;
        }
        while(R--)
        {
            cin>>ch1>>ch2 ;
            a=stol[ch1] ;
            b=stol[ch2] ;
            a=find(a) ;
            b=find(b) ;
            if(a!=b)
                par[a]=b ;
        }
        for(i=1 ; i<=C ; i++)
         {
             a=find(i) ;
             ara[a]++ ;
         }
        a=0 ;
        for(i=1 ; i<=C ; i++)
            if(a<ara[i])
                a=ara[i] ;/////
        cout<<a<<endl ;
    }
    return 0 ;
}
