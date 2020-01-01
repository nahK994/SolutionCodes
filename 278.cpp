#include<iostream>

using namespace std ;

int main()
{
    long test , a , b , i ;
    char ch ;
    cin>>test ;
    while(test--)
    {
        cin>>ch>>a>>b ;
        if(ch=='r')
        {
            if(a<b) i=a ;
            else i=b ;
        }
        else if(ch=='K')
        i=((a+1)/2)*((b+1)/2) ;
        else if(ch=='Q')
        {
            if(a<b) i=a ;
            else i=b ;
        }
        else if(ch=='k')
        i=(a*b)/2 ;
        cout<<i<<endl ;
    }
    return 0 ;
}
