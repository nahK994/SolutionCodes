#include<stdio.h>
#include<string.h>

long M9(char p[1000000])

{
    long j=strlen(p) , sum=0 , i ;
    for(i=0 ; i<j ; i++)
    sum=sum+p[i]-48 ;
    if(sum%9==0) return 0 ;
    return 1 ;
}

long g(long n)
{
    long j , sum=0 ;
    while(n!=0)
    {
       j=n%10 ;
       sum=sum+j ;
       n=n/10 ;
    }
    return sum ;
}

long h(char p[100000])
{
    long sum=0 , j=strlen(p) , i , count=1 ;
    for(i=0 ; i<j ; i++)
    sum=sum+p[i]-48 ;
    while(sum>9)
    {
        sum=g(sum) ;
        count++ ;
    }
    return count ;
}

int main ()

{
    char p[100000]={0} ;
    while(gets(p))
    {
        if(strlen(p)==1 && p[0]==48) break ;
        long a=M9(p) , b ;
        if(a%9==0)
        {
            b=h(p) ;
            printf("%s is a multiple of 9 and has 9-degree %ld.\n",p,b) ;
        }
        else printf("%s is not a multiple of 9.\n",p) ;
        p[100000]={0} ;
    }
    return 0 ;
}
