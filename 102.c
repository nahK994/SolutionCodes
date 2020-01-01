#include<stdio.h>

int main()
{
    long b1 , g1 , c1 , b2 , g2 , c2 , b3 , g3 , c3, i , a[6] , min , min_index ;
    while(scanf("%ld%ld%ld%ld%ld%ld%ld%ld%ld",&b1,&g1,&c1,&b2,&g2,&c2,&b3,&g3,&c3)!=EOF)
    {
        a[0]=b2+b3+c1+c3+g1+g2;
        a[1]=b2+b3+c1+c2+g1+g3;
        a[2]=b1+b3+c2+c3+g1+g2;
        a[3]=b1+b2+c2+c3+g1+g3;
        a[4]=b1+b3+c1+c2+g3+g2;
        a[5]=b2+b1+c1+c3+g3+g2;
        min=a[0] ;
        min_index=0 ;
        for(i=1 ; i<6 ; i++)
            if(min>a[i])
            {
                min=a[i] ;
                min_index=i ;
            }

        if(min_index==0) printf("BCG ") ;
        else if(min_index==1) printf("BGC ") ;
        else if(min_index==2) printf("CBG ") ;
        else if(min_index==3) printf("CGB ") ;
        else if(min_index==4) printf("GBC ") ;
        else if(min_index==5) printf("GCB ") ;
        printf("%ld\n",a[min_index]) ;

    }
    return 0;
}
