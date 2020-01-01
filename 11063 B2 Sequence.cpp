#include<stdio.h>

int main ()

{
    long n , ara[1000] , i , a , b , c , d , e=1 , sum ;
    while(scanf("%ld",&n)!=EOF)
    {
        d=0 ;
        sum=0 ;
        for(i=0 ; i<n ; i++) scanf("%ld",&ara[i]) ;
        for(a=0 ; a<n-2 ; a++)
        {
            for(b=a+1 ; b<n-1 ; b++)
            {
                sum=ara[a]+ara[b] ;
                {
                    for(c=b+1 ; c<n ; c++)
                        if(sum>=ara[c]) d=1 ;
                }
            }
        }
        if(d==0) printf("Case #%ld: It is a B2-Sequence.\n\n",e) ;
        else printf("Case #%ld: It is not a B2-Sequence.\n\n",e) ;
        e++ ;
        //ara[1000]={0} ;
    }
    return 0 ;
}
