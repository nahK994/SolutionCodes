#include <bits/stdc++.h>
#define MAX_BOLTS 500
#define MAX_NUTS 500
using namespace std ;
/*~global~copy~of~the~input~data~*/
int nuts,bolts;
int fits[MAX_BOLTS][MAX_NUTS] , parent[MAX_NUTS] , used[MAX_NUTS] , color[MAX_BOLTS] ;
vector<int>V[MAX_BOLTS] ;
void read_input_data(void)
{
    int n,b;
    for(b=0; b<bolts; b++)
    {
        for(n=0; n<nuts; n++)
        {
            scanf("%d",&fits[b][n]);
            if(fits[b][n])
            {
                // printf("H\n") ;
                V[b].push_back(n) ;
            }
        }
    }
}
/* data used to match nuts with bolts */
int bestmatched;
void init_match(void)
{
    int n;
    bestmatched=0;
    for(n=0 ; n<bolts ; n++)
    {
        V[n].clear() ;
        color[n]=0 ;
    }
    for(n=0; n<nuts; n++)
        parent[n]=-1;
}
bool match_bolt(int boltno)
{
    //printf("R\n") ;
    //printf("%ld\n",V[boltno].size()) ;
    for(int i=0 ; i<V[boltno].size() ; i++)
    {
        int a=V[boltno][i] ;
        if(!used[a])
        {
            used[a]=1 ;
            if(parent[a] == -1 || (parent[a] != boltno and match_bolt(parent[a])))
            {
                parent[a]=boltno ;
                color[boltno]=1 ;
                return true ;
            }
        }
    }
    return false ;
}
int main()
{
    int cases,caseno;
    scanf("%d",&cases);
    for(caseno=1; caseno<=cases; caseno++)
    {
        scanf("%d%d",&bolts,&nuts);
        init_match();
        read_input_data();
        for(int i=0 ; i<bolts ; i++)
            if(!color[i])
            {
                memset(used , 0 , sizeof used) ;
                if(match_bolt(i))
                    bestmatched++ ;
                if(bestmatched==min(bolts,nuts)) break ;
            }
        printf("Case %d: ",caseno);
        printf("a maximum of %d nuts and bolts ",bestmatched);
        printf("can be fitted together\n");
    }
    return 0;
}

