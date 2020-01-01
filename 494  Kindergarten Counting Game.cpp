#include<stdio.h>
#include<string.h>

int main ()

{
    char c[100000] ;
    while(gets(c))
    {
        long i , j , count=0 ;
        j=strlen(c) ;
        for(i=0 ; i<j-1 ; i++)
        {
         if(((c[i]<'a' && c[i]>'Z') || (c[i]<'A' && c[i]>'\0') || (c[i]<'z' && c[i]>=127)) && ((c[i+1]>='a' && c[i+1]<='z') || (c[i+1]>='A' && c[i+1]<='Z')))
         count++ ;
        }
        if((c[0]>='a' && c[0]<='z') || (c[0]>='A' && c[0]<='Z'))
        printf("%ld\n",++count) ;
        else printf("%ld\n",count) ;
        c[100000]={0} ;
    }
    return 0 ;
}
