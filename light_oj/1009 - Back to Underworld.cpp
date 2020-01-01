#include<stdio.h>
#include<string.h>
#include<map>
#include<queue>
#include<vector>
using namespace std ;

map<long,long>mp ;
vector<long>v[100100] ;
queue<long>q ;
long countA , countB , color[200100] , Count ;

void dfs(long a,long count)
{
    if(count%2) countA++ ;
    else countB++ ;
    long i ; Count++ ;
    color[a]=1 ;
    for(i=0 ; i<v[a].size() ; i++)
        if(color[v[a][i]]==0)
            dfs(v[a][i],count+1) ;
}

int main()
{
    long loop , test , a , b , i , j , n ;
    scanf("%ld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        scanf("%ld",&n) ;
        i=1 ;
        j=0 ;
        memset(color,0,sizeof(color)) ;
        while(j<n)
        {
            scanf("%ld%ld",&a,&b) ;
            if(mp[a]==0) mp[a]=i++ ;
            if(mp[b]==0) mp[b]=i++ ;
            v[mp[a]].push_back(mp[b]) ;
            v[mp[b]].push_back(mp[a]) ;
            j++ ;
        }
        j=0 ; countA=countB=Count=0 ;
        for(a=1 ; a<i && Count<i-1 ; a++)
            if(color[a]==0)
            {
                dfs(a,1) ;
                if(countA>countB) j+=countA ;
                else j+=countB ;
                countA=countB=0 ;
            }
        printf("Case %ld: %ld\n",loop,j) ;
        for(a=0 ; a<=i ; a++)
            v[a].clear() ;
        mp.clear() ;
        memset(color,0,sizeof(color)) ;
    }
    return 0 ;
}
