#include<stdio.h>

int main ()

{
    int i , j ;
    scanf("%d",&j) ;
    for(i=1 ; i<=j ; i++)
    {
        int n , k , p ;
        scanf("%d%d%d",&n,&k,&p) ;
        if(k+p!=n && (k+p)%n!=0) printf("Case %d: %d\n",i,(k+p)%n) ;
        else printf("Case %d: %d\n",i,n) ;
    }
    return 0 ;
}
