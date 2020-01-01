#include<stdio.h>

int main()
{
    long a , i , j , test ;
    char ch[20] ;
    scanf("%ld",&test) ;
    while(test--)
    {
        scanf("%s",ch) ;
        a=(ch[7]-48)+10*(ch[6]-48)+100*(ch[5]-48)+1000*(ch[4]-48) ;
        j=26*26*(ch[0]-65)+26*(ch[1]-65)+(ch[2]-65) ;
        if(a>j && a-j<=100) printf("nice\n") ;
        else if(a<j && j-a<=100) printf("nice\n") ;
        else printf("not nice\n") ;
    }
    return 0 ;
}
