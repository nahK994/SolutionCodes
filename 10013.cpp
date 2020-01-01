#include<stdio.h>
#include<string.h>

char rev(char ch[1000])

{
    long a , b ;
    char c ;
    for(a=0,b=strlen(ch) ; a<b ; a++,b--)
    {
        c=ch[b-1] ;
        ch[b-1]=ch[a] ;
        ch[a]=c ;
    }
    return ch[1000] ;
}

int main ()

{
    char ch1[1000000] , ch2[1000000] , cc ;
    long i , a , b , f , c , d , j , k , l , m ;
    scanf("%ld",&k) ;
    for(j=1 ; j<=k ; j++)
    {
        scanf("%ld",&l) ;
        for(m=0 ; m<l ; m++)
        {
            scanf("%c",&ch1[m]) ;
            getchar() ;
            scanf("%c",&ch1[m]) ;
        }
        printf("%c %c",ch1[0],ch2[0]) ;
        c=0 ;
        ch1[1000000]=rev(ch1) ;
        ch2[1000000]=rev(ch2) ;
        for(i=0 ; i<l ; i++)
        {
            f=(ch1[i]+ch2[i]-96)+c ;
            ch2[i]=(f%10)+48 ;
            c=f/10 ;
        }
        if(c!=0) ch2[i]=c+48 ;

    for(d=strlen(ch2)-1 ; ch2[d]==48 ; d--)
    {

    }
    for(; d>=0 ; d--) printf("%c",ch2[d]) ;
    printf("\n") ;
    }
    return 0 ;
}

