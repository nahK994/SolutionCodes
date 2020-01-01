#include<stdio.h>
#include<string.h>

double g(long n)
{
    long j ;
    long sum=0 ;
    while(n!=0)
    {
       j=n%10 ;
       sum=sum+j ;
       n=n/10 ;
    }
    return sum ;
}

double h(char c[30])

{
    long i , j ;
    double sum=0 ;
    j=strlen(c) ;
    for(i=0 ; i<j ; i++)
        {
           if(c[i]>64 && c[i]<91)
           sum=sum+c[i]-64 ;
           else if(c[i]>96 && c[i]<123)
           sum=sum+c[i]-96 ;
        }
        while(sum>=10)
        sum=g(sum) ;
        return sum ;
}

int main ()

{
    char c1[30] , c2[30] ;
    while(gets(c1),gets(c2))
    {
        double sum1=0 , sum2=0 , sum ;
        sum1=h(c1) ;
        sum2=h(c2) ;
        if(sum1>=sum2)
        sum=(sum2/sum1)*100 ;
        else sum=(sum1/sum2)*100 ;
        printf("%0.2lf %%\n",sum) ;
        c1[30]={0} ;
        c2[30]={0} ;
    }
    return 0 ;
}
