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
    char ch1[1000000] , ch2[1000000]={'0'} ;
    long i , a , b , big , small , f , c , d ;
    while(gets(ch1))
    {
        if(strlen(ch1)==1 && ch1[0]==48) break ;
        c=0 ;
        ch1[1000]=rev(ch1) ;
        a=strlen(ch1) ;
        b=strlen(ch2) ;
        if(a>b)
        {
            big=a ;
            small=b ;
        }
        else
        {
            big=b ;
            small=a ;
        }
        for(i=0 ; i<big ; i++)
        {
            if(i<small) f=(ch1[i]+ch2[i]-96)+c ;
            else if(a>b) f=(ch1[i]-48)+c ;
            else f=(ch2[i]-48)+c ;
            ch2[i]=(f%10)+48 ;
            c=f/10 ;
        }
        if(c!=0) ch2[i]=c+48 ;
    }
    for(d=strlen(ch2)-1 ; ch2[d]==48 ; d--)
    {

    }
    for(; d>=0 ; d--) printf("%c",ch2[d]) ;
    printf("\n") ;
    return 0 ;
}
