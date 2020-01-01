#include<stdio.h>
#include<string.h>

long n , m , d , q , ara[500] , ans[500][500][20] ;

long rec(long a , long sum , long count)
{
    if(count == m)
    {
        if(sum%d == 0)
            return 1 ;
        return 0 ;
    }
    if(a == n) return 0 ;
    if(ans[a][sum][count] != -1) return ans[a][sum][count] ;

    long b = rec(a+1 , sum%d , count) ;
    long c = rec(a+1 , (sum + ara[a])%d , count+1) ;

    return ans[a][sum][count] = b+c ;
}

int main()
{
    long a , b=0 , c ;
    while(scanf("%ld%ld",&n,&q) != EOF)
    {
        if(n == 0 && q == 0)
            break ;
        for(a=0 ; a<n ; a++)
            scanf("%ld",&ara[a]) ;

        printf("SET %ld:\n",++b) ;
        for(c=1 ; c<=q ; c++)
        {
            memset(ans,-1,sizeof ans) ;
            scanf("%ld%ld",&d,&m) ;
            printf("QUERY %ld: %ld\n",c,rec(0,0,0)) ;
        }
    }
}

/*
10 2
1
2
3
4
5
6
7
8
9
10
5 1
5 2
5 1
2
3
4
5
6
6 2
0 0
*/
