#include<stdio.h>
#include<math.h>

int main ()

{
    long n ;
    while(scanf("%ld",&n)!=EOF)
    {
        long q=n ;
        long a=sqrt(n) ;
        long i , j=0 , k , ara[1000]={0} , product=1 , sum=0 , p , l , x ;
        for(i=2 ; i<=a ; i++)
        {
            if(n%i==0)
            break ;
        }
        if(i<a || i==a)
        {
            printf("%ld is not prime.\n",q) ;
            continue ;
        }
        while(n!=0)
        {
            ara[j]=n%10 ;
            n=n/10 ;
            j++ ;
        }
        j=j-1 ;
        for(k=j ; k>=0 ; k--)
        {
           p=product*ara[k] ;
           sum=sum+p ;
           product=product*10 ;
        }
        l=sqrt(sum) ;
        for(x=2 ; x<=l ; x++)
        {
            if(sum%x==0)
            break ;
        }
        if(x>l && q!=sum && q/10>0)
        printf("%ld is emirp.\n",q) ;
        else printf("%ld is prime.\n",q) ;
    }
    return 0 ;
}
