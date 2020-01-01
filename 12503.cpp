#include<stdio.h>
#include<string.h>

int main()
{
    long loop , test , a , i , j , b , c , order , ara[1000] ;
    char ch[100] ;
    scanf("%ld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        scanf("%ld",&order) ;
        char s=getchar() ;
        a=0 ;
        for(i=1 ; i<=order ; i++)
        {
             gets(ch) ;
             if(ch[0]=='L')
             {
                  a-=1 ; ara[i]=-1 ;
             }
             else if(ch[0]=='R')
             {
                  a+=1 ; ara[i]=1 ;
             }
             else
             {
                 j=0 ; c=8 ;
                 while(ch[c])
                 {
                     j=10*j+(ch[c]-48) ;
                     c++ ;
                 }
                 ara[i]=ara[j] ;
                 a+=ara[i] ;
             }
        }
        memset(ara,0,sizeof(ara)) ;
        printf("%ld\n",a) ;
    }
    return 0 ;
}
