#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
using namespace std ;

long t , w , d[50] , v[50] , n ;
struct data
{
    long a , b , flag , sum , count ;
} ans[50][2000] ;

long rec(long a , long T)
{
    if(T == t || a == n)
    {
        ans[a][T].sum = ans[a][T].count = 0 ;
        return 0 ;
    }
    if(ans[a][T].sum != -1)
         return ans[a][T].sum ;

    long b = rec(a+1 , T) ;
    long c = 0 ;
    if(T + 3*w*d[a] < t)
    c += v[a]+rec(a+1 , T + 3*w*d[a]) ;

    if(b>c)
    {
        ans[a][T].a=a+1 ;
        ans[a][T].b=T ;
        ans[a][T].flag=0 ;
        ans[a][T].sum = b ;
        ans[a][T].count = ans[a+1][T].count ;
    }
    else
    {
        ans[a][T].a=a+1 ;
        ans[a][T].b=T + 3*w*d[a] ;
        ans[a][T].flag=1 ;
        ans[a][T].sum = c ;
        ans[a][T].count = ans[a+1][T + 3*w*d[a]].count+1 ;
    }
    return ans[a][T].sum ;
}

int main()
{
    long A , B , C , F=1 ;
    while(scanf("%ld%ld",&t,&w) != EOF)
    {
        if(F == 2) printf("\n") ;
        F=2 ;
        scanf("%ld",&n) ;
        for(A=0 ; A<n ; A++)
            scanf("%ld%ld",&d[A],&v[A]) ;
        memset(ans,-1,sizeof ans) ;
        B=C=0 ;

        printf("%ld\n",rec(0,0)) ;
        printf("%ld\n",ans[0][0].count) ;
        while(B < n && C <= t && ans[0][0].count)
        {
            if(ans[B][C].flag == 1)
                printf("%ld %ld\n",d[B],v[B]) ;
                long D = B ;
             B=ans[B][C].a ;
             C=ans[D][C].b ;
        }

    }
}
/*
10 4
5
10 1
10 1
5 8
3 2
5 1
*/
