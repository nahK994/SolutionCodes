#include<iostream>
using namespace std ;

int main()
{
    long test , a , b , n ;
    cin>>test ;
    while(test--)
    {
        cin>>n ;
        if(n<=10)
        cout<<"0 "<<n<<endl ;
        else cout<<n-10<<" 10\n" ;
    }
    return 0 ;
}
