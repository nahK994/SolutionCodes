#include<stdio.h>
#include<algorithm>

using namespace std ;

int main()
{
    long i=0 , a , n=1 , ara[10010] , b ;
    while(scanf("%ld",&a)!=EOF)
    {
        ara[i++]=a ;
        sort(ara,ara+n) ;
        if(n%2!=0) b=ara[(n/2)] ;
        else b=(ara[(n/2)-1]+ara[(n/2)])/2  ;
        printf("%ld\n",b) ;
        n++ ;
    }
    return 0 ;
}
