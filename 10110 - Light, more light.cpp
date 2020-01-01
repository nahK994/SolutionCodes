#include<iostream>
#include<math.h>

using namespace std ;

int main()
{
    long n , a ;
    double b ;
    while(cin>>n && n!=0)
    {
        a=sqrt(n) ;
        b=sqrt(n) ;
        if(b==a) cout<<"yes\n" ;
        else cout<<"no\n" ;
    }
    return 0 ;
}
