//#include<bits/stdc++.h>
#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
#define ll long long

queue<struct node>Q ;
char ch[20][20] , find , obstracle ;
long ans , ara[20][20] , n , color[100] , count ;
struct node
{
    long a , b ;
} ;

void bfs(struct node bb)
{
    //printf("A") ;
    long i , j , a , b , c , p , q , r , x , y , flag ;
    obstracle='b' ;
    find='B' ;
    ara[bb.a][bb.b]=0 ;
    ch[bb.a][bb.b]='b' ;
    Q.push(bb) ;
    while(!Q.empty())
    {
        //printf("D") ;
        bb=Q.front() ;
        Q.pop() ;
        x=bb.a ;
        y=bb.b ;
        flag=0 ;

        if(ch[x-1][y]!='#' && ch[x-1][y]!=obstracle && x>0 && flag==0)
        {
            if(ch[x-1][y]==find)
            {
                //printf("%c %ld %ld\n",ch[x-1][y],x-1,y) ;
                flag=1 ;
                ans+=ara[x][y]+1 ;
                ch[x-1][y]=++obstracle ;
                find++ ;
                for(long aa=0 ; aa<n ; aa++)
                    memset(ara[aa],0,sizeof(ara[aa])) ;
                while(!Q.empty()) Q.pop() ;
                bb.a=x-1 ;
                bb.b=y ;
                Q.push(bb) ;
            }
            else if(!(ch[x-1][y]>='A' && ch[x-1][y]<='Z'))
            {
                // printf("%ld %ld\n",x-1,y) ;
                ara[x-1][y]=ara[x][y]+1 ;
                ch[x-1][y]=obstracle ;
                bb.a=x-1 ;
                bb.b=y ;
                Q.push(bb) ;
            }
        }

        if(ch[x+1][y]!='#' && ch[x+1][y]!=obstracle && x+1<n && flag==0)
        {
            if(ch[x+1][y]==find)
            {
                flag=1 ;
                //printf("%c %ld %ld\n",ch[x+1][y],x+1,y) ;
                ans+=ara[x][y]+1 ;
                ch[x+1][y]=++obstracle ;
                find++ ;
                for(long aa=0 ; aa<n ; aa++)
                    memset(ara[aa],0,sizeof(ara[aa])) ;
                while(!Q.empty()) Q.pop() ;
                bb.a=x+1 ;
                bb.b=y ;
                Q.push(bb) ;
            }
            else if(!(ch[x+1][y]>='A' && ch[x+1][y]<='Z'))
            {
                //printf("%ld %ld\n",x+1,y) ;
                ara[x+1][y]=ara[x][y]+1 ;
                ch[x+1][y]=obstracle ;
                bb.a=x+1 ;
                bb.b=y ;
                Q.push(bb) ;
            }
        }

        if(ch[x][y-1]!='#' && ch[x][y-1]!=obstracle && y>0 && flag==0)
        {
            if(ch[x][y-1]==find)
            {
                flag=1 ;
                // printf("%c %ld %ld\n",ch[x][y-1],x,y-1) ;
                ans+=ara[x][y]+1 ;
                ch[x][y-1]=++obstracle ;
                find++ ;
                for(long aa=0 ; aa<n ; aa++)
                    memset(ara[aa],0,sizeof(ara[aa])) ;
                while(!Q.empty()) Q.pop() ;
                bb.a=x ;
                bb.b=y-1 ;
                Q.push(bb) ;
            }
            else if(!(ch[x][y-1]>='A' && ch[x][y-1]<='Z'))
            {
                //printf("%ld %ld\n",x,y-1) ;
                ara[x][y-1]=ara[x][y]+1 ;
                ch[x][y-1]=obstracle ;
                bb.a=x ;
                bb.b=y-1 ;
                Q.push(bb) ;
            }
        }

        if(ch[x][y+1]!='#' && ch[x][y+1]!=obstracle && y+1<n && flag==0)
        {
            if(ch[x][y+1]==find)
            {
                flag=1 ;
                //printf("%c %ld %ld\n",ch[x][y+1],x,y+1) ;
                ans+=ara[x][y]+1 ;
                ch[x][y+1]=++obstracle ;
                find++ ;
                for(long aa=0 ; aa<n ; aa++)
                    memset(ara[aa],0,sizeof(ara[aa])) ;
                while(!Q.empty()) Q.pop() ;
                bb.a=x ;
                bb.b=y+1 ;
                Q.push(bb) ;
            }
            else if(!(ch[x][y+1]>='A' && ch[x][y+1]<='Z'))
            {
                //printf("%ld %ld\n",x,y+1) ;
                ara[x][y+1]=ara[x][y]+1 ;
                ch[x][y+1]=obstracle ;
                bb.a=x ;
                bb.b=y+1 ;
                Q.push(bb) ;
            }
        }
    }
}

int main()
{
    long loop , test , a , b , c , i , j ;
    struct node bb ;
    scanf("%ld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        scanf("%ld",&n) ;
        for(a=0 ; a<n ; a++)
            for(b=0 ; b<n ; b++)
                ara[a][b]=0 ;
        ans=count=0 ;
        for(i=0 ; i<n ; i++)
        {
            scanf("%s",ch[i]) ;
            for(j=0 ; j<n ; j++)
                if(ch[i][j]>='A' && ch[i][j]<='Z')
                {
                    count++ ;
                    if(ch[i][j]=='A')
                    {
                        bb.a=i ;
                        bb.b=j ;
                    }
                }
        }
        bfs(bb) ;
        if(obstracle-1==count+96)
            printf("Case %ld: %ld\n",loop,ans) ;
        else printf("Case %ld: Impossible\n",loop) ;
    }
    return 0 ;
}
