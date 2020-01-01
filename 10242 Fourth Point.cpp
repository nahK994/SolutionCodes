#include<stdio.h>

int main ()

{
    double ara[8] ;
    long x , y , i ;
    while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&ara[0],&ara[1],&ara[2],&ara[3],&ara[4],&ara[5],&ara[6],&ara[7])!=EOF)
    {
        double sumx=0 , sumy=0 ;
        for(x=0 ; x<7 ; x+=2)
        {
            for(y=x+2 ; y<=7 ; y+=2)
            {
              if(ara[x]==ara[y] && ara[x+1]==ara[y+1])
              break ;
            }
            if(ara[x]==ara[y] && ara[x+1]==ara[y+1])
            break ;
        }
        for(i=0 ; i<=6 ; i+=2)
        {
            sumx=sumx+ara[i] ;
            sumy=sumy+ara[i+1] ;
        }
        sumx=sumx-3*ara[x] ;
        sumy=sumy-3*ara[x+1] ;
        printf("%0.3lf %0.3lf\n",sumx,sumy) ;
    }
    return 0 ;
}
