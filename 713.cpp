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
    char ch1[1000] , ch2[1000] , ch3[1000] ;
    long i , a , b , big , small , f , c , e , g , h ;
    scanf("%ld",&g) ;
    for(e=1 ; e<=g ; e++)
    {
        scanf("%s%s",ch1,ch2) ;
        c=0 ;
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
            ch3[i]=(f%10)+48 ;
            c=f/10 ;
        }
        if(c!=0) ch3[i]=c+48 ;
        for(h=0 ; ch3[h]==48 ; h++)
        {

        }
        for( ; h<strlen(ch3) ; h++) printf("%c",ch3[h]) ;
        memset(ch3,0,sizeof(ch3)) ;
        printf("\n") ;
    }
    return 0 ;
}

