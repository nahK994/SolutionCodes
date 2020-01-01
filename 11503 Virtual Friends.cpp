#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
#include<string.h>

using namespace std ;

long par[100050] , Count[100050] ;

long find(long n)
{
    if(par[n]==n) return n ;
    return par[n]=find(par[n]) ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    map<string,long>mp ;
    long j , a , b , node , edge , test ;
    cin>>test ;
    string ch2 , ch1 ;
    while(test--)
    {
        cin>>edge ;
        node=1 ;
        for(j=0 ; j<=100010 ; j++)
        {
            par[j]=j ;
            Count[j]=1 ;
        }
        for(j=1 ; j<=edge ; j++)
        {
            cin>>ch1>>ch2 ;
            if(mp[ch1]==0) mp[ch1]=node++ ;
            if(mp[ch2]==0) mp[ch2]=node++ ;
            a=find(mp[ch1]) ;
            b=find(mp[ch2]) ;
            if(a!=b)
            {
                Count[a]=Count[a]+Count[b] ;
                par[b]=a ;
                cout<<Count[a]<<endl ;
            }
            else cout<<Count[a]<<endl ;
        }
        memset(par,0,sizeof(par)) ;
        memset(Count,0,sizeof(Count)) ;
        mp.clear() ;
    }
    return 0 ;
}

