#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std ;

long dis_F[500][500] , dis_J[500][500] , row , col ;
char ch[500][500] ;
struct node
{
    long a , b ;
} aa ;
queue<struct node>Q ;

void J_bfs()
{
    long a , b , i , j ;

    for(i=0 ; i<row ; i++)
        for(j=0 ; j<col ; j++)
            if(ch[i][j]=='J')
            {
                a=i ;
                b=j ;
                i=row ;
                break ;
            }

             dis_J[a][b]=0 ;
                ch[a][b]='a' ;
                aa.a=a ;
                aa.b=b ;
                Q.push(aa) ;

    while(!Q.empty())
    {
        // printf("K\n") ;
        aa=Q.front() ;
        Q.pop() ;
        i=aa.a ;
        j=aa.b ;
        if(i-1>=0)
            if(ch[i-1][j]=='.')
            {
                ch[i-1][j]='a' ;
                dis_J[i-1][j]=dis_J[i][j]+1 ;
                aa.a=i-1 ;
                aa.b=j ;
                Q.push(aa) ;
            }

        if(i+1<row)
            if(ch[i+1][j]=='.')
            {
                ch[i+1][j]='a' ;
                dis_J[i+1][j]=dis_J[i][j]+1 ;
                aa.a=i+1 ;
                aa.b=j ;
                Q.push(aa) ;
            }

        if(j-1>=0)
            if(ch[i][j-1]=='.')
            {
                ch[i][j-1]='a' ;
                dis_J[i][j-1]=dis_J[i][j]+1 ;
                aa.a=i ;
                aa.b=j-1 ;
                Q.push(aa) ;
            }

        if(j+1<col)
            if(ch[i][j+1]=='.')
            {
                ch[i][j+1]='a' ;
                dis_J[i][j+1]=dis_J[i][j]+1 ;
                aa.a=i ;
                aa.b=j+1 ;
                Q.push(aa) ;
            }
    }
}

void F_bfs()
{
    long a , b , i , j ;

    for(i=0 ; i<row ; i++)
        for(j=0 ; j<col ; j++)
            if(ch[i][j]=='F')
            {
                ch[i][j]='#' ;
                dis_F[i][j]=0 ;
                aa.a=i ;
                aa.b=j ;
                Q.push(aa) ;
            }

    while(!Q.empty())
    {
        aa=Q.front() ;
        Q.pop() ;
        i=aa.a ;
        j=aa.b ;
        if(i-1>=0)
            if(ch[i-1][j]!='#')
            {
                ch[i-1][j]='#' ;
                dis_F[i-1][j]=dis_F[i][j]+1 ;
                aa.a=i-1 ;
                aa.b=j ;
                Q.push(aa) ;
            }

        if(i+1<row)
            if(ch[i+1][j]!='#')
            {
                ch[i+1][j]='#' ;
                dis_F[i+1][j]=dis_F[i][j]+1 ;
                aa.a=i+1 ;
                aa.b=j ;
                Q.push(aa) ;
            }

        if(j-1>=0)
            if(ch[i][j-1]!='#')
            {
                ch[i][j-1]='#' ;
                dis_F[i][j-1]=dis_F[i][j]+1 ;
                aa.a=i ;
                aa.b=j-1 ;
                Q.push(aa) ;
            }

        if(j+1<col)
            if(ch[i][j+1]!='#')
            {
                ch[i][j+1]='#' ;
                dis_F[i][j+1]=dis_F[i][j]+1 ;
                aa.a=i ;
                aa.b=j+1 ;
                Q.push(aa) ;
            }
    }
}

int main()
{
    long loop , test , a , b , c , i , j , ii , jj ;
    scanf("%ld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        scanf("%ld%ld",&row,&col) ;
        for(a=0 ; a<row ; a++)
            scanf("%s",ch[a]) ;

        if((row==1 && col==2) || (row==2 && col==1))
        {
            printf("Case %ld: 1\n",loop) ;
            continue ;
        }
        for(a=0 ; a<row ; a++)
        {
            memset(dis_F[a],0,sizeof(dis_F[a])) ;
            memset(dis_J[a],0,sizeof(dis_J[a])) ;
        }

        J_bfs() ;

        F_bfs() ;

        c=9999 ;
        for(i=0 ; i<col ; i++)
            if(dis_F[0][i]>dis_J[0][i] && c>dis_J[0][i] && dis_J[0][i]) c=dis_J[0][i] ;

        for(i=0 ; i<row ; i++)
            if(dis_F[i][0]>dis_J[i][0] && c>dis_J[i][0] && dis_J[i][0]) c=dis_J[i][0] ;

        for(i=0 ; i<col ; i++)
            if(dis_F[row-1][i]>dis_J[row-1][i] && c>dis_J[row-1][i] && dis_J[row-1][i]) c=dis_J[row-1][i] ;

        for(i=0 ; i<row ; i++)
            if(dis_F[i][col-1]>dis_J[i][col-1] && c>dis_J[i][col-1] && dis_J[i][col-1]) c=dis_J[i][col-1] ;

        if(c==9999)
            printf("Case %ld: IMPOSSIBLE\n",loop) ;
        else printf("Case %ld: %ld\n",loop,c+1) ;
    }
    return 0 ;
}
