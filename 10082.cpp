#include<stdio.h>
#include<string.h>

int main()
{
    char ch[1000] , p ;
    long i , j , a ;
    /*p=getchar() ;
    printf("%ld\n",p) ;*/
    while(gets(ch))
    {
        for(i=0 ; i<strlen(ch) ; i++)
        {
            p=ch[i] ;
            if(p>=50 && p<=57)
            printf("%c",p-1) ;
            else if(p=='0')
            printf("9") ;
            else if(p=='-')
            printf("0") ;
            else if(p=='[')
            printf("P") ;
            else if(p=='P')
            printf("O") ;
            else if(p=='O')
            printf("I") ;
            else if(p=='I')
            printf("U") ;
            else if(p=='U')
            printf("Y") ;
            else if(p=='Y')
            printf("T") ;
            else if(p=='T')
            printf("R") ;
            else if(p=='R')
            printf("E") ;
            else if(p=='E')
            printf("W") ;
            else if(p=='W')
            printf("Q") ;
            else if(p==';')
            printf("L") ;
            else if(p=='L')
            printf("K") ;
            else if(p=='K')
            printf("J") ;
            else if(p=='J')
            printf("H") ;
            else if(p=='H')
            printf("G") ;
            else if(p=='G')
            printf("F") ;
            else if(p=='F')
            printf("D") ;
            else if(p=='D')
            printf("S") ;
            else if(p=='S')
            printf("A") ;
            else if(p=='/')
            printf(".") ;
            else if(p=='.')
            printf(",") ;
            else if(p==',')
            printf("M") ;
            else if(p=='M')
            printf("N") ;
            else if(p=='N')
            printf("B") ;
            else if(p=='B')
            printf("V") ;
            else if(p=='V')
            printf("C") ;
            else if(p=='C')
            printf("X") ;
            else if(p=='X')
            printf("Z") ;
            else if(p==39)
            printf(";") ;
            else if(p=='1')
            printf("`") ;
            else if(p==']')
            printf("[") ;
            else if(p==92)
            printf("]") ;
            else if(p=='=')
            printf("-") ;
            /*else if(p==10)
            printf("%c",39) ;*/
            else printf("%c",p) ;
        }
        printf("\n") ;
    }
    return 0 ;
}
