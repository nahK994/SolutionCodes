#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
using namespace std ;

vector<long>V[50010];
queue<long>Q ;
long color[50010] , time , n ;

void bfs(long a , long b)
{
    long i , j ;
    Q.push(a) ;
    time++ ;
    //color[a]=b ;
    while(!Q.empty())
    {
        a=Q.front() ;
        color[a] = b ;
        for(i=0 ; i<V[a].size() ; i++)
            if(color[ V[a][i] ] != b)
            {
                time++ ;
                Q.push( V[a][i] ) ;
            }
        Q.pop() ;
    }
}

int main()
{
    long loop , test , a , b , c , max  , m ;
    scanf("%ld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        scanf("%ld",&n) ;
        m=n ;
        memset(color,0,sizeof(color)) ;
        while(n--)
        {
            scanf("%ld%ld",&a,&b) ;
            V[a].push_back(b) ;
        }
        max = -1 ;
        c=1 ;
        for(a=1 ; a<=m ; a++)
        {
            if( color[a] == 0 )
            {
                time=0 ;
                bfs(a , c) ;
                if(time>max)
                {
                    max = time ;
                    b = a ;
                }
                c++ ;
            }
        }
        for(a=1 ; a<=m ; a++)
            V[a].clear() ;
        printf("Case %ld: %ld\n",loop,b) ;
    }
}
