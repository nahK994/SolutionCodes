#include<stdio.h>

int main ()

{
    long i , j ;
    scanf("%ld",&j) ;
    for(i=1 ; i<=j ; i++)
    {
        long n ;
        long long p=1 , a=1 ;
        char c[1000]={0} ;
        scanf("%ld",&n) ;
        if(n==0) printf("Case #%ld: 0\n",i) ;
        else
          {
            while(n!=0)
             {
               p=2*p ;
               if(n%p!=0) c[a]=49 ;
               else c[a]=48 ;
               if(n%p==0) n=n ;
               else if(a%2!=0) n=n-p/2 ;
               else if(a%2==0) n=n+p/2 ;
               a++ ;
             }
             a-- ;
             printf("Case #%ld: ",i) ;
             for( ; a>=1 ; a--)
             printf("%c",c[a]) ;
             printf("\n") ;
           }
    }
    return 0 ;
}

