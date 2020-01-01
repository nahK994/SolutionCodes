#include<stdio.h>

int main()
{
    long i , j , k , l , m , a , b , c , d ;
    scanf("%ld",&j) ;
    for(i=1 ; i<=j ; i++)
    {
      //  printf("\n") ;
        scanf("%ld%ld",&l,&k) ;
        for(m=1 ; m<=l ; m++)
        {
            scanf("%ld%ld%ld%ld",&a,&b,&c,&d) ;
            if(((a-c)%2!=0 && (b-d)%2==0) || ((a-c)%2==0 && (b-d)%2!=0))
            printf("no move\n") ;
            else if(a==c && b==d) printf("0\n") ;
            else if(a-c-b+d==0 || a-c+b-d==0) printf("1\n") ;
            else printf("2\n") ;
        }
    }
    return 0 ;
}
