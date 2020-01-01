#include<stdio.h>
#include<math.h>

int main ()

{
    long a , b , i , c , count=0 ;
    while(scanf("%ld%ld",&a,&b)!=EOF)
        {
            if(a==0 && b==0)
            break ;
            count=0 ;
            for( i=a ; i<=b ; i++ )
                 {
                     c=sqrt(i) ;
                     if(i==c*c)
                     count++ ;
                 }
            printf("%ld\n",count) ;
        }
    return 0 ;
}
