/*
2
2 5
6 1 1 1 1 1 1
3 1 2 2
3 5
4 1 2 1 1
3 2 2 2
5 1 3 4 4 3
*/
#include<bits/stdc++.h>
using namespace std;
long ara[100][100], n, m, dist[100], aa[100];

bool bfs(long S, long D)
{
    memset(dist,9999,sizeof dist);
    memset(aa,-1,sizeof aa);
    queue<long>Q;
    Q.push(S);
    dist[S]=0;
    while(!Q.empty())
    {
        long a=Q.front(), b, c;
        Q.pop();
        if(a<=n)
        {
            b=n+1;
            c=n+m;
        }
        else
        {
            b=0;
            c=n;
        }
        for( ; b<=c ; b++)
            if(ara[a][b] && dist[b]>dist[a]+1)
            {
                Q.push(b);
                dist[b]=dist[a]+1;
                aa[b]=a;
                if(b==D) return true;
            }
    }
  //  return dist[D]!=9999 ;  // ei ta dile tle dey
    return false; // dile wa dey
}

long maxFlow(long S, long D)
{
    long ans=0;
    while(bfs(S,D))
    {
        long minn=9999, asdf=D;
        while(asdf != S)
        {
            if( minn > ara[ aa[asdf] ][asdf] )
                minn =  ara[ aa[asdf] ][asdf];
            asdf=aa[asdf];
        }

        asdf=D;
        while(asdf != S)
        {
            ara[ aa[asdf] ][asdf]-=minn;
            ara[asdf][ aa[asdf] ]+=minn;
            asdf=aa[asdf];
        }

        ans+=minn;
    }
    return ans;
}

int main()
{
    long loop, test, a, b, c, S, D, i, j ;
    scanf("%ld",&test);
    for(loop=1 ; loop<=test ; loop++)
    {
        S=1, D=0;
        memset(ara, 0, sizeof ara);
        scanf("%ld%ld",&n,&m);
        for(i=1 ; i<=n ; i++)
        {
            scanf("%ld",&b);
            for(j=1 ; j<=b ; j++)
            {
                scanf("%ld",&a);
                ara[i][a+n]++;
            }
        }

        for(j=2 ; j<=n ; j++)
            for(i=1 ; i<=m ; i++)
                if(!ara[j][i+n]) ara[i+n][j]=1;
                else ara[j][i+n]--;

        for(j=1 ; j<=m ; j++)
            ara[n+j][D]=1;
        printf("Case #%ld: %ld\n",loop,maxFlow(S,D));
    }
    return 0;
}
