#include<stdio.h>
#include<string.h>

int main()
{
    char ch[1000] ;
    long i , sum , a , test ;
    scanf("%ld",&test) ;
    while(test--)
    {
        a=sum=0 ;
        scanf("%s",ch) ;
        for(i=0 ; i<strlen(ch) ; i++)
        {
            if(ch[i]=='X')
            {
               // printf("%c\n",ch[i]) ;
                sum+=a*(a+1)/2 ; a=0 ;
            }
            else
            {
                a++ ;
              //  printf("%c\n",ch[i]) ;
            }
        }
        sum+=a*(a+1)/2 ;
        printf("%ld\n",sum) ;
    }
    return 0 ;
}
