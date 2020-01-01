#include <bits/stdc++.h>
using namespace std;
struct ans
{
    long long x,y;
};

bool cmp(ans a, ans b)
{
    if(a.x==b.x)
        return a.y>b.y;
    return a.x<b.x;
}

int main()
{
    ans data[1005];
    long loop , test , i , j , Count=0;
    for(i=1; i<=1000; i++)
    {
        for(j=1; j<=i; j++)
            if(i%j==0)
                Count+=1;
        data[i].x=Count;
        data[i].y=i;
        Count=0;
    }
    sort(data,data+1001,cmp);
    scanf("%ld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        scanf("%ld",&i) ;
        printf("Case %ld: %ld\n",loop,data[i].y) ;
    }

    return 0;
}
