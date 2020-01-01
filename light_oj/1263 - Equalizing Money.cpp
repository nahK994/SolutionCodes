#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
using namespace std ;

vector<long>V[1005] ;
queue<long>Q ;
long color[1005] , value[1005] , sum1 , sum2 , counter ;

long bfs(long a)
{
    color[a] = 1 ;
    Q.push(a) ;

    if(counter < value[a])
        sum1 = value[a] - counter ;
    else if(counter > value[a])
        sum2 = counter - value[a] ;

    while(!Q.empty())
    {
        a = Q.front() ;
        Q.pop() ;
        for(int i=0 ; i<V[a].size() ; i++)
            if(color[V[a][i]] == 0)
            {
                Q.push(V[a][i]) ;
                color[V[a][i]] = 1 ;
                if(counter < value[V[a][i]])
                    sum1 += value[V[a][i]] - counter ;
                else if(counter > value[V[a][i]])
                    sum2 += counter - value[V[a][i]] ;
            }
    }

    if(sum1 == sum2) return 1 ;
    return 0 ;
}

int main ()

{
    long loop , test , a , n , m , flag , b ;
    scanf("%ld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        scanf("%ld%ld",&n,&m) ;
        counter = 0 ;
        for(a=1 ; a<=n ; a++)
        {
            scanf("%ld",&value[a]) ;
            counter+=value[a] ;
            V[a].clear() ;
            color[a]=0 ;
        }
        while(m--)
        {
            scanf("%ld%ld",&a,&b) ;
            V[a].push_back(b) ;
            V[b].push_back(a) ;
        }
         if(counter%n != 0)
        {
            printf("Case %ld: No\n",loop) ;
            continue ;
        }
        counter/=n ;
         flag = 1 ;
        for(a=1 ; a<=n ; a++)
        {
            sum1=sum2=0 ;
            if(color[a] == 0)
                flag = bfs(a) ;
            if(flag == 0) break ;
        }

        if(flag) printf("Case %ld: Yes\n",loop) ;
        else  printf("Case %ld: No\n",loop) ;
    }
    return 0 ;
}
