#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std ;

long num , n , ara[1050] , flag ;
vector<long> V ;

void rec(long a , long sum)
{
    if(sum == 0)
    {
        flag = 1 ;
            printf("%ld",V[0]) ;
        if(V.size() == 1)
        {
            printf("\n") ;
            return ;
        }

        for(long i = 1 ; i<V.size() ; i++)
            printf("+%ld",V[i]) ;
            printf("\n") ;
        return ;
    }

    long pev = -1 ;
    for(long i = a ; i<n ; i++)
        if(sum - ara[i] >= 0 && pev != ara[i])
        {
            pev = ara[i] ;
            V.push_back(ara[i]) ;
            rec(i+1 , sum - ara[i]) ;
            V.pop_back() ;
        }
}

int main()
{
    long a , b , c ;
    while(scanf("%ld%ld",&num,&n) != EOF)
    {
        if(n == 0) break ;
        flag=0 ;
        for(a=0 ; a<n ; a++)
            scanf("%ld",&ara[a]) ;
        printf("Sums of %ld:\n",num) ;
        rec(0,num) ;
        if(flag == 0)
            printf("NONE\n") ;
    }
}

/*
4 6 4 3 2 2 1 1
5 3 2 1 1
400 12 50 50 50 50 50 50 25 25 25 25 25 25
0 0
*/
