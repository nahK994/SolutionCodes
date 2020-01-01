#include<stdio.h>

int main()
{
    long n , b , h , w , i , A , a , cost , c ;
    while(scanf("%ld%ld%ld%ld",&n,&b,&h,&w)!=EOF)
    {
        cost=999999999 ;
        while(h--)
        {
            a=0 ;
            scanf("%ld",&A) ;
            for(i=1 ; i<=w ; i++)
            {
                scanf("%ld",&c) ;
                if(c>=n && cost>A*n) cost=A*n ;
            }
        }
        if(cost>b) printf("stay home\n") ;
        else printf("%ld\n",cost) ;
    }
    return 0 ;
}
