#include<stdio.h>
#include<math.h>

int main ()

{
    long a;
    while(scanf("%ld",&a)!=EOF)
    {
		 long b , c , d , e , g , count=0 ,ara1[100000]={0};
         g=a ;
         if(a==0)
         break ;
         if(a==1)
         {
             count=0 ;
             printf("%ld : %ld\n",a,count) ;
         }
         d=1 ;
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
         for(e=1; e<d; e++)
         {
             if(ara1[e]!=ara1[e+1])
             {
                 count++ ;
             }
         }
         if(g==2)
         {
            count=1 ;
            printf("%ld : %ld\n",g,count) ;
         }
         else if(d==1)
         {
            count=1 ;
            printf("%ld : %ld\n",g,count) ;
         }
         else if(d!=1)
         {
           printf("%ld : %ld\n",g,count+1) ;
         }
    }
    return 0 ;
}

