#include<stdio.h>

int main ()

{
    long i , j , n , p , q , ara[1000] , a , b , c , s , aa ;
    scanf("%ld",&j) ;
    for(i=1 ; i<=j ; i++)
    {
        c=0 ;
        s=0 ;
        scanf("%ld%ld%ld",&n,&p,&q) ;
        for(a=0 ; a<n ; a++)
        scanf("%ld",&ara[a]) ;
        for(aa=0 ; aa<n ; aa++)
        {
            if(ara[aa]>q) break ;
            s=s+ara[aa] ;
            if(s>q || c>p) break ;
            c++ ;
           /* if(s+ara[aa]<=q and c+1<=p)
            {
                s+=ara[aa];
                c++;
            }*/
        }
        if(c>p) c-- ;
        printf("Case %ld: %ld\n",i,c) ;
    }
    return 0 ;
}
