#include<stdio.h>
#include<math.h>
#define pi 2*acos( 0.0 )

int main ()

{
      int i, j ;
      scanf("%d",&j) ;
      for( i=1 ; i<=j ; i++ )
            {
                  double x, y, z ;
                  scanf("%lf%lf%lf",&x,&y,&z) ;
                  double a=x+y , b=x+z , c=y+z ;
                  double s=0.5*( a+b+c ) ;
                  double area1=s*( s-a )*( s-b )*( s-c ) ;
                  area1=sqrt(area1) ;
                  double angle1=acos(( a*a+b*b-c*c )/(2*a*b) ) ;
                  double area2=(angle1/(2*pi))*pi*x*x ;
                  double angle2=acos(( a*a-b*b+c*c )/(2*a*c) ) ;
                  double area3=(angle2/(2*pi))*pi*y*y ;
                  double angle3=acos(( b*b+c*c-a*a )/(2*c*b) ) ;
                  double area4=(angle3/(2*pi))*pi*z*z ;
                  double area=area1-area2-area3-area4 ;
                  printf("Case %d: %.10lf\n",i,area) ;
            }
            return 0 ;
}

