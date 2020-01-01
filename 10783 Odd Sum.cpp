#include<stdio.h>

int main ()

{
    long i , j , a , b , sum ;
    scanf("%ld",&j) ;
    for(i=1 ; i<=j ; i++)
    {
        sum=0 ;
        scanf("%ld%ld",&a,&b) ;
        if(a%2==0) a=a+1 ;
        if(b%2==0) b=b-1 ;
        b=(b+1)/2 ;
        a=(a+1)/2 ;
        sum=b*b-(a-1)*(a-1) ;
        printf("Case %ld: %ld\n",i,sum) ;
    }
    return 0 ;
}
