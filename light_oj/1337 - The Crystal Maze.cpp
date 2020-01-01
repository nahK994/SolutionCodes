#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std ;
char ch[800][800] , cc='1' ;
long count , row , col , color[800][800] ;
 struct node
{
    long a , b ;
} aa ;
queue<struct node> Q , Q1 ;

void bfs(long i , long j)
{
    aa.a=i ;
    aa.b=j ;
    ch[aa.a][aa.b]='1' ;
    Q.push(aa) ;
    Q1.push(aa) ;
    while(!Q.empty())
    {
        aa=Q.front() ;
        Q.pop() ;
        i=aa.a ;
        j=aa.b ;
        if(i>0 && ch[i-1][j]!='1' && ch[i-1][j]!='#')
        {
            if(ch[i-1][j]=='C') count++ ;
            ch[i-1][j]='1' ;
            aa.a=i-1 ;
            aa.b=j ;
            Q.push(aa) ;
            Q1.push(aa) ;
        }
        if(i+1<row && ch[i+1][j]!='1' && ch[i+1][j]!='#')
        {
            if(ch[i+1][j]=='C') count++ ;
            ch[i+1][j]='1' ;
            aa.a=i+1 ;
            aa.b=j ;
            Q.push(aa) ;
            Q1.push(aa) ;
        }
        if(j>0 && ch[i][j-1]!='1' && ch[i][j-1]!='#')
        {
            if(ch[i][j-1]=='C') count++ ;
            ch[i][j-1]='1' ;
            aa.a=i ;
            aa.b=j-1 ;
            Q.push(aa) ;
            Q1.push(aa) ;
        }
        if(j+1<col && ch[i][j+1]!='1' && ch[i][j+1]!='#')
        {
            if(ch[i][j+1]=='C') count++ ;
            ch[i][j+1]='1' ;
            aa.a=i ;
            aa.b=j+1 ;
            Q.push(aa) ;
            Q1.push(aa) ;
        }
    }
}

int main()
{
    long loop , test , a , i , j , b ;
    scanf("%ld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        scanf("%ld%ld%ld",&row,&col,&a) ;

        for(i=0 ; i<row ; i++)
            scanf("%s",ch[i]) ;

        for(i=0 ; i<row ; i++)
            memset(color[i],-1,sizeof(color[i])) ;

        printf("Case %ld:\n",loop) ;
        while(a--)
        {
            count=0 ;
            scanf("%ld%ld",&j,&b) ;
            if(color[j-1][b-1]==-1)
            {
                //printf("asdf\n") ;
                bfs(j-1,b-1) ;
                while(!Q1.empty())
                {
                    aa=Q1.front() ;
                    color[aa.a][aa.b]=count ;
                    Q1.pop() ;
                }
            }
            printf("%ld\n",color[j-1][b-1]) ;
        }
    }
    return 0 ;
}
