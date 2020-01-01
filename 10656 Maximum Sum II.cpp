#include<stdio.h>
#include<math.h>

int main ()

{
    long n , m , o , i , j , p , c , b , q , d , a[300] ;
    while(scanf("%ld",&n)!=EOF)
    {
        if(n==0) break ;
        o=0 ;
        q=100000 ;
        for(i=0 ; i<n ; i++)
        scanf("%ld",&a[i]) ;
        for(j=0 ; j<n-1 ; j++)
        {
           for(p=j+1 ; p<n ; p++)
           {
             m=a[j]+a[p] ;
             if(m=>o)
             {
                 if(a[j]>a[p]) d=a[j]-a[p] ;
                 else d=a[p]-a[j] ;
                 if(d<q)
                 {
                  c=a[j] ;
                  b=a[p] ;
                  o=a[j]+a[p] ;
                  if(a[j]>a[p]) q=a[j]-a[p] ;
                  else q=a[p]-a[j] ;
                 }
             }
           }
        }
        if(n==1) printf("%ld\n",a[0]) ;
        else if(c>b) printf("%ld %ld\n",b,c) ;
        else printf("%ld %ld\n",c,b) ;
        a[300]={0} ;
    }
    return 0 ;
}

