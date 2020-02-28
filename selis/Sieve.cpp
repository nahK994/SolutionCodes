#include<stdio.h>
#include<math.h>

int main ()

{
    long a[100000] , i , j , d , l , N = 10000 , p , pr[10000] , c=0 ;
    a[0]=1 ;
    for(i=1 ; i<=N ; i++)
    {
        a[i]=i ;
    }
    for(j=2 ; j<=sqrt(N) ; j++)
    {
        if(a[j]!=1)
        {
            for(p=j*j ; p<=N ; p=p+j)
            a[p]=1 ;
        }
    }
    for(d=1 ; d<=N ; d++)
    {
        if(a[d]!=1)
        {
          pr[c]=a[d] ;
          c++ ;
        }
    }
    for(l=0 ; l<c ; l++)
        printf("%ld\n",pr[l]) ;
    return 0 ;
}
