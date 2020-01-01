#include<bits/stdc++.h>
using namespace std ;
#define Max 10005

long start[Max] , minTime[Max] , par[Max] , node , edge , cc ;
vector<long>V[Max] ;
bool articulationPoint[Max] ;

void dfs(long a , long t)
{
    long Count=0 , b ;
    start[a]=minTime[a]=t ;

    for(b=0 ; b<V[a].size() ; b++)
        if(!start[ V[a][b] ])
        {
            Count++ ;
            par[ V[a][b] ] = a ;
            dfs(V[a][b] , t+1) ;

            minTime[a] =min( minTime[ V[a][b] ] , minTime[a] ) ;

            if(par[a] != -1 && minTime[ V[a][b] ] >= start[a])
                articulationPoint[a]=true ;
        }
        else if(par[a] != V[a][b])
            minTime[a] =min( start[ V[a][b] ] , minTime[a] ) ;


    if(par[a] == -1 && Count>1)
        articulationPoint[a]=true ;
}

int main()
{
    long loop , test , a , b , c , d , e ;
    scanf("%ld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        cc=0 ;
        scanf("%ld%ld",&node,&edge) ;
        for(a=1 ; a<=edge ; a++)
        {
            scanf("%ld%ld",&b,&c) ;
            V[b].push_back(c) ;
            V[c].push_back(b) ;
        }

        for(a=1 ; a<=node ; a++)
            start[a]=0 , articulationPoint[a]=false , par[a]=-1 ;

        for(a=1 ; a<=node ; a++)
            if(!start[a])
                dfs(a,1) ;

        c=0 ;
        for(a=1 ; a<=node ; a++)
            if(articulationPoint[a])
                c++ ;
        printf("Case %ld: %ld\n",loop,c) ;

        for(a=1 ; a<=node ; a++)
            V[a].clear() ;
    }
}
/*
1
5 4
1 2
2 3
3 4
4 5
*/
/*
1
3 3
1 2
2 3
3 1
*/
