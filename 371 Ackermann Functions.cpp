#include<stdio.h>

long c(long i)
{
   if(i==1) return 3 ;
   long count=0 ;
   while(i!=1)
    {
        if(i%2==0)
        {
            i=i/2 ;
            count++ ;
            if(i==1) return count ;
        }
        if(i%2!=0)
        {
            i=3*i+1 ;
            count++ ;
        }
    }
    return count+1 ;

}

int main ()

{
    long a , b ;
    while(scanf("%ld%ld",&a,&b)!=EOF)
    {
        if(a==0 && b==0) break ;
        long count=0 , d=0 , i , j , k ;
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
            if(count>d)
            {
                k=i ;
                d=count ;
            }
        }
        printf("Between %ld and %ld, %ld generates the longest sequence of %ld values.\n",a,b,k,d) ;
    }
    return 0 ;
}

