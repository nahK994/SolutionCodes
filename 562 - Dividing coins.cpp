#include <cstdlib>
#include <algorithm>
#include <climits>
#include <cstdio>
using namespace std;
#define DUMMY 5454
long A[25000+5];

long wt[100+5];
long knapSack(long N, long W)
{
    for(int i = 0; i<= W; i++)
        A[i] = 0;

    for(int i=1 ;  i<=N ; i++)
        for(int j=W ; j>0 ; j--)
            if(j>=wt[i])
                A[j] = max( A[j] , wt[i]+A[j-wt[i]] ) ;

    return A[W];
}

int main()
{

    long test, sum, n;
    scanf("%ld", &test);
    while(test--)
    {
        scanf("%ld", &n);
        sum = 0;
        for(int i = 1; i<=n; i++)
        {
            scanf("%ld", &wt[i]);
            sum +=wt[i];
        }

        printf("%ld\n", sum - 2*knapSack(n, sum/2));
    }
    return 0;
}
