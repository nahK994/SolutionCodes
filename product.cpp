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

char add(char ch1[1000],char ch2[1000])

{
    long i , a , b , big , small , f , c , d ;
    char ch3[1000] ;
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
    return ch3[1000] ;
}

int main ()

{
    char ch1[1000] , ch2[1000] , ch3[1000] ;
    gets(ch1) ;
    gets(ch2) ;
    ch3[1000]=add(ch1,ch2) ;
    ch3[1000]=rev(ch3) ;
    printf("%s\n",ch3) ;
    return 0 ;
}
