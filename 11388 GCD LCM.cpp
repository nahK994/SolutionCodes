#include<stdio.h>

long GCD (long a, long b)

{
    long i , j , s=1 ;
    if(a<b)
    j=a ;
    else j=b ;
    for(i=1 ; i<=j ; i++)
    if(s<i && a%i==0 && b%i==0)
    s=i ;
    return s ;
}

long LCM (long a , long b)

{
    long l=GCD(a,b) ;
    l=a*b/l ;
    return l ;
}

int main ()

{
    int i , j ;
    scanf("%d",&j) ;
    for(i=1 ; i<=j ; i++)
    {
        long a , b , c , d , e , f ;
        scanf("%ld%ld",&a,&b) ;
        if(b%a!=0 || a>b)
        {
            printf("-1\n") ;
            continue ;
        }
        else if(a==b)
        printf("%ld %ld\n",a,b) ;
        else
        {
        for(c=a+1 ; c<b ; c++)
        {
            if(a*b/c!=0)
            continue ;
            d=a*b/c ;
            e=GCD(c,d) ;
            f=LCM(c,d) ;
            if(e==a && f==b)
            {
                printf("%ld %ld\n",c,d) ;
                break ;
            }
        }
        if(c==b)
        printf("%ld %ld\n",a,b) ;
    }
    }
    return 0 ;
}
