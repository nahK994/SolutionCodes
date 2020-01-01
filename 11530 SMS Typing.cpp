#include<stdio.h>
#include<string.h>

int main ()

{
    long i , j ;
    scanf("%ld",&j) ;
    getchar() ;
    for(i=1 ; i<=j ; i++)
    {
        long a , b , c , count=0 ;
        char ch[1000] ;
        gets(ch) ;
        c=strlen(ch) ;
        for(b=0 ; b<c ; b++)
        if(ch[b]==' ') count++ ;
        else if(ch[b]<'s') count=count+((ch[b]-97)%3)+1 ;
        else if(ch[b]=='s' || ch[b]=='z') count=count+4 ;
        else if(ch[b]=='v' || ch[b]=='y') count=count+3 ;
        else count=count+((ch[b]-97)%3) ;
        printf("Case #%ld: %ld\n",i,count) ;
    }
    return 0 ;
}
