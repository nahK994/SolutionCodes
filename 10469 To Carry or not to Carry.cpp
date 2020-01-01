#include<stdio.h>

int main ()

{
    long unsigned a , b , c ;
    while(scanf("%lu%lu",&a,&b)!=EOF)
    {
        /*if(a==0 || b==0)
        {
            printf("%lu\n",a+b) ;
            continue ;
        }
        long unsigned ara1[100]={0} , ara2[100]={0} , ara3[100]={0} , i=0 , j=0 , p=1 ,sum=0 ;
        while(a!=0 || b!=0)
        {
            ara1[i]=a%2 ;
            ara2[i]=b%2 ;
            a=a/2 ;
            b=b/2 ;
            i++ ;
        }
        i=i-1 ;
        for( ; j<=i ; j++)
        {
            if(ara1[j]==0 && ara2[j]==0) ara3[j]=0 ;
            else if((ara1[j]==0 && ara2[j]==1) || (ara1[j]==1 && ara2[j]==0)) ara3[j]=1 ;
            sum=sum+p*ara3[j] ;
            p=p*2 ;
        }
        printf("%lu\n",sum) ;*/
        c=a^b ;
        printf("%lu\n",c) ;
    }
    return 0 ;
}
