#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std ;
int main()
{
    long loop , test , a , b , i , n , min1 , min2 , ara[400][400] , c , color[400] , sum_of_weights ;
    vector<long> v_in[400] , v_out[400] ;
    scanf("%ld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        scanf("%ld",&n) ;
        for(i=1 ; i<=n ; i++)
        {
            memset(ara[i],0,sizeof(ara[i])) ;
            v_in[i].clear() ;
            v_out[i].clear() ;
        }
        memset(color,0,sizeof(color)) ;
        i=n ; sum_of_weights=0 ;
        while(i--)
        {
            scanf("%ld%ld%ld",&a,&b,&c) ;
            v_in[a].push_back(b) ;
            v_out[b].push_back(a) ;
            ara[b][a]=c ;
            sum_of_weights+=c ;
        }
        min1=0 ;
        i=n ;
        a=1 ;
        while(i--)
        {
            b=v_in[a].size() ;
            c=v_out[a].size() ;
            color[a]=1 ;
            if(b==2 && !color[v_in[a][0]])
                a=v_in[a][0] ;
            else if(b==2 && !color[v_in[a][1]])
                a=v_in[a][1] ;
            else if(b==1 && !color[v_in[a][0]])
                a=v_in[a][0] ;
            else if(c==2 && !color[v_out[a][0]])
            {
                c=a ;
                a=v_out[a][0] ;
                min1+=ara[c][a] ;
            }
            else if(c==2 && !color[v_out[a][1]])
            {
                c=a ;
                a=v_out[a][1] ;
                min1+=ara[c][a] ;
            }
            else if(c==1 && !color[v_out[a][0]])
            {
                c=a ;
                a=v_out[a][0] ;
                min1+=ara[c][a] ;
            }
        }
        min1+=ara[a][1] ;
        min2=sum_of_weights-min1 ;
        if(min2<min1) min1=min2 ;
        printf("Case %ld: %ld\n",loop , min1) ;
    }
    return 0 ;
}
