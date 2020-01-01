#include<stdio.h>
#include<math.h>

#define i64 long long
i64 B , P , M ;

i64 rec(i64 B , i64 P)
{
    if(P==0) return 1 ;
    if(P%2==0)
    {
        i64 Rec=rec(B,P/2) ;
        return ((Rec%M)*(Rec%M))%M ;
    }
    return ((B%M)*(rec(B,P-1))%M)%M ;
}

int main()
{
    i64 a ;
    while(scanf("%lld%lld%lld",&B,&P,&M)!=EOF)
    {
        a=rec(B,P) ;
        printf("%lld\n",a) ;
    }
    return 0 ;
}
