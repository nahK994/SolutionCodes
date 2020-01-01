#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std ;

long time , limit , ara[30] , Max , finish , count=1 ;
vector<long> V , ans ;

void rec(long index , long sum)
{
    long i , a ;
    if(index>=time) return ;
    if(sum==limit)
    {
        ans.clear() ;
        for(i=0 ; i<V.size() ; i++)   // how can I optimize 45 5 45 1 2 3 4 ????
        ans.push_back(V[i]) ;
        Max=sum ;
        //finish=1 ;
        return ;
    }
    if(sum>Max)
    {
        ans.clear() ;
        for(i=0 ; i<V.size() ; i++)
        ans.push_back(V[i]) ;
        Max=sum ;
    }
    /*if(finish==0)*/ rec(index+1 , sum) ;
    if(sum+ara[index+1]<=limit)
    {
        V.push_back(ara[index+1]) ;
        /*if(finish==0)*/ rec(index+1 , sum+ara[index+1]) ;
        sum-=ara[index+1] ;
        if(V.size()!=0) V.pop_back() ;
    }
   // printf("%ld\n",count++) ;
}

int main()
{
    long i , a ;
    while(scanf("%ld%ld",&limit,&time)!=EOF)
    {
        //finish=0 ;
        Max=0 ;
        for(i=0 ; i<time ; i++)
        scanf("%ld",&ara[i]) ;
        rec(-1,0) ;
        for(i=0 ; i<ans.size() ; i++)
            printf("%ld ",ans[i]) ;
        printf("sum:%ld\n",Max) ;
        memset(ara,0,sizeof(ara)) ;
        V.clear() ;
        ans.clear() ;
    }
    return 0 ;
}
