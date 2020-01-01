#include<stdio.h>

int main ()

{
    int a[10] ;
    while(scanf("%d%d%d%d%d%d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5])!=EOF)
    {
       if(a[0]==0 && a[1]==0 && a[2]==0 && a[3]==0 && a[4]==0 && a[5]==0) break ;
       float d=a[0]*a[4]-a[3]*a[1] ;
       if(d==0)
       {
           printf("No fixed point exists.\n") ;
           continue ;
       }
       float dx=a[2]*a[4]-a[1]*a[5] , dy=a[0]*a[5]-a[2]*a[3] ;
       float X=(double)(dx/d) , Y=(double)(dy/d) ;
       printf("The fixed point is at %0.2f %0.2f.\n",X,Y) ;
    }
    return 0 ;
}
