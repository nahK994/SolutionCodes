#include<stdio.h>
#include<string.h>

char ch[10][10] ;
long row[15][15] , col[15][15] , board[15][15][15] , finish ;

void rec()
{
    long i , j , a=-1 , b=-1 , c , max1=0 , count1 , count_finish=0 ;

    for(i=0 ; i<9 ; i++)
        for(j=0 ; j<9 ; j++)
        {
            count1=0 ;
            if(ch[i][j]=='.')
            {
                count_finish++ ;
                for(c=1 ; c<=9 ; c++)
                    if(row[i][c]==1 || col[j][c]==1 || board[i/3][j/3][c]==1)
                        count1++ ;
                if(max1<count1)
                {
                    max1=count1 ;
                    a=i ;
                    b=j ;
                }
            }
        }

    if(count_finish==0)
    {
        finish=1 ;
        return ;
    }
    if(a==-1) return ;

    for(c=1 ; c<=9 && finish==0 ; c++)
        if(row[a][c]==0 && col[b][c]==0 && board[a/3][b/3][c]==0)
        {
            row[a][c]=col[b][c]=board[a/3][b/3][c]=1 ;
            ch[a][b]=c+48 ;

            /*printf("\n\n%ld  %ld   %ld\n",a,b,max1) ;
            for(long ii=0 ; ii<9 ; ii++)
                puts(ch[ii]) ;
            char ss=getchar() ;*/
            rec() ;
            if(finish==0)
            {
                row[a][c]=col[b][c]=board[a/3][b/3][c]=0 ;
                ch[a][b]='.' ;
            }
        }
}

int main()
{
    long loop , test , n , a , b , i , j ;
    scanf("%ld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        for(i=0 ; i<9 ; i++)
            scanf("%s",ch[i]) ;

        for(i=0 ; i<9 ; i++)
        {
            memset(row[i],0,sizeof(row[i])) ;
            memset(col[i],0,sizeof(col[i])) ;
        }

        for(i=0 ; i<3 ; i++)
            for(j=0 ; j<3 ; j++)
                memset(board[i][j],0,sizeof(board[i][j])) ;

        for(i=0 ; i<9 ; i++)
            for(j=0 ; j<9 ; j++)
                if(ch[i][j]!='.')
                    row[i][ch[i][j]-48]=col[j][ch[i][j]-48]=board[i/3][j/3][ch[i][j]-48]=1 ;

        finish=0 ;
        rec() ;
        printf("Case %ld:\n",loop) ;
        for(i=0 ; i<9 ; i++)
            puts(ch[i]) ;
    }
    return 0 ;
}
