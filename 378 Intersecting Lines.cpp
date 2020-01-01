#include<stdio.h>

int main ()

{
    int i , j , b ;
    scanf("%d",&j) ;
    printf("INTERSECTING LINES OUTPUT\n") ;
    for(i=1 ; i<=j ; i++)
    {
        int a[10] ;
        for(b=0 ; b<8 ; b++)
        scanf("%d",&a[b]) ;
        double D , D1 ;
        D=(double)(a[3]-a[1])*(a[4]-a[6])-(a[7]-a[5])*(a[0]-a[2]) ;
        if(a[3]==a[1] && a[7]==a[5]) D1=(double)((a[0]-a[2])*(a[5]*a[6]-a[4]*a[7])-(a[1]*a[2]-a[0]*a[3])*(a[4]-a[6])) ;
        else D1=(double)((a[1]*a[2]-a[0]*a[3])*(a[7]-a[5])-(a[3]-a[1])*(a[5]*a[6]-a[4]*a[7])) ;
        if(D==0 && D1==0) printf("LINE\n") ;
        else if(D==0 && D1!=0) printf("NONE\n") ;
        else
        {
            double X=(double)((a[0]-a[2])*(a[5]*a[6]-a[4]*a[7])-(a[1]*a[2]-a[0]*a[3])*(a[4]-a[6]))/D ;
            double Y=(double)((a[1]*a[2]-a[0]*a[3])*(a[7]-a[5])-(a[3]-a[1])*(a[5]*a[6]-a[4]*a[7]))/D ;
            printf("POINT %0.2lf %0.2lf\n",X,Y) ;
        }
    }
    printf("END OF OUTPUT\n") ;
    return 0 ;
}
