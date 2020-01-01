#include<bits/stdc++.h>
using namespace std ;
#define Max 10005

long start[Max] , minTime[Max] , par[Max] , node , edge , cc ;
vector<long>V[Max] ;
vector<pair<long,long> >ans ;

bool cmp(pair<long,long>a,pair<long,long>b)
{
    if(a.first == b.first)
        return a.second < b.second ;
    return a.first < b.first ;
}

void dfs(long a , long t)
{
    start[a]=minTime[a]=t ;

    for(long b=0 ; b<V[a].size() ; b++)
        if(!start[ V[a][b] ])
        {
            par[ V[a][b] ] = a ;
            dfs(V[a][b] , t+1) ;

            if(minTime[ V[a][b] ] > start[a])
            {
                pair<long,long>P(min(a,V[a][b]) , max(a,V[a][b])) ;
                ans.push_back(P) ;
            }

            minTime[a] =min( minTime[ V[a][b] ] , minTime[a] ) ;
            /*if(par[a] != -1 && minTime[ V[a][b] ] >= start[a])
                articulationPoint[a]=true ;*/
        }
        else if(par[a] != V[a][b])
            minTime[a] =min( start[ V[a][b] ] , minTime[a] ) ;


    /*if(par[a] == -1 && Count>1)
        articulationPoint[a]=true ;*/
}

int main()
{
    long loop , test , a , b , c , d , e ;
    char ch1 , ch2 ;
    scanf("%ld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        cc=0 ;
        scanf("%ld",&node) ;
        for(a=0 ; a<node ; a++)
        {
            scanf("%ld %c%ld%c",&b,&ch1,&c,&ch2) ;
            while(c--)
            {
                scanf("%ld",&d) ;
                V[b].push_back(d) ;
            }
        }

        for(a=0 ; a<node ; a++)
            start[a]=0 ,  par[a]=-1 ;

        for(a=0 ; a<node ; a++)
            if(!start[a])
                dfs(a,1) ;

        printf("Case %ld:\n",loop) ;
        printf("%ld critical links\n",ans.size()) ;
        sort(ans.begin(),ans.end(),cmp) ;
        for(a=0 ; a<ans.size() ; a++)
            printf("%ld - %ld\n",ans[a].first,ans[a].second) ;

        for(a=0 ; a<node ; a++)
            V[a].clear() ;
        ans.clear() ;
    }
}
