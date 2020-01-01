#include<stdio.h>
#include<string.h>
#define mx 100001
#define aa long long

struct info
{
    aa prop=0,sum=0;
} tree[mx*3];
aa arr[mx] ;

void update(aa node , aa b, aa e, aa i, aa j, aa x)
{
    if (i > e || j < b) return;
    if (b >= i && e <= j)
    {
        tree[node].sum+=(e-b+1)*x;
        tree[node].prop+=x;
        return;
    }

    aa Left=node<<1;
    aa Right=(node<<1)+1;
    aa mid=(b+e)>>1;

    update(Left,b,mid,i,j,x);
    update(Right,mid+1,e,i,j,x);
    tree[node].sum=tree[Left].sum+tree[Right].sum+(e-b+1)*tree[node].prop ;
}

aa query(aa node , aa b , aa e , aa i , aa j , aa carry=0)
{
    if (i > e || j < b)
        return 0;

    if(b>=i && e<=j)
        return tree[node].sum+carry*(e-b+1);

    aa Left=node<<1;
    aa Right=(node<<1)+1;
    aa mid=(b+e)>>1;

    aa p1 = query(Left, b , mid, i, j, carry+tree[node].prop);
    aa p2 = query(Right, mid+1, e, i, j,carry+tree[node].prop);

    return p1+p2;

}

void init(aa node, aa b, aa e)
{
    if(b==e)
    {
        tree[node].sum=arr[b];
        return;
    }
    aa Left=node<<1;
    aa Right=(node<<1)+1;
    aa mid=(b+e)>>1;
    init(Left,b,mid);
    init(Right,mid+1,e);
    tree[node].sum=tree[Left].sum+tree[Right].sum;
}

int main()
{
    aa loop , test , a , b , c , n , m , d ;
    scanf("%lld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {

        scanf("%lld%lld",&n,&m) ;

        for(a=0 ; a<n ; a++)
            arr[a]=tree[a].sum=tree[a].prop=0 ;
        for( ; a<=2*n+5 ; a++)
            tree[a].sum=tree[a].prop=0 ;

        printf("Case %lld:\n",loop) ;
        init(1,0,n-1) ;
        while(m--)
        {
            scanf("%lld",&a) ;

            if(a==0)
            {
                scanf("%lld%lld%lld",&b,&c,&d) ;
                update(1,0,n-1,b,c,d) ;
            }
            else if(a==1)
            {
                scanf("%lld%lld",&b,&c) ;
                printf("%lld\n",query(1,0,n-1,b,c)) ;
            }

        }
    }
    return 0 ;
}
