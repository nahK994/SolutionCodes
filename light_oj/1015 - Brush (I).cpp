#include<iostream>

using namespace std ;

int main()
{
    long loop , test , sum , a , n , b ;
    cin>>test ;
    for(loop=1 ; loop<=test ; loop++)
    {
        sum=0 ;
        cin>>n ;
        for(a=1 ; a<=n ; a++)
        {
            cin>>b ;
            if(b>-1) sum=sum+b ;
        }
        cout<<"Case "<<loop<<": "<<sum<<endl ;
    }
    return 0 ;
}
