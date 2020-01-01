#include<stdio.h>
#include<string.h>
long sum[300050] ;

void update(long node , long e , long f , long i , long j)
{
    long mid , left , right ;
    if(f<i || e>j) return ;
    if(e<=i && j<=f)
    {
        sum[node]++ ;
        return ;
    }
    mid=(i+j)/2 ;
    left=2*node ;
    right=2*node+1 ;
    update(left,e,f,i,mid) ;
    update(right,e,f,mid+1,j) ;
}

long query(long node , long e , long i , long j)
{
    long mid , left , right , q1 , q2 ;
    if(j<e || i>e) return 0 ;
    if(i==j)
    {
        return sum[node] ;
    }
    mid=(i+j)/2 ;
    left=2*node ;
    right=2*node+1 ;
    q1=query(left,e,i,mid) ;
    q2=query(right,e,mid+1,j) ;
    return q1+q2+sum[node] ;
}

int main()
{
    long loop , test , j , i , n , a , b , c , d ;
    char ch[100000] , cc , cd ;
    scanf("%ld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        printf("Case %ld:\n",loop) ;
        scanf("%s",ch) ;
        n=strlen(ch) ;
        n-- ;
            memset(sum,0,sizeof(sum)) ;
        scanf("%ld",&j) ;
        for(i=1 ; i<=j ; i++)
        {
            cd=getchar() ;
            scanf("%c",&cc) ;
            if(cc=='I')
            {
                scanf("%ld%ld",&a,&b) ;
                update(1,a-1,b-1,0,n) ;
            }
            else if(cc=='Q')
            {
                scanf("%ld",&a) ;
                b=query(1,a-1,0,n) ;
                if(b%2==0) printf("%c\n",ch[a-1]) ;
                else printf("%ld\n",49-ch[a-1]) ;
            }
        }
    }
}
