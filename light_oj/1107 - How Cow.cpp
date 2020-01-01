#include<iostream>

using namespace std ;

int main()
{
    long loop , test , x1 , x2 , y1 , y2 , n , x , y ;
    cin>>test ;
    for(loop=1 ; loop<=test ; loop++)
    {
        cin>>x1>>y1>>x2>>y2 ;
        cin>>n ;
        cout<<"Case "<<loop<<":"<<endl ;
        while(n--)
        {
            cin>>x>>y ;
            if(x>=x1 && x<=x2 && y>=y1 && y<=y2) cout<<"Yes\n" ;
            else cout<<"No\n" ;
        }
    }
    return 0 ;
}
