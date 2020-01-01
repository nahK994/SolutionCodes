#include<stdio.h>
#include<string.h>
#include<string>
#include<map>
#include<vector>

using namespace std ;

map<string,long>mp ;
vector<long>V[10050] ;

int main()
{
    long loop , test , a , b , indegree[10050] , i , min ;
    char ch1[50] , ch2[50] ;
    scanf("%ld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        memset(indegree,0,sizeof(indegree)) ;
        a=0 ;
        scanf("%ld",&b) ;
        while(b--)
        {
            scanf("%s %s",ch1,ch2) ;
            if(mp[ch1]==0) mp[ch1]=a++ ;
            if(mp[ch2]==0) mp[ch2]=a++ ;
            V[mp[ch1]].push_back(mp[ch2]) ;
            indegree[mp[ch2]]++ ;
        }
        do
        {
            min=99999999 ;
            for(b=0 ; b<a ; b++)
            {
                if(min>indegree[b])
                    min=indegree[b] ;
                if(indegree[b]==0)
                {
                    indegree[b]=99999999 ;
                    for(i=0 ; i<V[b].size() ; i++)
                        indegree[V[b][i]]-- ;
                }
            }
        }
        while(min==0) ;
        if(min!=99999999) printf("Case %ld: No\n",loop) ;
        else printf("Case %ld: Yes\n",loop) ;
        mp.clear() ;
        for(i=0 ; i<a ; i++) V[i].clear() ;
    }
    return 0 ;
}
