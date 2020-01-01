#include<bits/stdc++.h>
using namespace std ;

vector<long>V[110] ;
double v , s ;
long holes , gophers , used[110] , parent[110] ;
struct data
{
    double a , b ;
} Hpoints[110] , Gpoints[110] ;

bool bpm(long a)
{
    used[a]=1 ;
    for(int i=0 ; i<V[a].size() ; i++)
    {
        long aa=V[a][i] ;
        if(parent[aa] == -1 ||( !used[parent[aa]] && bpm( parent[aa] )))
        {
            parent[aa] = a ;
            return true ;
        }
    }
    return false ;
}

int main()
{
    long a , b , i , j ;
    double aa ;
    while(scanf("%ld%ld%lf%lf",&gophers,&holes,&s,&v)!=EOF)
    {
        memset(parent , -1 , sizeof parent) ;
        for(i=0 ; i<=gophers ; i++)
            V[i].clear() ;

        for(i=1 ; i<=gophers ; i++)
            scanf("%lf%lf",&Gpoints[i].a,&Gpoints[i].b) ;
        for(i=1 ; i<=holes ; i++)
            scanf("%lf%lf",&Hpoints[i].a,&Hpoints[i].b) ;

        for(i=1 ; i<=gophers ; i++)
            for(j=1 ; j<=holes ; j++)
            {
                aa=sqrt( (Gpoints[i].a-Hpoints[j].a)*(Gpoints[i].a-Hpoints[j].a) + (Gpoints[i].b-Hpoints[j].b)*(Gpoints[i].b-Hpoints[j].b) ) ;
                aa/=v ;
                if(aa < s)
                    V[i].push_back(j) ;
            }
        a=0 ;
        for(i=1 ; i<=min(gophers,holes) ; i++)
            if(bpm(i))
            {
                a++ ;
                memset(used,0,sizeof used) ;
            }
        printf("%ld\n",gophers-a) ;
    }
    return 0 ;
}
