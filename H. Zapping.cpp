#include<stdio.h>

int main ()

{
    long n , a , b ;
    scanf("%ld%ld",&a,&b) ;
    while(a!=-1 && b!=-1)
    {
       if(b>a) n=b-a ;
       else n=a-b ;
       if(n<100-n) printf("%ld\n",n) ;
       else printf("%ld\n",100-n) ;
       scanf("%ld%ld",&a,&b) ;
    }
    return 0 ;
}
