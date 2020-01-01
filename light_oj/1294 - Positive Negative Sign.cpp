#include<stdio.h>

int main()
{
    long loop , test , m , n , a , b , c ;
    scanf("%ld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        scanf("%ld%ld",&n,&m) ;
        a=m*m*(n/(2*m)) ;
        if(n%(2*m))
        {
            b=n%(2*m) ;
            c=n-b ;
            if(c+m<n)
            {
                a=a-((c+m)*(c+m+1)/2)+c*(c+1)/2 ;
                c+=m ;
                a=a+(n*(n+1)/2)-(c*(c+1)/2) ;
            }
            else
            {
                a=a-(n*(n+1)/2)+(c*(c+1)/2) ;
            }

        }
        printf("Case %ld: %ld\n",loop,a) ;
    }
    return 0 ;
}
