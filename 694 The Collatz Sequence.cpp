#include<stdio.h>

long c(long i,long j)
{
   long count=0 ;
   while(i<=j)
    {
        if(i%2==0)
        {
            i=i/2 ;
            count++ ;
        }
        if(i==1) return count+1 ;
        if(i%2!=0)
        {
            i=3*i+1 ;
            count++ ;
        }
    }
    return count ;
}

int main ()

{
    long a , b , i=1 ;
    while(scanf("%ld%ld",&a,&b)!=EOF)
    {
        if(a<0 && b<0) break ;
        long count=0 ;
        count=c(a,b) ;
        printf("Case %ld: A = %ld, limit = %ld, number of terms = %ld\n",i,a,b,count) ;
        i++ ;
    }
    return 0 ;
}


