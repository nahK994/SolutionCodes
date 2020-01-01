#include<iostream>
#include<queue>
#include<stdio.h>
using namespace std ;

int main()
{
    long n , a , b , i ;
    queue<long>q ;
    while(scanf("%ld",&n)!=EOF)
    {
        if(n==0) break ;
        for(i=1 ; i<=n ; i++) q.push(i) ;
        if(n!=1)
        {
            printf("Discarded cards: %ld",q.front()) ;
            q.pop() ;
            for(a=2 ; q.size()>1 ; a++)
            {
                if(a%2==1)
                {
                    printf(", %ld",q.front()) ;
                    q.pop() ;
                }
                else
                {
                    b=q.front() ;
                    q.pop() ;
                    q.push(b) ;
                }
            }
            printf("\nRemaining card: %ld\n",q.front()) ;
            q.pop() ;
        }
        else {printf("Discarded cards:\nRemaining card: 1\n") ; q.pop() ;}
        // printf(" %ld\n",q.front()) ; q.pop() ;

    }
    return 0 ;
}
