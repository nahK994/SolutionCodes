#include<stdio.h>
#include<math.h>

long s(long n)

{
   long a=n*(n+1)/2 ;
   return a ;
}

int main ()

{
    long a , b ;
    while(scanf("%ld%ld",&a,&b)!=EOF)
    {
        if(a<0 && b<0)
        break ;
        long sum=0 , a1 , b1 , a2 , b2 , i ;
        a1=ceil((double)a/10) ;
        b1=b/10 ;
        if(b1-a1==0 && b%10==0)
        sum=(b1-a1+1)*45 ;
        else sum=(b1-a1)*45 ;
        if(a%10!=0)
        sum=sum+s(b%10) ;
        if(b%10!=0)
        sum=sum+45-s(a%10-1) ;
        for(i=a1*10 ; i<=b1*10 ; i+=10)
        {
          //  printf("h") ;
            while(i%10==0)
            {
              //  printf("j") ;
                i=i/10 ;
            }
            sum=sum+i%10 ;
        }
        printf("%ld\n",sum) ;
    }
    return 0 ;
}
