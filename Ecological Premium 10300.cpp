#include<iostream>

using namespace std ;

int main()
{
    long test , farmers , farmlands , animals , env , sum ;
    cin>>test ;
    while(test--)
    {
        cin>>farmers ;
        sum=0 ;
        while(farmers--)
        {
            cin>>farmlands>>animals>>env ;
            sum+=farmlands*env ;
        }
        cout<<sum<<endl ;
    }
    return 0 ;
}
