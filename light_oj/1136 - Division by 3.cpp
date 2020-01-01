#include<stdio.h>

int main()
{
    long loop , test , A , B , sum , count , i ;
    scanf("%ld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        scanf("%ld%ld",&A,&B) ;
        A-- ;
        if((A+1)%3==0) A=(2*(A/3))+1 ;
        else A=2*(A/3) ;
        if((B+1)%3==0) B=(2*(B/3))+1 ;
        else B=2*(B/3) ;
        printf("Case %ld: %ld\n",loop,B-A) ;
    }
    return 0 ;
}
