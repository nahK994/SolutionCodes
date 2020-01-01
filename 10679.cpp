#include<stdio.h>
#include<string.h>

int main()
{
    long test , i , a , flag , j ;
    char ch[100010] , v , ch1[1010] ;
    scanf("%ld",&test) ;
    v=getchar() ;
    while(test--)
    {
        gets(ch) ;
        scanf("%ld",&a) ;
        //printf("%s\n",ch) ;
        v=getchar() ;
        while(a--)
        {
            flag=0 ;
            gets(ch1) ;
            i=0 ;
            while(i<strlen(ch))
            {
                while(ch[i]!=ch1[0]) i++ ;
                j=0 ;
                while(ch[i]==ch1[j] && i<strlen(ch) && j<strlen(ch1))
                {
                    i++ ;
                    j++ ;
                }
                if(j==strlen(ch1))
                {
                    flag=1 ;
                    break ;
                }
            }
            if(flag) printf("y\n") ;
            else printf("n\n") ;
        }
    }
}
