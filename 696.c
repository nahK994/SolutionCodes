#include<stdio.h>

int main()
{
    long m , n , c , a ;
    while(scanf("%ld%ld",&m,&n)!=EOF)
    {
        if(m==0 && n==0) break ;
        if(m==0 || n==0)
        printf("0 knights may be placed on a %ld row %ld column board.\n",m,n) ;
        else if(m==1 || n==1)
        {
            if(m>n)
            printf("%ld knights may be placed on a %ld row %ld column board.\n",m,m,n) ;
            else
            printf("%ld knights may be placed on a %ld row %ld column board.\n",n,m,n) ;
        }
        else if(m==2 || n==2)
        {
            c=m*n ;
            if(c%4==0 && c%8==0)
            {
                c=c/4 ;
                c=(c/2) ;
                c=4*c ;
            }
            else if(c%4==0 && c%8!=0)
            {
                c=c/4 ;
                c=c-(c/2) ;
                c=4*c ;
            }
            else if(c%4!=0 && (c/4)%2!=0)
            {
                c=c/4 ;
                c=c-(c/2) ;
                c=4*c ;
              //  printf("M\n") ;
            }
            else if(c%4!=0 && (c/4)%2==0)
            {
                c=4*(c/8)+(c%4) ;
              //  printf("N\n") ;
            }
            printf("%ld knights may be placed on a %ld row %ld column board.\n",c,m,n) ;
        }
        else
        {
            c=n*(m/2)+(m%2)*(n-(n/2)) ;
             printf("%ld knights may be placed on a %ld row %ld column board.\n",c,m,n) ;
        }
    }
    return 0 ;
}
