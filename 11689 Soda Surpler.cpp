#include<stdio.h>

int main ()

{
    int i , j ;
    scanf("%d",&j) ;
    for(i=1 ; i<=j ; i++)
    {
        int a[3]={0} , b , count=0 , n , c ;
        for(b=0 ; b<3 ; b++)
        scanf("%d",&a[b]) ;
        n=a[0]+a[1] ;
        while(n>=a[2])
        {
            c=n/a[2] ;
            count=count+c ;
            n=c+n%a[2] ;
        }
        printf("%d\n",count) ;
    }
    return 0 ;
}
