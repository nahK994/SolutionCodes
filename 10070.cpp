#include<stdio.h>
#include<string.h>

long L(char p[1000000])

{
    long j=strlen(p) ;
    long a , b ;
    a=10*(p[j-2]-48)+p[j-1]-48 ;
    b=10*(p[j-4]-48)+p[j-3]-48 ;
    if(a%4==0 && a%100!=0) return 0 ;
    else if(a%4==0 && a%100==0 && b%4==0) return 0 ;
    return 1 ;
}

long M5(char p[1000000])

{
    long j=strlen(p) ;
    if(p[j-1]=='5' || p[j-1]=='0') return 0 ;
    return 1 ;
}

long M3(char p[1000000])

{
    long j=strlen(p) , sum=0 , i ;
    for(i=0 ; i<j ; i++)
    sum=sum+p[i]-48 ;
    if(sum%3==0) return 0 ;
    return 1 ;
}

long M11(char p[1000000])

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
    char p[1000000]={0} ;
    int t=0 ;
    while(gets(p))
    {
        if(t>0) printf("\n") ;
        long a=M5(p) , b=M3(p) , c=M11(p) , d=L(p) ;
        if(d==0)
        printf("This is leap year.\n") ;
        if(a==0 && b==0)
        printf("This is huluculu festival year.\n") ;
        if(a==0 && c==0 && d==0)
        printf("This is bulukulu festival year.\n") ;
        else if(d==1 && (a==1 || b==1) && (a==1 || c==1 || d==1))
        printf("This is an ordinary year.\n") ;
        t=1 ;
    }
    return 0 ;
}
