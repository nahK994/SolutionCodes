#include<stdio.h>
#include<math.h>

long p(long n)

{
    long sum=1 , i=2 , j=sqrt(n) ;
    while(i<=j && sum<=n)
    {
        if(n%i==0) sum=sum+i+n/i ;
        i++ ;
    }
    if(j*j==n && i>j) return sum-j ;
    return sum ;
}

int main ()

{
    long c=0 , i , a[1000]={1} ;
    while(a[c]!=0)
    {
        c++ ;
        scanf("%ld",&a[c]) ;
    }
    printf("PERFECTION OUTPUT\n") ;
    for(i=1 ; i<c ; i++)
    {
        if(p(a[i])==a[i]) printf("%5ld  PERFECT\n",a[i]) ;
        else if(p(a[i])>a[i]) printf("%5ld  ABUNDANT\n",a[i]) ;
        else printf("%5ld  DEFICIENT\n",a[i]) ;
    }
    printf("END OF OUTPUT\n") ;
    return 0 ;
}
