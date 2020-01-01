#include<stdio.h>
#include<string.h>

long htod(char ch[])
{
    long c=1 , sum=0 , j=strlen(ch) ;
    for(j=j-1 ; j>=0 ; j--)
    {
        if(ch[j]>=48 && ch[j]<=57) sum=sum+(ch[j]-48)*c ;
        else sum=sum+(ch[j]-55)*c ;
        c=16*c ;
    }
    return sum ;
}

void dtob(char *ch , long n)
{
    long i , j=0 ;
    char a ;
    for(i=0 ; i<13 ; i++)
        ch[i]='0' ;
    while(n!=0)
    {
        if(n%2!=0)
            ch[j]='1' ;
        n=n/2 ;
        j++ ;
    }
    for(i=0 ; i<12-i ; i++)
    {
        a=ch[i] ;
        ch[i]=ch[12-i] ;
        ch[12-i]=a ;
    }
    ch[13]='\0' ;
}

int main()
{
    long i , j , a , b , c ;
    char ch1[1000] , ch2[1000] , ch , temp ;
    scanf("%ld ",&j) ;
    for(i=1 ; i<=j ; i++)
    {
        scanf("%s %c %s",ch1,&ch,ch2) ;
        a=htod(ch1) ;
        b=htod(ch2) ;
        if(ch=='+') c=a+b ;
        else c=a-b ;
        dtob(ch1,a) ;
        dtob(ch2,b) ;
        printf("%s %c %s = %ld\n",ch1,ch,ch2,c) ;
    }
    return 0 ;
}
