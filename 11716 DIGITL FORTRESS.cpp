#include<stdio.h>
#include<string.h>
#include<math.h>

int main ()

{
    long i , j , n , a , b , c ;
    scanf("%ld",&j) ;
    for(i=1 ; i<=j ; i++)
    {
        char ch[10000] ;
        gets(ch) ;
        n=strlen(ch) ;
        a=sqrt(n) ;
        if(a*a!=n) printf("INVALID\n") ;
        else
        {
            for(b=0 ; b<a ; b++)
            for(c=b ; c<n ; c=c+a)
            printf("%c",ch[c]) ;
            printf("\n") ;
        }
    }
    return 0 ;
}
