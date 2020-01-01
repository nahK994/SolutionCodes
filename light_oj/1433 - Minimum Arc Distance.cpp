#include<iostream>
#include<stdio.h>
#include<math.h>
#define pi 2*acos(0.0)

using namespace std ;

int main()
{
    long loop , test ;
    double A1 , A2 , B1 , B2 , O1 , O2 , OA , OB , AB , thita ;
    cin>>test ;
    for(loop=1 ; loop<=test ; loop++)
    {
        cin>>O1>>O2>>A1>>A2>>B1>>B2 ;
        AB=(A1-B1)*(A1-B1)+(A2-B2)*(A2-B2) ;
        AB=(double)sqrt(AB) ;
        OA=(A1-O1)*(A1-O1)+(A2-O2)*(A2-O2) ;
        OA=(double)sqrt(OA) ;
        OB=(B1-O1)*(B1-O1)+(B2-O2)*(B2-O2) ;
        OB=(double)sqrt(OB) ;
        thita=(double)(OA*OA+OB*OB-AB*AB)/(2*OA*OB) ;
        thita=acos(thita) ;
        //thita=thita*pi/180.0 ;
        AB=OA*thita ;
        printf("Case %ld: %0.8lf\n",loop,AB) ;
    }
    return 0 ;
}
