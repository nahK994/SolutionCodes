#include<stdio.h>
#include<math.h>

int main ()

{
    long n , s=0 , i ;
    double b ;
    while(scanf("%ld",&n)!=EOF)
    {
        long c=0 , x=0 , y=0 , a=0 , v ;
        if(s!=0) printf("\n") ;
        for(i=1 ; i<=n ; i++)
        {
            b=(double)((n-0.5)*(n-0.5)-(n-i)*(n-i)) ;
            b=sqrt(b) ;
            v=ceil(b) ;
            c=c+v-a ;
            x=x+n-v ;
            a=b ;
        }
        y=n*n-(c+x) ;
        printf("In the case n = %ld, %ld cells contain segments of the circle.\n",n,4*c) ;
        printf("There are %ld cells completely contained in the circle.\n",4*y) ;
        s=1 ;
    }
    return 0 ;
}
