#include<stdio.h>
#include<string.h>

int main()

{
    long i , j , a , b , c , d ;
    scanf("%ld",&j) ;
    for(i=1 ; i<=j ; i++)
    {
        char ch[1000] ;
        scanf("%s",ch) ;
        b=strlen(ch) ;
        printf("Case %ld: ",i) ;
        for(a=0 ; a<b ; )
        {
               // printf("R\n") ;
                if((ch[a+1]>=48 && ch[a+1]<=57) && (ch[a+2]>=48 && ch[a+2]<=57) && (ch[a+3]>=48 && ch[a+3]<=57))
                {
                   // printf("E\n") ;
                    c=100*(ch[a+1]-48)+10*(ch[a+2]-48)+(ch[a+3]-48) ;
                    for(d=1 ; d<=c ; d++)
                    printf("%c",ch[a]) ;
                    a=a+4 ;
                }
                else if((ch[a+1]>=48 && ch[a+1]<=57) && (ch[a+2]>=48 && ch[a+2]<=57))
                {
                    //printf("Q\n") ;
                    c=10*(ch[a+1]-48)+(ch[a+2]-48) ;
                    for(d=1 ; d<=c ; d++)
                    printf("%c",ch[a]) ;
                    a=a+3 ;
                }
                else if((ch[a+1]>=48 && ch[a+1]<=57))
                {
                    //printf("W\n") ;
                    c=ch[a+1]-48 ;
                    for(d=1 ; d<=c ; d++)
                    printf("%c",ch[a]) ;
                    a=a+2 ;
                }

        }
        printf("\n") ;
    }
    return 0 ;
}
