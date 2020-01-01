#include<stdio.h>
#include<string.h>

long one(char ch[])
{
    long j=strlen(ch) , i , count=0 ;
    char c1[]="one" ;
    for(i=0 ; i<j ; i++)
    if(ch[i]==c1[i]) count++ ;
    return count ;
}

int main()
{
    long i , j ;
    char ch[10] ;
    scanf("%ld",&j) ;
    char c=getchar() ;
    for(i=1 ; i<=j ; i++)
    {
        gets(ch) ;
        if(strlen(ch)==5)
        printf("3\n") ;
        else if(one(ch)>=2)
        printf("1\n") ;
        else printf("2\n") ;
    }
    return 0 ;
}
