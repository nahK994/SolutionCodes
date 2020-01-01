#include<stdio.h>
#include<string.h>

int main()
{
    long loop=0 , test , i , j , a ;
    char ch[][50]={"HELLO" , "HOLA" , "HALLO" , "BONJOUR" , "CIAO" , "ZDRAVSTVUJTE"} , ch1[100] ;
    scanf("%ld",&test) ;
    for( ; scanf("%s",ch1) && strcmp(ch1,"#")!=0 ; )
    {
        a=0 ;
        printf("Case %ld: ",++loop) ;
        if(strcmp(ch1,ch[0])==0) printf("ENGLISH\n") ;
        else if(strcmp(ch1,ch[1])==0) printf("SPANISH\n") ;
        else if(strcmp(ch1,ch[2])==0) printf("GERMAN\n") ;
        else if(strcmp(ch1,ch[3])==0) printf("FRENCH\n") ;
        else if(strcmp(ch1,ch[4])==0) printf("ITALIAN\n") ;
        else if(strcmp(ch1,ch[5])==0) printf("RUSSIAN\n") ;
        else printf("UNKNOWN\n") ;
    }
    return 0 ;
}
