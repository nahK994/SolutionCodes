#include<stdio.h>

int main ()

{
    long i , j , x , y , a , b ;
    scanf("%ld",&j) ;
    for(i=1 ; i<=j ; i++)
    {
        scanf("%ld%ld",&x,&y) ;
        if(x<y || (x%2==0 && y%2!=0) || (x%2!=0 && y%2==0))
        {
            printf("impossible\n") ;
            continue ;
        }
        a=(x+y)/2 ;
        b=(x-y)/2 ;
        printf("%ld %ld\n",a,b) ;
    }
    return 0 ;
}
