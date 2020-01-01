#include<stdio.h>
#include<string.h>

int main()
{
    long i , j , a ;
    char ch[1000] ;
    while(gets(ch))
    {
        if(strcmp(ch,"DONE")==0) break ;
        j=0 ;
        a=strlen(ch) ;
        for(i=0 ; i<a ; i++)
        {
            if((ch[i]>=97 && ch[i]<=122) || (ch[i]>=65 && ch[i]<=90))
            ch[j++]=ch[i] ;
        }
      //  strupr(ch) ;
        for(i=0 ; i<j ; i++)
        if(ch[i]>=97 && ch[i]<=122) ch[i]=ch[i]-32 ;
        j-- ;
        for(i=0 ; i<=j-i ; i++)
        {
            if(ch[i]!=ch[j-i])
            break ;
        }
        if(i>j-i) printf("You won't be eaten!\n") ;
        else printf("Uh oh..\n") ;
    }
    return 0 ;
}
