#include<stdio.h>
#include<string.h>

long ntod(char ch[] , long n)
{
    long c=1 , sum=0 , j=strlen(ch) ;
    for(j=j-1 ; j>=0 ; j--)
    {
        if(ch[j]>=48 && ch[j]<=57) sum=sum+(ch[j]-48)*c ;
        else sum=sum+(ch[j]-55)*c ;
        c=n*c ;
    }
    return sum ;
}

void dton(char *ch , long n , long b)
{
    if(n==0)
    {
        ch[0]='0' ;
        ch[1]='\0' ;
        return ;
    }
    long i , j=0 , c , d ;
    char a ;
    while(n!=0)
    {
        d=n%b ;
        if(d>=0 && d<=9)
            ch[j]=d+48 ;
        else
            ch[j]=d+55 ;
        n=n/b ;
        j++ ;
    }
    ch[j]='\0' ;
    c=strlen(ch) ;
    c-- ;
    for(i=0 ; i<c-i ; i++)
    {
        a=ch[i] ;
        ch[i]=ch[c-i] ;
        ch[c-i]=a ;
    }
}

int main()
{
    long decimal , j , a , b ;
    char ch[1000] ;
    while(scanf(" %s%ld%ld",ch,&a,&b)!=EOF)
    {
        decimal=ntod(ch,a) ;
        dton(ch,decimal,b) ;
        if(strlen(ch)>7) printf("  ERROR\n") ;
        else printf("%7s\n",ch) ;
    }
    return 0 ;
}
