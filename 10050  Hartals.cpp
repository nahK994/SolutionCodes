#include<stdio.h>
#include<string.h>

int main()
{
    long test , party , h , days[4000] , N , j , a , i ;
    scanf("%ld",&test) ;
    while(test--)
    {
        scanf("%ld%ld",&N,&party) ;
        for(j=1 ; j<=N ; j++) days[j]=0 ;
        while(party--)
        {
            scanf("%ld",&a) ;
            for(i=0 ; i<=N ; i+=a) days[i]=1 ;
        }
        a=0 ;
        for(i=1 ; i<=N ; i++)
        if(days[i]==1 && i%7!=0 && (i+1)%7!=0)
        a++ ;
        printf("%ld\n",a) ;
        memset(days,0,sizeof(days)) ;
    }
    return 0 ;
}
