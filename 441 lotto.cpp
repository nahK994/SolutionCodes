#include<vector>
#include<algorithm>
#include<stdio.h>
#include<string.h>

using namespace std ;

long ara[100] , length , color[100] ;
vector<long>V ;

void rec(long a)
{
    long i ;
    if(V.size()==6)
    {
        for(i=0 ; i<5 ; i++)
        printf("%ld ",V[i]) ;
        printf("%ld\n",V[5]) ;
        return ;
    }
    for(i=a+1 ; i<length ; i++)
    {
        if(color[i]==0)
        {
            color[i]=1 ; V.push_back(ara[i]) ;
            rec(i) ;
            color[i]=0 ; V.pop_back() ;
        }
    }
}

int main()
{
    long i , a=0 ;
    while(scanf("%ld",&length)!=EOF)
    {
        if(length==0) break ;
        if(a>0) printf("\n") ;
        a=1 ;
        for(i=0 ; i<length ; i++)
        {
            scanf("%ld",&ara[i]) ;
            color[i]=0 ;
        }
        sort(ara,ara+length) ;
        rec(-1) ;
        memset(ara,0,sizeof(ara)) ;
        memset(color,0,sizeof(color)) ;
        V.clear() ;
    }
    return 0 ;
}
