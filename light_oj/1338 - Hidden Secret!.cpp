#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
#include<string.h>
#include<stdio.h>

using namespace std ;

int main()
{
    long loop , test , a , b , c , i , ara1[30] , ara2[30] ;
    char ch1[1000] , ch2[1000] , ch ;
    cin>>test ;
    ch=getchar() ;
    for(loop=1 ; loop<=test ; loop++)
    {
        b=0 ;
        gets(ch1) ;
        gets(ch2) ;
        for(i=0 ; i<30 ; i++)
        {
            ara1[i]=0 ;
            ara2[i]=0 ;
        }
        for(i=0 ; i<strlen(ch1) ; i++)
        {
            if(ch1[i]>=97 && ch1[i]<=122)
            {
                a=ch1[i]-96 ;
                ara1[a]++ ;
            }
            else if(ch1[i]>=65 && ch1[i]<=90)
            {
                a=ch1[i]-64 ;
                ara1[a]++ ;
            }
        }
        for(i=0 ; i<strlen(ch2) ; i++)
        {
            if(ch2[i]>=97 && ch2[i]<=122)
            {
                a=ch2[i]-96 ;
                ara2[a]++ ;
            }
            else if(ch2[i]>=65 && ch2[i]<=90)
            {
                a=ch2[i]-64 ;
                ara2[a]++ ;
            }
        }
        for(i=0 ; i<strlen(ch1) ; i++)
        {
            if(ch1[i]>=97 && ch1[i]<=122)
                a=ch1[i]-96 ;
            else if(ch1[i]>=65 && ch1[i]<=90)
                a=ch1[i]-64 ;
            if(ara1[a]!=ara2[a])
            {
               // cout<<"A\n" ;
                b=1 ;
                break ;
            }
        }
        for(i=0 ; i<strlen(ch2) ; i++)
        {
            if(ch2[i]>=97 && ch2[i]<=122)
                a=ch2[i]-96 ;
            else if(ch2[i]>=65 && ch2[i]<=90)
                a=ch2[i]-64 ;
            if(ara1[a]!=ara2[a])
            {
               // cout<<"B\n" ;
                b=1 ;
                break ;
            }
        }
        if(b==0) cout<<"Case "<<loop<<": Yes\n" ;
        else cout<<"Case "<<loop<<": No\n" ;
        memset(ara1,0,sizeof(ara1)) ;
        memset(ara2,0,sizeof(ara2)) ;
    }
    return 0 ;
}
