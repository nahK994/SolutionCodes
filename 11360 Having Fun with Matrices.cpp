#include<stdio.h>
#include<string.h>

int main()
{
    long m , i , j , loop , test , n , ara[50][50] , b , a ;
    char ch[100] ;
    scanf("%ld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        scanf("%ld",&n) ;
        for(i=0 ; i<n ; i++)
        {
            scanf("%s",ch) ;
            for(j=0 ; j<n ; j++)
                ara[i][j]=ch[j]-48 ;
        }
        scanf("%ld",&m) ;
        char g=getchar() ;
        while(m--)
        {
            gets(ch) ;
            if(ch[0]=='t')
            {
                for(i=0 ; i<n ; i++)
                    for(j=i ; j<n ; j++)
                    {
                        b=ara[i][j] ;
                        ara[i][j]=ara[j][i] ;
                        ara[j][i]=b ;
                    }
            }
            else if(ch[0]=='i')
            {
                for(i=0 ; i<n ; i++)
                    for(j=0 ; j<n ; j++)
                        ara[i][j]=(ara[i][j]+1)%10 ;
            }
            else if(ch[0]=='d')
            {
                for(i=0 ; i<n ; i++)
                    for(j=0 ; j<n ; j++)
                        if(ara[i][j]-1==-1) ara[i][j]=9 ;
                        else ara[i][j]-- ;
            }
            else if(ch[0]=='r')
            {
                /*sscanf(ch,"%*s %ld %ld",&a,&b) ;
                a-- ;
                b-- ;*/
                a=ch[4]-49 ; b=ch[6]-49 ;
                for(i=0 ; i<n ; i++)
                {
                    j=ara[a][i] ;
                    ara[a][i]=ara[b][i] ;
                    ara[b][i]=j ;
                }
            }
            else
            {
                /*sscanf(ch,"%*s %ld %ld",&a,&b) ;
                a-- ;
                b-- ;*/
                a=ch[4]-49 ; b=ch[6]-49 ;
                for(i=0 ; i<n ; i++)
                {
                    j=ara[i][a] ;
                    ara[i][a]=ara[i][b] ;
                    ara[i][b]=j ;
                }
            }
        }
        printf("Case #%ld\n",loop) ;
        for(i=0 ; i<n ; i++)
            for(j=0 ; j<n ; j++)
                if(j!=n-1) printf("%ld",ara[i][j]) ;
                else printf("%ld\n",ara[i][j]) ;
        printf("\n") ;
        for(i=0 ; i<n ; i++) memset(ara[i],0,sizeof(ara[i])) ;
    }
    return 0 ;
}
