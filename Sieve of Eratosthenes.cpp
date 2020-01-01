#include<stdio.h>
#include<math.h>

int main ()

{
    long a[100000] , i , j , d , l , z=sqrt(9999) , p , pr[100000] , c=0 ;
    a[0]=1 ;
    for(i=1 ; i<100000 ; i++)
    {
        a[i]=i ;
    }
    for(j=2 ; j<=z ; j++)
    {
        if(a[j]!=1)
        {
            for(p=2*j ; p<=100000 ; p=p+j)
            a[p]=1 ;
        }
    }
    for(d=1 ; d<=100000 ; d++)
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
