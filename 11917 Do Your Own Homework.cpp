#include<stdio.h>
#include<string.h>

int main()
{
    long loop , test , a , i , D , ara[100] ;
    char ch[100] , ques[1000][100] ;
    scanf("%ld",&test) ;
    char q=getchar() ;
    for(loop=1 ; loop<=test ; loop++)
    {
        scanf("%ld",&a) ;
        for(i=0 ; i<a ; i++)
        {
            scanf("%s %ld",ch,&ara[i]) ;
            strcpy(ques[i],ch) ;
            //printf("%s %ld\n",ch,ara[i]) ;
        }
        ques[i][0]='\0' ;
        scanf("%ld",&D) ;
        q=getchar() ;
        gets(ch) ;
        for(i=0 ; i<a ; i++)
        if(strcmp(ques[i],ch)==0)
        {
            if(ara[i]<=D) printf("Case %ld: Yesss\n",loop) ;
            else if(ara[i]<=D+5) printf("Case %ld: Late\n",loop) ;
            else printf("Case %ld: Do your own homework!\n",loop) ;
            break ;
        }
        if(i==a) printf("Case %ld: Do your own homework!\n",loop) ;
        memset(ara,0,sizeof(ara)) ;
        for(i=0 ; i<a ; i++) memset(ques[i],0,sizeof(ques[i])) ;
    }
    return 0 ;
}
