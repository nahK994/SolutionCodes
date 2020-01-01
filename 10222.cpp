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
            if(p=='=')
            printf("0") ;
            else if(p=='-')
            printf("9") ;
            else if(p=='0')
            printf("8") ;
            else if(p=='9')
            printf("7") ;
            else if(p=='8')
            printf("6") ;
            else if(p=='7')
            printf("5") ;
            else if(p=='6')
            printf("4") ;
            else if(p=='5')
            printf("3") ;
            else if(p=='4')
            printf("2") ;
            else if(p=='3')
            printf("1") ;
            else if(p=='2')
            printf("`") ;
            else if(p=='\\')
            printf("[") ;
            else if(p==']')
            printf("p") ;
            else if(p=='[')
            printf("o") ;
            else if(p=='p' || p=='P')
            printf("i") ;
            else if(p=='o' || p=='O')
            printf("u") ;
            else if(p=='i' || p=='I')
            printf("y") ;
            else if(p=='u' || p=='U')
            printf("t") ;
            else if(p=='y' || p=='Y')
            printf("r") ;
            else if(p=='t' || p=='T')
            printf("e") ;
            else if(p=='r' || p=='R')
            printf("w") ;
            else if(p=='e' || p=='E')
            printf("q") ;
            else if(p==39)
            printf("l") ;
            else if(p==';')
            printf("k") ;
            else if(p=='l' || p=='L')
            printf("j") ;
            else if(p=='k' || p=='K')
            printf("h") ;
            else if(p=='j' || p=='J')
            printf("g") ;
            else if(p=='h' || p=='H')
            printf("f") ;
            else if(p=='g' || p=='G')
            printf("d") ;
            else if(p=='f' || p=='F')
            printf("s") ;
            else if(p=='d' || p=='D')
            printf("a") ;
            else if(p=='/')
            printf(",") ;
            else if(p=='.')
            printf("m") ;
            else if(p==',')
            printf("n") ;
            else if(p=='m' || p=='M')
            printf("b") ;
            else if(p=='n' || p=='N')
            printf("v") ;
            else if(p=='b' || p=='B')
            printf("c") ;
            else if(p=='v' || p=='V')
            printf("x") ;
            else if(p=='c' || p=='C')
            printf("z") ;
            else printf("%c",p) ;
        }
        printf("\n") ;
    }
    return 0 ;
}

