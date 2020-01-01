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

long legal(char *ch , long a)
{
    long i , j=strlen(ch) ;
    for(i=0 ; i<j ; i++)
    if(ch[i]>=48 && ch[i]<=57 && a<=ch[i]-48) return 0 ;
    else if(a<=ch[i]-55) return 0 ;
    return 1 ;
}

int main()
{
    long decimal , j , a , b , e ;
    char ch[1000] ;
    while(scanf("%ld%ld %s",&a,&b,ch)!=EOF)
    {
        e=legal(ch,a) ;
        if(e==0)
        {
            printf("%s is an illegal base %ld number\n",ch,a) ;
            continue ;
        }
        printf("%s base %ld = ",ch,a) ;
        decimal=ntod(ch,a) ;
        dton(ch,decimal,b) ;
        printf("%s base %ld\n",ch,b) ;
    }
    return 0 ;
}

