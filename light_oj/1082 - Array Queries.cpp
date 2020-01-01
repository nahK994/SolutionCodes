#include<stdio.h>
#include<string.h>

long ara[100000] , ans[300000] , Root , End ;

/*struct ad
{
    long a , b ;
} sd[1000] ;*/

void ini(long node , long root , long end)
{
    long left , right , mid ;
    if(root==end)
    {
        ans[node]=ara[root] ;
       // sd[node].a=sd[node].b=root ;
        return ;
    }
    left=2*node ;
    right=2*node+1 ;
    mid=(root+end)/2 ;
    ini(left,root,mid) ;
    ini(right,mid+1,end) ;
    if(ans[left]<ans[right]) ans[node]=ans[left] ;
    else ans[node]=ans[right] ;
  /*  sd[node].a=root ;
    sd[node].b=end ;*/
}

long find_ans(long node , long first , long last)
{
    long left , right , mid , a , b ;
    if(first>End || last<Root) return 200000 ;
    if(Root<=first && End>=last) return ans[node] ;
    mid=(first+last)/2 ;
    left=2*node ;
    right=2*node+1 ;
    a=find_ans(left , first , mid) ;
    b=find_ans(right , mid+1 , last) ;
    if(a<b) return a ;
    return b ;
}

int main()
{
    long loop , test , n , i , j , m , a , b ;
    scanf("%ld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        printf("Case %ld:\n",loop) ;
        scanf("%ld%ld",&n,&m) ;
        for(i=1 ; i<=n ; i++)
            scanf("%ld",&ara[i]) ;
        ini(1,1,n) ;
       /* for(i=1 ; i<=3*n ; i++)
            printf("%ld - %ld -> %ld\n",sd[i].a,sd[i].b,ans[i]) ;*/
        for(i=1 ; i<=m ; i++)
        {
            scanf("%ld%ld",&Root,&End) ;
            a=find_ans(1 , 1 , n) ;
            printf("%ld\n",a) ;
        }
        memset(ara,0,sizeof(ara)) ;
        memset(ans,0,sizeof(ans)) ;
    }
    return 0 ;
}
