#include<stdio.h>

int main()
{
    long ara[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97} ;
    long n , loop , test ;
    scanf("%ld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        long a , b=n , c , d=1 , flag=0 ;
        scanf("%ld",&n) ;
        printf("Case %ld: %ld =",loop,n) ;
        for(a=0 ; a<25 ; a++)
        {
            c=0 ;
            b=n ;
            while(b!=0)
            {
                b=b/ara[a] ;
                c=c+b ;
            }
            if(c==0) break ;
            if(flag == 0)
            {
                printf(" %ld (%ld)",ara[a],c) ;
                flag=1 ;
            }
            else printf(" * %ld (%ld)",ara[a],c) ;
        }
        printf("\n") ;
    }
}
