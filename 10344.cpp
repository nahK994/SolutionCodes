#include<stdio.h>
#include<string.h>
long ara[6] , flag , color[6] , row_color[6][55] ;

void rec(long a , long sum)
{
    if(sum == 23 && a == 5)
    {
        flag=1 ;
        return ;
    }
    if(flag || a==5) return ;

    for(long i=0 ; i<5 ; i++)
        if(!color[i] && !row_color[a][ara[i]])
        {
            color[i]=row_color[a][ara[i]]=1 ;

            rec(a+1,sum+ara[i]) ;
            rec(a+1,sum-ara[i]) ;
            rec(a+1,sum*ara[i]) ;

            color[i]=0 ;
        }
    memset(row_color[a],0,sizeof row_color[a]) ;

}

int main()
{
    memset(color,0,sizeof color) ;
    memset(row_color,0,sizeof row_color) ;
    while(scanf("%ld%ld%ld%ld%ld",&ara[0],&ara[1],&ara[2],&ara[3],&ara[4]) != EOF)
    {
        if(ara[0] == 0 && ara[1] == 0 && ara[2] == 0 && ara[3] == 0 && ara[4] == 0)
            break ;
        flag=0 ;
        for(long a=0 ; a<5 ; a++)
        {
            if(!color[a] && !row_color[0][ara[a]])
            {
                color[a]=row_color[0][ ara[a] ]=1 ;
                rec(1,ara[a]) ;
                color[a]=0 ;
            }
            if(flag) break ;
        }
        memset(row_color[0],0,sizeof row_color[0]) ;
        if(flag)
            printf("Possible\n") ;
        else printf("Impossible\n") ;
    }
}
