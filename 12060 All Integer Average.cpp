#include<stdio.h>
#include<math.h>

int g(int a , int b)

{
    int i=1 , j ;
    if(a>b)
    j=b ;
    else j=a ;
    while(i<=j)
    {
        if(a%i==0 && b%i==0)
        {
            a=a/i ;
            b=b/i ;
        }
        i++ ;
    }
    return b ;
}

int main ()

{
    int n , e=1 ;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
        break ;
        int  sum=0 , ara[10000]={0} , i , j , p , q ;
        for(i=0 ; i<n ; i++)
        scanf("%d",&ara[i]) ;
        for(j=0 ; j<n ; j++)
        sum=sum+ara[j] ;
        if(sum%n==0)
        {
            if(sum>=0)
            printf("Case %d:\n%d\n",e,sum/n) ;
            else printf("Case %d:\n- %d\n",e,-1*sum/n) ;
        }
        else
        {
          if(sum<0)
          {
              p=g(n,-1*sum%n) ;
              q=g(-1*sum%n,n) ;
          }
          else
          {
             p=g(n,sum%n) ;
             q=g(sum%n,n) ;
          }
          if(sum/n<0)
          {
             printf("Case %d:\n",e) ;
             printf("   %d\n",p) ;
             printf("- %d-\n",-1*sum/n) ;
             printf("   %d\n",q) ;
          }
          else if(sum/n>0)
          {
             printf("Case %d:\n",e) ;
             printf(" %d\n",p) ;
             printf("%d-\n",sum/n) ;
             printf(" %d\n",q) ;
          }
          else if(sum/n==0 && sum>=0)
          {
             printf("Case %d:\n",e) ;
             printf("%d\n",p) ;
             printf("-\n") ;
             printf("%d\n",q) ;
          }
          else if(sum/n==0 && sum<0)
          {
             printf("Case %d:\n",e) ;
             printf("  %d\n",p) ;
             printf("- -\n") ;
             printf("  %d\n",q) ;
          }
        }
        e++ ;
    }
    return 0 ;
}
