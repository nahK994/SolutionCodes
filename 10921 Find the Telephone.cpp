#include<stdio.h>
#include<string.h>

int main ()

{
    char c[100] ;
    while(gets(c))
    {
        int i , j=strlen(c) ;
        for(i=0 ; i<j ; i++)
        {
            if(c[i]>=65 && c[i]<=67)
            c[i]='2' ;
            else if(c[i]>=68 && c[i]<=70)
            c[i]='3' ;
            else if(c[i]>=71 && c[i]<=73)
            c[i]='4' ;
            else if(c[i]>=74 && c[i]<=76)
            c[i]='5' ;
            else if(c[i]>=77 && c[i]<=79)
            c[i]='6' ;
            else if(c[i]>=80 && c[i]<=83)
            c[i]='7' ;
            else if(c[i]>=84 && c[i]<=86)
            c[i]='8' ;
            else if(c[i]>=87 && c[i]<=90)
            c[i]='9' ;
        }
        printf("%s\n",c) ;
        c[100]={0} ;
    }
    return 0 ;
}
