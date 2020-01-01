#include<stdio.h>
#include<string.h>
int main()
{
    long i , n , sum1 , sum2 , a=1 ;
    while(scanf("%ld",&n)!=EOF)
    {
        if(n==0) break ;
        sum1=sum2=0 ;
        while(n--)
        {
            scanf("%ld",&i) ;
            if(i>0) sum1++ ;
            else sum2++ ;
        }
        printf("Case %ld: %ld\n",a++,sum1-sum2) ;
    }
    return 0 ;
}
