#include<stdio.h>
#include<math.h>

long sq_test(double n)
{
    long long a=sqrt(n) ;
    if(a*a==n) return 1 ;
    return 0 ;
}

int main()
{
    long long loop , test , a , limit , n ;
    double i , j , k ;
    scanf("%lld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        scanf("%lld",&n) ;
        k=n ;
        a=sqrt(k) ;
        if(sq_test(k)==1 && n%2!=0)
        printf("Case %lld: 1 %lld\n",loop,a) ;
        else if(sq_test(k)==1 && n%2==0)
        printf("Case %lld: %lld 1\n",loop,a) ;
        else if(a%2==0)
        {
            limit=a*a+a+1 ;
            if(n==limit) printf("Case %lld: %lld %lld\n",loop,a+1,a+1) ;
            else if(n>limit) printf("Case %lld: %lld %lld\n",loop, (a+1)*(a+1)-n+1 ,a+1) ;
            else printf("Case %lld: %lld %lld\n",loop,a+1,n-a*a) ;
        }
        else
        {
             limit=a*a+a+1 ;
            if(n==limit) printf("Case %lld: %lld %lld\n",loop,a+1,a+1) ;
            else if(n>limit) printf("Case %lld: %lld %lld\n",loop,a+1,(a+1)*(a+1)-n+1) ;
            else printf("Case %lld: %lld %lld\n",loop,n-a*a,a+1) ;
        }
    }
    return 0 ;
}
