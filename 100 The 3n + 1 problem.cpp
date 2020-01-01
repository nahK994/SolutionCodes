#include<stdio.h>
long c(long i)
{
   long count=0 ;
   while(i!=1)
    {
        if(i%2==0)
        {
            i=i/2 ;
            count++ ;
        }
        if(i==1) break ;
        if(i%2!=0)
        {
            i=3*i+1 ;
            count++ ;
        }
    }
    if(i==1) count ;
    return count+1 ;

}

int main ()

{
    long a , b ;
    while(scanf("%ld%ld",&a,&b)!=EOF)
    {
        long count=0 , d=0 , i , j ;
        if(a<b)
        {
            i=a ;
            j=b ;
        }
        else
        {
            i=b ;
            j=a ;
        }
        for( ; i<=j ; i++)
        {
            count=c(i) ;
            if(count>=d) d=count ;
        }
        printf("%ld %ld %ld\n",a,b,d) ;
    }
    return 0 ;
}
