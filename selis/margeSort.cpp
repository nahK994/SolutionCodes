#include<bits/stdc++.h>
using namespace std;

long P[600], Q[600];
void margeSort(long *ara, long a, long b)
{
    if(a >= b) return ;
    long mid = (a+b)/2, p=0, q=0, r=0;
    margeSort(ara, a, mid);
    margeSort(ara, mid+1, b);

    for(int i=a ; i<=mid ; i++)
        P[i-a] = ara[i];
    for(int i=mid+1 ; i<=b ; i++)
        Q[i-(mid+1)] = ara[i];


    while(p<=(mid-a) || q<=(b-mid-1))
    {
        if(p>(mid-a) && q<=(b-mid-1))
            ara[a+(r++)] = Q[q++];
        else if(p<=(mid-a) && q>(b-mid-1))
            ara[a+(r++)] = P[p++];
        else 
        {
            if(P[p] < Q[q])
                ara[a+(r++)] = P[p++];
            else
                ara[a+(r++)] = Q[q++];
        }
    }
}

int main()
{
    long a, b, c, n, ara[1000];

    scanf("%ld", &n);
    for(int i=0 ; i<n ; i++)
        scanf("%ld", &ara[i]);

    margeSort(ara, 0, n-1);

    for(int i=0 ; i<n ; i++)
        printf("%ld\n", ara[i]);
    return 0;
}