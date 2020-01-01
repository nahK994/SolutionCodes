#include<stdio.h>
#include<string.h>
#include<math.h>

long ston(char ch[])
{
    long i , j , sum=0 ;
    for(i=0 ; i<strlen(ch) ; i++)
    {
        if(ch[i]>=97 && ch[i]<=122) sum=sum+(ch[i]-96) ;
        else sum=sum+(ch[i]-38) ;
    }
    return sum ;
}

long prime_test(long n)
{
    long i , j=sqrt(n) ;
    if(n%2==0 && n!=2)
        return 0 ;
    for(i=3 ; i<=j+1 ; i+=2)
        if(n%i==0)
            return 0 ;
    return 1 ;
}

int main()
{
    char ch[1000] ;
    long i ;
    while(gets(ch))
    {
        i=ston(ch) ;
        i=prime_test(i) ;
        if(i==1)
            printf("It is a prime word.\n") ;
        else
            printf("It is not a prime word.\n") ;
    }
    return 0 ;
}
