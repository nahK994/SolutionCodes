#include<stdio.h>
#include<math.h>

/*long prime_test(long n)

{
    if(n==2) return 2 ;
    if(n%2==0 || n<=1) return 1 ;
    for(long i=3 ; i*i<=n ; i+=2)
    if(n%i==0) return 1 ;
    return 2 ;
}*/

long int almost_prime(long int n , long int b)

{
    long int p=1 , count=0 ;
        while(p<=b)
        {
            count++ ;
            p=p*n ;
        }
        return count-2 ;
}

int main ()

{
    long int p , r , s , t , u=0 , v , ara[1000000] , p[1000000]={0} ;
    r=sqrt(1000000) ;
    for(p=1 ; p<=1000000 ; p++)
    ara[p]=p ;
    for(q=1 ; q<=r ; q++)
    {
        if(ara[q]!=1)
        {
           for(s=q+q ; s<=1000000 ; s=s+q)
           {
               ara[s]=1 ;
           }
        }
    }
    for(t=1 ; t<=1000 ; t++)
    {
        if(ara[t]!=1)
        {
            u++ ;
            p[u]=t ;
        }
    }
    long int i , j ;
    scanf("%ld",&j) ;
    for(i=1 ; i<=j ; i++)
    {
        long int a , b , count=0 , c , d ;
        scanf("%ld%ld",&a,&b) ;
        d=sqrt(b) ;
        for(c=1 ; c<=d ; c+=2)
        {
            if(p[c]>d)
            break ;
            count+=almost_prime(p[c],b) ;
        }
        printf("%ld\n",count) ;
    }
    return 0 ;
}
