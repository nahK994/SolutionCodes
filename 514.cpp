#include<stdio.h>
#include<stack>
#include<string.h>
using namespace std ;

int main()
{
    stack<long>S , A ;
    long n , a , i , ara[1010] , j , true_value ;
    while(scanf("%ld",&n)!=EOF)
    {
        if(n==0) break ;
        while(1)
        {
            j=n ;
            true_value=1 ;
            scanf("%ld",&ara[0]) ;
            if(ara[0]==0) break ;
            for(i=1 ; i<n ; i++)
                scanf("%ld",&ara[i]) ;
            S.push(ara[n-1]) ;
            for(i=n-2 ; i>=0 && true_value==1 ; i--)
            {
                if(S.top()<ara[i]) S.push(ara[i]) ;
                else
                {
                    while(S.empty()==false && S.top()>ara[i])
                    {
                        if(S.top()!=j)
                        {
                    //        printf("H j = %ld S = %ld\n",j,S.top()) ;
                            true_value=0 ;
                            break ;
                        }
                        j-- ;
                        S.pop() ;
                    }
                    S.push(ara[i]) ;
                }
            }
            while(S.empty()==false && true_value==1)
            {
                if(S.top()!=j)
                {
                 //   printf("D j = %ld S = %ld\n",j,S.top()) ;
                    true_value=0 ;
                    break ;
                }
                j-- ;
                S.pop() ;
            }
            if(true_value==1) printf("Yes\n") ;
            else printf("No\n") ;
            while(S.empty()==false) S.pop() ;
        }
        printf("\n") ;
    }
    return 0 ;
}
