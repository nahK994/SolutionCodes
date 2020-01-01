#include<iostream>
#include<math.h>
#include<stdio.h>

using namespace std ;

int main()
{
    double a , b , c , area ;
    while(cin>>a>>b>>c)
    {
        area=(a+b+c)/2.0 ;
        area=area*(area-a)*(area-b)*(area-c) ;
        if(area<=0) area=-1 ;
        else area=4.0*(sqrt(area))/3.0 ;
        printf("%0.3lf\n",area) ;
    }
    return 0 ;
}
