#include<stdio.h>
#include<string.h>

long ara[1000]  , p[1000] , q[1000] ;

void marge(long l , long mid , long r)
{
      long i , j , a , b ;
      for(i=l ; i<=mid ; i++)
        p[i-l]=ara[i] ;

      for( ; i<=r ; i++)
        q[i-mid-1]=ara[i] ;

      i=j=a=0 ;
      while(i<=(mid-l) && j<=(r-mid-1))
      {
          if(p[i] <= q[j])
          {
              ara[a+l]=p[i] ;
              i++ ;
              a++ ;
          }
          else
          {
              ara[a+l]=q[j] ;
              j++ ;
              a++ ;
          }
      }

      while(i<=(mid-l))
      {
          ara[a+l]=p[i] ;
          a++ ;
          i++ ;
      }

      while(j<=(r-mid-1))
      {
          ara[a+l]=q[j] ;
          j++ ;
          a++ ;
      }
}

void Sort(long a, long b)
{
    if(a<b)
    {
        long c=(a+b)/2 ;
        Sort(a,c) ;
        Sort(c+1,b) ;
        marge(a,c,b) ;
    }
}

int main()
{
    long n , a , b , c ;
    scanf("%ld",&n) ;
    for(a=0 ; a<n ; a++)
        scanf("%ld",&ara[a]) ;

     Sort(0,n-1) ;
     for(a=0 ; a<n ; a++)
        printf("%ld\n",ara[a]) ;
}
