#include<stdio.h>
#include<string.h>

long M11(char p[100000])

{
    long j=strlen(p) , sum1=0 , i , a , sum2=0 , sum3 ;
    for(i=0 ; i<j ; i=i+2)
    sum1=sum1+p[i]-48 ;
    for(a=1 ; a<j ; a=a+2)
    sum2=sum2+p[a]-48 ;
    sum3=sum1-sum2 ;
    if(sum3%11==0) return 0 ;
    return 1 ;
}

int main ()

{
    char p[100000]={0} ;
    while(gets(p))
    {
        long a=strlen(p) , b=M11(p) ;
        if(a==1 && p[0]==48) break ;
        if(b==0) printf("%s is a multiple of 11.\n",p) ;
        else printf("%s is not a multiple of 11.\n",p) ;
        p[100000]={0} ;
    }
}
