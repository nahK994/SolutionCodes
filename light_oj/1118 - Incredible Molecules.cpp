#include <stdio.h>
#include <math.h>
#include<stdlib.h>
#define PI acos(-1.0)
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))

double Deal ()
{
    int x1,y1,r1,x2,y2,r2;
    scanf("%d%d%d%d%d%d",&x1,&y1,&r1,&x2,&y2,&r2);
    double dis=sqrt(1.0*(x1-x2)*(x1-x2)+1.0*(y1-y2)*(y1-y2));
    if (dis<=abs(r1-r2))
        return PI*MIN(r1,r2)*MIN(r1,r2);
    else if (dis>=r1+r2)
        return 0;
    else
    {
        double temp=acos((r1*r1+r2*r2-dis*dis)/(2*r1*r2));
        temp=r1*r2*sin(temp);
        double temp1=acos((r1*r1+dis*dis-r2*r2)/(2*r1*dis));
        temp1=temp1*r1*r1;
        double temp2=acos((r2*r2+dis*dis-r1*r1)/(2*r2*dis));
        temp2=temp2*r2*r2;
        return temp1+temp2-temp;
    }
}

int main ()
{
    int T;
    scanf("%d",&T);
    for (int cas=1;cas<=T;cas++)
        printf("Case %d: %.8lf\n",cas,Deal());
    return 0;
}
