#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std ;

int main()
{
    long test , i , j , a , ara[30] ;
    char ch[1000] , c ;
    cin>>test ;
    c=getchar() ;
    while(test--)
    {
        gets(ch) ;
       // strlwr(ch) ;
        //cout<<ch<<endl ;
        for(i=0 ; i<30 ; i++) ara[i]=0 ;
        for(i=0 ; i<strlen(ch) ; i++)
        {
            a=ch[i] ;
            if(a>=65 && a<=90) a=a+32 ;
            if(a>=97 && a<=122)
            {
                a=a-97 ;
                ara[a]++ ;
            }
        }
        j=0 ;
        for(i=0 ; i<26 ; i++)
        if(ara[i]>j) j=ara[i] ;
        for(i=0 ; i<26 ; i++)
        if(ara[i]==j)
        {
            c=i+97 ;
            cout<<c ;
        }
        cout<<endl ;
        //memset(ara,0,sizeof(ara)) ;
    }
    return 0 ;
}
