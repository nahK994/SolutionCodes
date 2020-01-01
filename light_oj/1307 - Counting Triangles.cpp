#include<stdio.h>
#include<string.h>

void marge(long ara[] , long low , long mid , long high)
{
    long i , j , k , n1 , n2 ;
    n1=mid-low+1 ;
    n2=high-mid ;
    long p[n1] , q[n2] ;
    for(i=0 ; i<n1 ; i++)
        p[i]=ara[low+i] ;
    for(i=0 ; i<n2 ; i++)
        q[i]=ara[mid+1+i] ;
    i=j=0 ;
    k=low ;
    while(i<n1 && j<n2)
    {
        if(p[i]>q[j])
        {
            ara[k++]=q[j] ;
            j++ ;
        }
        else
        {
            ara[k++]=p[i] ;
            i++ ;
        }
    }
    while(i<n1)
    {
        ara[k++]=p[i] ;
        i++ ;
    }
    while(j<n2)
    {
        ara[k++]=q[j] ;
        j++ ;
    }
}

void sort(long ara[] , long i , long j)
{
    if(i==j) return ;
    long mid=i+(j-i)/2 ;
    sort(ara,i,mid) ;
    sort(ara,mid+1,j) ;
    marge(ara,i,mid,j) ;
}

long bs(long n , long ara[] , long min , long max)
{
    long mid ;
    while(min<max)
    {
        mid=(min+max)/2 ;
        if(ara[mid]==n) return mid ;
        else if(ara[mid]>n) max=mid-1 ;
        else min=mid+1 ;
    }
    return min ;
}

int main()
{
    long loop , test , i , j , a , b , n , ara[2050] , c , d , count ;
    scanf("%ld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        count=0 ;
        scanf("%ld",&n) ;
        for(i=0 ; i<n ; i++)
        scanf("%ld",&ara[i]) ;
     /*   for(i=0 ; i<n ; i++)
        printf("%ld ",ara[i]) ;
        printf("\n") ;*/
        sort(ara,0,n-1) ;
        for(i=0 ; i<n-2 ; i++)
         for(j=i+1 ; j<n-1 ; j++)
           {
               a=ara[j]-ara[i]+1 ; b=ara[i]+ara[j]-1 ;
               c=bs(a,ara,j+1,n-1) ; d=bs(b,ara,j+1,n-1) ;
               if(ara[c]<a) c++ ;
               if(ara[d]>b) d-- ;
            //   printf("ara[ i ] = %ld ara[ j ] = %ld c = %ld d = %ld\n\n",ara[i],ara[j],c,d) ;
               count+=(d-c+1) ;
           }
           printf("Case %ld: %ld\n",loop,count) ;
           memset(ara,0,sizeof(ara)) ;
    }
    return 0 ;
}
