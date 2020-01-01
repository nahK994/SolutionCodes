#include<stdio.h>
#include<math.h>

int main()
{
    double a , b , c ;
    long i , j , d ;
    scanf("%ld",&j) ;
    for(i=1 ; i<=j ; i++)
    {
        c=0 ;
        scanf("%lf",&a) ;
        a=a-180000 ;
        if(a>=300000)
        {
            c=c+30000 ;
            a=a-300000 ;
        }
        else if(a>0)
        {
            c=c+a*0.1 ;
            a=0 ;
        }
        if(a>=400000)
        {
            c=c+60000 ;
            a=a-400000 ;
        }
        else if(a>0)
        {
            c=c+a*0.15 ;
            a=0 ;
        }
        if(a>=300000)
        {
            c=c+60000 ;
            a=a-300000 ;
        }
        else if(a>0)
        {
            c=c+a*0.2 ;
            a=0 ;
        }
        if(a>0) c=c+a*0.25 ;
       // printf("%lf\n",c) ;
        if(c>0 && c<=2000) c=2000 ;
        c=ceil(c) ;
        d=(int)c ;
        printf("Case %ld: %ld\n",i,d) ;
    }
   // printf("%ld\n",20000000-180000) ;
    return 0 ;
}
