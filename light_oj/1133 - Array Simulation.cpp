#include<iostream>
#include<string.h>

using namespace std ;

int main()
{
    long loop , test , size , ins , ara[1000] , i , j , a ;
    char ch ;
    cin>>test ;
    for(loop=1 ; loop<=test ; loop++)
    {
        cin>>size>>ins ;
        for(i=0 ; i<size ; i++)
        cin>>ara[i] ;
        while(ins--)
        {
            cin>>ch ;
            if(ch=='S')
            {
                cin>>j ;
                for(i=0 ; i<size ; i++)
                ara[i]+=j ;
            }
            else if(ch=='M')
            {
                cin>>j ;
                for(i=0 ; i<size ; i++)
                ara[i]*=j ;
            }
            else if(ch=='D')
            {
                cin>>j ;
                for(i=0 ; i<size ; i++)
                ara[i]/=j ;
            }
            else if(ch=='P')
            {
                cin>>j>>a ;
                i=ara[j] ;
                ara[j]=ara[a] ;
                ara[a]=i ;
            }
            else
            {
                for(i=0 , a=size-1 ; i<a ; i++ , a--)
                {
                    j=ara[i] ;
                    ara[i]=ara[a] ;
                    ara[a]=j ;

                }
            }
        }
        cout<<"Case "<<loop<<":\n" ;
        for(i=0 ; i<size-1 ; i++)
        cout<<ara[i]<<" " ;
        cout<<ara[size-1]<<endl ;
        memset(ara,0,sizeof(ara)) ;
    }
    return 0 ;
}
