#include<stdio.h>

int main ()

{
    float h , m ;
    char c ;
    while(scanf("%f%c%f",&h,&c,&m)!=EOF)
    {
        if(h==0 && m==0)
        break ;
        float a=30*h-11*m/2 ;
        if(a<0)
        a=-1*a ;
        if(a>180)
        printf("%0.3f\n",360-a) ;
        else printf("%0.3f\n",a) ;
    }
    return 0 ;
}
