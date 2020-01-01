#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define eps 1e-9
#define pi 2*acos(0.0)

int main ()

{
    //double eps=0 ;
    double g1, f1, r1, g2, f2, r2, a, b, c, t, x1, x2, y1, y2, d, h, x, y, l1, l2, q1, c1, c2 ;
    while(scanf("%lf%lf%lf%lf%lf%lf",&g1,&f1,&r1,&g2,&f2,&r2)!=EOF)
    {
        a=sqrt((g1-g2)*(g1-g2)+(f1-f2)*(f1-f2)) ;
        r1=abs(r1) ;
        r2=abs(r2) ;
        if(r1>r2) q1=r1-r2 ;
        else q1=r2-r1 ;
        if(g1==g2 && f1==f2 && (r1!=r2 || (r1==0 && r2==0)))
            printf("(%0.3lf,%0.3lf)\n",g1,f1) ;
        else if(r1+r2<a || (q1!=0 && a!=0 && q1>a) || (r1==0 && r2!=0 && r2!=a) || (r1!=0 && r2==0 && r1!=a))
            printf("NO INTERSECTION\n") ;
        else if(g1==g2 && f1==f2 && r1==r2)
            printf("THE CIRCLES ARE THE SAME\  n") ;
        else if(q1!=0 && a!=0 && q1==a)
        {
           if(r1>r2)
           {
               x=((r1*g2-r2*g1)/q1)+eps ;
               y=((r1*f2-r2*f1)/q1)+eps ;
           }
           else
           {
               x=((r2*g1-r1*g2)/q1)+eps ;
               y=((r2*f1-r1*f2)/q1)+eps ;
           }
           printf("(%0.3lf,%0.3lf)\n",x,y) ;
        }
        else if(r1+r2==a)
        {
           x=((g1*r2+g2*r1)/(r1+r2))+eps ;
           y=((f1*r2+f2*r1)/(r1+r2))+eps ;
           printf("(%0.3lf,%0.3lf)\n",x,y) ;
        }
        else
        {
            if(f1!=f2)
            {
               t=(g2-g1)/(f1-f2)+eps ;
               t=atan(t)+eps ;
            }
            else t=(pi/2.0)+eps ;
            c1=g1*g1+f1*f1-r1*r1+eps ;
            c2=g2*g2+f2*f2-r2*r2+eps ;
            x=((g1-g2)*(c1-c2)+2.0*(f1-f2)*(g1*f2-f1*g2))/(2.0*a*a)+eps ;
            y=(2.0*(g1-g2)*(g1*f2-g2*f1)+(f1-f2)*(c1-c2))/(2.0*a*a)+eps ;
            l1=sqrt((x-g1)*(x-g1)+(y-f1)*(y-f1))+eps ;
            h=sqrt(r1*r1-l1*l1)+eps ;
            x1=x+h*cos(t)+eps ;
            y1=y+h*sin(t)+eps ;
            x2=2.0*x-x1+eps ;
            y2=2.0*y-y1+eps ;
           // printf("x1=%0.3lf\ny1=%0.3lf\nx2=%0.3lf\ny2=%0.3lf\n",x1,y1,x2,y2) ;
            if(x2-x1>0.0)
            {
              //  printf("H1\n\n") ;
                printf("(%0.3lf,%0.3lf)(%0.3lf,%0.3lf)\n",x1,y1,x2,y2) ;
            }
            else if(x1-x2==0.0 && y2>y1)
            {
               // printf("H2\n\n") ;
                printf("(%0.3lf,%0.3lf)(%0.3lf,%0.3lf)\n",x1,y1,x2,y2) ;
            }
            else printf("(%0.3lf,%0.3lf)(%0.3lf,%0.3lf)\n",x2,y2,x1,y1) ;
        }
    }
    return 0 ;
}
