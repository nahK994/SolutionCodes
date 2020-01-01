#include<stdio.h>
#include<string.h>
#include<math.h>

int main ()

{
    char c[100] ;
    while(gets(c))
    {
        int i , j , k , h , a , sum=0 ;
        j=strlen(c) ;
        for(i=0 ; i<j ; i++)
        {
            if(c[i]>='A' && c[i]<='Z')
            a=c[i]-38 ;
            else if(c[i]>='a' && c[i]<='z')
            a=c[i]-96 ;
            sum=sum+a ;
        }
        h=sqrt(sum) ;
        for(k=2 ; k<=h ; k++)
        {
            if(sum%k==0)
            {
                printf("It is not a prime word.\n") ;
                break ;
            }
        }
        if(k>h)
        printf("It is a prime word.\n") ;
        c[100]={0} ;
    }
}
