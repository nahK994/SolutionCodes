#include<bits/stdc++.h>
#define eps 1e-7
using namespace std ;

double x , y ,c ,low ,high ,mid ,p,q ,x1,x2 ;

double call (double n)
{
    p=sqrt(y*y-n*n) ;
    q=sqrt(x*x-n*n) ;

    x1=(n*c)/p ;
    x2=(n*c)/q ;

    return x1+x2 ;
}

int main ()
{
    int t , i ,it=0 ;
    cin>>t ;
    while (it<t)
    {
        it++ ;
        cin>>x>>y>>c ;
        low=0.0 ;
        high=min(x,y)*1.0 ;

         while (fabs(low-high)>eps)
         {
             mid=(low+high)/2.0 ;
             if (call(mid)<mid) low=mid;
             else if (call(mid)>mid) high=mid ;
         }
         cout<<"Case "<<it<<": " ;
         cout<<setprecision(10)<<low<<endl ;

    }

    return 0 ;
}
