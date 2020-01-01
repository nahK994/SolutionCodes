#include<stdio.h>
#include<string.h>

int main()
{
    char ch[10] , a ;
    long i , j , count=0 , c ;
    scanf("%ld",&j) ;
    a=getchar() ;
    for(i=1 ; i<=j ; i++)
    {
        scanf("%s",ch) ;
        if(strcmp(ch,"donate")==0)
        {
            scanf("%ld",&c) ;
            count=count+c ;
        }
        else printf("%ld\n",count) ;
    }
    return 0 ;
}
