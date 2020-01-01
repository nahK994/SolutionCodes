#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<string>
#include<string.h>
using namespace std ;

int par[10000] , ara[10000] ;
map<string,int>stol ;

int find(int n)
{
    if(par[n]==n)
        return n ;
    return par[n]=find(par[n]) ;
}

int main()
{
    int C , R , i , a , b ;
    char ch1[35] , ch2[35] ;
    while(cin>>C>>R)
        {
            if(C==0&&R==0)
                break ;
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
            //for(i=1;i<=C;++i)
            //cout<<"par["<<i<<"]=="<<par[i]<<endl;

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
            par[b]=a ;
        }
        //for(i=1;i<=C;++i)
            //cout<<"par["<<i<<"]=="<<par[i]<<endl;

        for(i=1 ; i<=C ; i++)
        {
            a=find(i) ;
            par[i]=a;
            //cout<<i<<"xxx"<<a<<endl;
            ++ara[a] ;
        }
        //for(i=1;i<=C;++i)
           // cout<<par[i]<<endl;
        //cout<<"aaaa"<<endl;
        //for(i=1;i<=C;++i)
           // cout<<ara[i]<<endl;
        a=0 ;
        for(i=1 ; i<=C ; i++)
        if(a<ara[i]) a=ara[i] ;
        cout<<a<<endl ;
    }
    return 0 ;
}
