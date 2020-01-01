#include<stdio.h>
#include<math.h>

int main ()

{
    double r , l ;
    long n , m , i , j , p , a[300] ;
    while(scanf("%ld",&n)!=EOF)
    {
        if(n==0) break ;
        for(i=1 ; i<=2*n ; i++)
        scanf("%ld",&a[i]) ;
        scanf("%lf",&r) ;
        m=1 ;
        for(j=1 ; j<=2*n-3 ; j+=2)
        {
           for(p=j+2 ; p<=2*n ; p+=2)
           {
             l=(double)(a[j]-a[p])*(a[j]-a[p])+(a[j+1]-a[p+1])*(a[j+1]-a[p+1]) ;
             if(l<0) l=(double)-1*l ;
             l=(double)sqrt(l) ;
             if(l>r*2)
             {
                 m=2 ;
                 break ;
             }
           }
          if(m==2) break ;
        }
        if(m==1 && r!=0) printf("The polygon can be packed in the circle.\n") ;
        else printf("There is no way of packing that polygon.\n") ;
        a[300]={0} ;
    }
    return 0 ;
}
