#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std ;

char ch[100] , ch1[100] ;

long P_TEST()
{
    long i , j=strlen(ch)-1 , a , b ;
    for(i=0 ; i<j ; i++ , j--)
        if(ch[i]!=ch[j])
            return 0 ;
    return 1 ;
}

long M_TEST()
{
    long i , j , a , b ;
    char c ;
    strcpy(ch1,ch) ;
    for(i=0 ; i<strlen(ch1) ; i++)
    {
        c=ch1[i] ;
        if(c=='E') ch1[i]='3' ;
        else if(c=='3') ch1[i]='E' ;
        else if(c=='L') ch1[i]='J' ;
        else if(c=='J') ch1[i]='L' ;
        else if(c=='S') ch1[i]='2' ;
        else if(c=='2') ch1[i]='S' ;
        else if(c=='5') ch1[i]='Z' ;
        else if(c=='Z') ch1[i]='5' ;
        else if(c=='A' || c=='H' || c=='T' || c=='U' || c=='V' || c=='W' || c=='X' || c=='M' || c=='O' || c=='Y' || c=='1' || c=='8' || c=='I') ;
        else return 0 ;
    }
    for(i=0 , j=strlen(ch1)-1 ; i<=j ; i++ , j--)
    if(ch1[j]!=ch[i])
    return 0 ;
    return 1 ;
}

int main()
{
    long i , j ;
    while(scanf("%s",ch))
    {
        i=P_TEST() ;
        j=M_TEST() ;
        printf("%s -- ",ch) ;
        if(i==1 && j==1) printf("is a mirrored palindrome.\n\n") ;
        else if(i==1 && j==0) printf("is a regular palindrome.\n\n") ;
        else if(i==0 && j==1) printf("is a mirrored string.\n\n") ;
        else printf("is not a palindrome.\n\n") ;
        memset(ch,0,sizeof(ch)) ; memset(ch1,0,sizeof(ch1)) ;
    }
    return 0 ;
}
