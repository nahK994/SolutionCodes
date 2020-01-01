#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
    long loop , test ;
    double x , L , W ;
    scanf("%ld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        scanf("%lf%lf",&L,&W) ;
        x = ((L+W) - sqrt(L*L+W*W-L*W))/6.0 ;
        printf("Case %ld: %0.9lf\n",loop,(L-2*x)*(W-2*x)*x) ;
    }
    return 0 ;
}
