#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char ch1[100000] , ch2[100000] , ch , ans[100000] , ans1[100000] ;
    long long a , b , i ,  j ;
    while(scanf("%s %c %s",ch1,&ch,ch2)!=EOF)
    {
        a=2147483649 ; b=2147483649 ;
        printf("%s %c %s\n",ch1,ch,ch2) ;
        for(i=0 ; ch1[i]==48 && i<strlen(ch1) ; i++) ;
        j=0 ;
        while(i<strlen(ch1))
        {
            ans[j++]=ch1[i++] ;
        }
        ans[j]='\0' ;
        for(i=0 ; ch2[i]==48 && i<strlen(ch2) ; i++) ;
        j=0 ;
        while(i<strlen(ch2))
        {
            ans1[j++]=ch2[i++] ;
        }
        ans1[j]='\0' ;
        if((strcmp(ans,"2147483647")!=1 && strlen(ans)==strlen("2147483647")) || strlen(ans)<strlen("2147483647")) a=atol(ans) ;
        else printf("first number too big\n") ;
        if((strcmp(ans1,"2147483647")!=1 && strlen(ans1)==strlen("2147483647")) || strlen(ans1)<strlen("2147483647")) b=atol(ans1) ;
        else printf("second number too big\n") ;
        if(((a+b)>2147483647 && ch=='+') || ((a*b)>2147483647 && ch=='*')) printf("result too big\n") ;
    }
    return 0 ;
}
