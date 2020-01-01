#include<stdio.h>
#include<string.h>
void v1(char c)
{
    long a ;
    a=c ;
    while(a!=0)
    {
        printf("%ld",a%10) ;
        a=a/10 ;
    }
}
void v2(char a,char b)
{
    long c=10*(b-48)+(a-48) ;
    printf("%c",c) ;
}
int main()
{
    char ch[10000] ;
    while(gets(ch))
    {
        if(ch[0]>='0' && ch[0]<='9')
    }
}
