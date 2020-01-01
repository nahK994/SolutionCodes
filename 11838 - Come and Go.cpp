#include<bits/stdc++.h>
using namespace std ;

vector<long>V[3000] , rev[3000] ;
stack<long>S , ans ;
long node , edge , color[3000] , color1[3000] ;

void dfs1(long a)
{
    color[a]=1 ;
    for(long i=0 ; i<V[a].size() ; i++)
       {
           long s=V[a][i] ;
           if(!color[s])
               dfs1(s) ;
       }
       S.push(a) ;
}

void dfs2(long a)
{
    color1[a]=1 ;
    for(long i=0 ; i<rev[a].size() ; i++)
       {
           long s=rev[a][i] ;
           if(!color1[s])
               dfs2(s) ;
       }
       ans.push(a) ;
}

int main()
{
    long i , j , a , b , c ;
    while(true)
    {
        scanf("%ld%ld",&node,&edge) ;
       if(!node && !edge) break ;
        for(i=0 ; i<=node ; i++)
        {
            V[i].clear() ;
            rev[i].clear() ;
            color1[i]=color[i]=0 ;
        }
        while(!S.empty())
         S.pop() ;
        while(!ans.empty())
         ans.pop() ;

        for(i=0 ; i<edge ; i++)
        {
            scanf("%ld%ld%ld",&a,&b,&c) ;
            V[a].push_back(b) ;
            rev[b].push_back(a) ;
            if(c==2)
            {
                V[b].push_back(a) ;
                rev[a].push_back(b) ;
            }
        }
        dfs1(1) ;
        if(S.size()!=node) printf("0\n") ;
         else
         {
             dfs2(S.top()) ;
             if(ans.size()!=node) printf("0\n") ;
               else
            printf("1\n") ;
         }
    }
    return 0 ;
}
