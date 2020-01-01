#include<stdio.h>

int main ()

{
    int i , j ;
    scanf("%d",&j) ;
    for(i=1 ; i<=j ; i++)
    {
        float c , d , C , F ;
        scanf("%f%f",&c,&d) ;
        F=(9*c/5)+32+d ;
        C=(5*F-160)/9 ;
        printf("Case %d: %0.2f\n",i,C) ;
    }
    return 0 ;
}
