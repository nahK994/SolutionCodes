#include<stdio.h>
#include<math.h>

int main ()

{
    long a;
    while(scanf("%ld",&a)!=EOF)
    {
		long b , c , d , e , sum,ara1[100000]={0};

        if(a==0)
        break ;
        if(a<0)
         a=-1*a ;
        if(a==2 || a==1)
        {
         printf("-1\n") ;
         continue;
        }
         d=1 ;
         sum=0 ;
         c=sqrt(a) ;
         for(b=2 ; b<=c ; b++)
         {
            if(a==1)
            break ;
            else if(a%b==0)
            {
                ara1[d]=b ;
                a=a/b ;
                d++ ;
                b-- ;
            }
         }
         if(a==1)
         d=d-1 ;
         if(a!=1)
         ara1[d]=a ;
         long flag=0;
         for(e=1; e<=d-1; e++)
         {
             if(ara1[e]!=ara1[e+1])
             {
                 flag=1;
                 break;
             }
         }
         if(d==1)
         {
            printf("-1\n") ;
         }
         else if(flag==0)
         printf("-1\n") ;
         else if(d!=1)
         {
           printf("%ld\n",ara1[d]) ;
         }
    }
    return 0 ;
}
