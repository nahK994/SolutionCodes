#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std ;

long par[100] ;

long find_parent(long n)
{
    if(par[n]==n) return n ;
    else find_parent(par[n]) ;
}

int main()
{
    long test , a , b , e , F=1 ;
    char ch[10] , c ;
    cin>>test ;
    c=getchar() ;
    c=getchar() ;
    while(test--)
    {
        e=0 ;
        for(a=65 ; a<=90 ; a++) par[a]=a ;
        while(gets(ch))
        {
            a=ch[0] ; b=ch[1] ;
            if(a>e) e=a ;
            if(b>e) e=b ;
            if(strlen(ch)==1) continue ;
            if(strlen(ch)==0) break ;
            a=find_parent(a) ; b=find_parent(b) ;
            par[a]=b ;
        }
        b=0 ;
        //cout<<e<<endl ;
        for(a=65 ; a<=e ; a++)
        if(par[a]==a) b++ ;
        if(F>1) cout<<endl ;
        cout<<b<<endl ;
        F=2 ;
    }
    return 0 ;
}
