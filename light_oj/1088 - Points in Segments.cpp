#include<stdio.h>
#include<string.h>

long ara[100050] , N ;

long bs(long n)
{
    long max=N-1 , min=0 , mid ;
    while(min<max)
    {
        mid=(max+min)>>1 ;
        if(ara[mid]==n) return mid ;
        else if(ara[mid]>n)
            max=mid-1 ;
        else if(ara[mid]<n)
            min=mid+1 ;
    }
    //if(min==max && ara[min]==n) return min ;
    return min ;
}

int main()
{
    long loop , test , i , j , a , b , g , h , k , m ;
    scanf("%ld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        printf("Case %ld:\n",loop) ;
        scanf("%ld%ld",&N,&m) ;
        for(i=0 ; i<N ; i++) scanf("%ld",&ara[i]) ;
        for(i=1 ; i<=m ; i++)
        {
            scanf("%ld%ld",&j,&a) ;
            if(ara[0]>a || ara[N-1]<j) printf("0\n") ;
            else
            {
                b=bs(a) ;
                g=bs(j) ;
                if(j>ara[g]) g++ ;
                if(a<ara[b]) b-- ;
              //  printf("\n") ;
               // printf("b = %ld g = %ld\n",b,g) ;
                printf("%ld\n",b-g+1) ;
                //printf("\n") ;
            }
        }
        memset(ara,0,sizeof(ara)) ;
    }
    return 0 ;
}
