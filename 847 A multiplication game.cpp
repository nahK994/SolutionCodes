#include<stdio.h>

int main ()

{
    long long i , j , a[100] , n ;
    a[0]=1 ;
    for(i=1 ; a[i-1]<4294967295 ; i++)
       a[i]=9*a[i-1] ;
    while(scanf("%I64d",&n)!=EOF)
    {
        j=1 ;
        while(a[j]<n)
            j++ ;
        printf("%I64d\n",j) ;
        if(j%2==0) printf("Ollie wins.\n") ;
        else printf("Stan wins.\n") ;
    }
    return 0 ;
}
