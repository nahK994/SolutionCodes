#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

char ch[10000] , ch1[10000] , cha[1000][200] ;
long length , taken[10000] , color[200] , Count ;
vector<char>V ;

void rec()
{
    long i , j ;
    if(V.size()==length)
    {
        for(i=0 ; i<length ; i++)

        printf("%c",V[i]) ;
        printf("\n") ;
        return ;
    }
    for(i=0 ; i<length ; i++)
    {
        if(taken[i]==0)
        {
            j=ch[i] ;
            //if(V.size()==0 && color[j]==1) continue ;
            taken[i]=1 ;
            if(V.size()==0) color[j]=1 ;
            V.push_back(ch[i]) ;
            rec() ;
            taken[i]=0 ;
            V.pop_back() ;
        }
    }
}

int main()
{
    long test , a , ara[200] , i , b ;
    char c ;
    scanf("%ld\n",&test) ;
    while(test--)
    {
        scanf("%s",ch1) ;
        length=strlen(ch1) ;
        for(i=0 ; i<length ; i++) taken[i]=0 ;
        for(i=0 ; i<200 ; i++) color[i]=0 ;
        for(i=65 ; i<=90 ; i++) ara[i]=0 ;
        for(i=97 ; i<=122 ; i++) ara[i]=0 ;
        for(i=0 ; i<length ; i++)
        {
            a=ch1[i] ;
            ara[a]++ ;
        }
        a=0 ;
        for(i=0 ; i<length ; )
        {
            while(ara[a+65]==0 && ara[a+97]==0)
                a++ ;
            if(ara[a+65]!=0)
            {
                for(b=0 ; b<ara[a+65] ; b++)
                    ch[i+b]=a+65 ;
                i+=ara[a+65] ;
            }
            if(ara[a+97]!=0)
            {
                for(b=0 ; b<ara[a+97] ; b++)
                    ch[i+b]=a+97 ;
                i+=ara[a+97] ;
            }
            a++ ;
        }
        ch1[0]='\0' ;
        ch[length]='\0' ;
        Count=0 ;
        //printf("%s %s\n",ch1,ch) ;
        rec() ;

        memset(ara,0,sizeof(ara)) ;
        memset(ch,0,sizeof(ch)) ;
        memset(ch1,0,sizeof(ch1)) ;
        memset(taken,0,sizeof(taken)) ;
        memset(color,0,sizeof(color)) ;
    }
    return 0;
}
