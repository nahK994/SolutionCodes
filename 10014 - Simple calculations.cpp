#include<iostream>
#include<math.h>
#include<stdio.h>
#include<string.h>

using namespace std ;

int main()
{
    long test , i , n ;
    double b , c , ara[10000] , a , sum ;
    cin>>test ;
    while(test--)
    {
        sum=0 ;
        cin>>n>>b>>c ;
        for(i=1 ; i<=n ; i++)
        cin>>ara[i] ;
        a=(double)n*b+c ;
        for(i=1 ; i<=n ; i++)
        sum+=(n-i+1)*ara[i] ;
        a-=2*sum ;
        a/=(n+1) ;
        printf("%.2lf\n",a) ;
        if(test) cout<<endl ;
    }
    return 0 ;
}
