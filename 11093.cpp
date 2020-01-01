#include<stdio.h>
#include<string.h>
int main()
{
    long loop , test , n , a , i , ara[200010] , lagbe , pabo , ans , lagbe1 , pabo1 ;
    scanf("%ld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        memset(ara,0,sizeof(ara)) ;
        lagbe=pabo=lagbe1=pabo1=0 ; ans=-1 ;
        scanf("%ld",&n) ;
        for(i=0 ; i<2*n ; i++)
        scanf("%ld",&ara[i]) ;
        for(i=0 ; i<n ; i++)
        {
            pabo+=ara[i] ; lagbe+=ara[i+n] ;
            if(pabo1+ara[i]>=lagbe1+ara[i+n] && ans==-1)
            {
                ans=i+1 ; pabo1+=ara[i] ; lagbe1+=ara[i+n] ;
            }
            else if(pabo1+ara[i]<lagbe1+ara[i+n])
            {
                ans=-1 ; lagbe1=pabo1=0 ;
            }
            else
            {
                pabo1+=ara[i] ; lagbe1+=ara[i+n] ;
            }
        }
        if(lagbe>pabo) printf("Case %ld: Not possible\n",loop) ;
        else printf("Case %ld: Possible from station %ld\n",loop,ans) ;
    }
    return  0 ;
}
