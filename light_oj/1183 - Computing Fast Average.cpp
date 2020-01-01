#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 111111;
int sum[MAXN<<2],cov[MAXN<<2],t,n,q;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
void build()
{
    memset(sum,0,sizeof(sum));
    memset(cov,-1,sizeof(cov));
}
void pushDOWN(int rt,int l,int r)
{
    if(cov[rt]!=-1)
    {
        int m = (l+r)>>1;
        sum[rt<<1] = (m-l+1)*cov[rt];
        sum[rt<<1|1] = (r-m)*cov[rt];
        cov[rt<<1] = cov[rt<<1|1] = cov[rt];
        cov[rt] = -1;
    }
}
void pushUP(int rt)
{
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
void update(int L,int R,int c,int l,int r,int rt)
{
    if(L<=l&&R>=r)
    {
        cov[rt] = c;
        sum[rt] = (r-l+1)*c;
        return;
    }
    pushDOWN(rt,l,r);
    int m = (l+r)>>1;
    if(m>=L)update(L,R,c,l,m,rt<<1);
    if(m<R)update(L,R,c,m+1,r,rt<<1|1);
    pushUP(rt);
}
int query(int L,int R,int l,int r,int rt)
{
    if(L<=l&&R>=r)
    {
        return sum[rt];
    }
    pushDOWN(rt,l,r);
    int m = (l+r)>>1,ret = 0;
    if(m>=L)ret+=query(L,R,l,m,rt<<1);
    if(m<R)ret+=query(L,R,m+1,r,rt<<1|1);
    pushUP(rt);
    return ret;
}
int gcd(int a,int b)
{
    return ((a%b)==0)?b:gcd(b,a%b);
}
void print(int cas,int mo,int so)
{
    int div = gcd(mo,so);
    mo/=div;
    so/=div;
    if(so==1)
    {
        printf("%d\n",mo);
    }
    else if(mo!=0)
    {
        printf("%d/%d\n",mo,so);
    }
    else
    {
        printf("%d\n",0);
    }
}
int main()
{
    scanf("%d",&t);
    for(int cas=1; cas<=t; cas++)
    {
        scanf("%d%d",&n,&q);
        build();
        printf("Case %d:\n",cas);
        while(q--)
        {
            int a,b,c,d;
            scanf("%d",&a);
            if(a==1)
            {
                scanf("%d%d%d",&b,&c,&d);
                update(b,c,d,0,n-1,1);
            }
            else
            {
                scanf("%d%d",&b,&c);
                int mo = query(b,c,0,n-1,1);
                print(cas,mo,(c-b+1));
            }
        }
    }
    return 0;
}
