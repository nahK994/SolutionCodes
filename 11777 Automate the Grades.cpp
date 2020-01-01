#include<stdio.h>

int main ()

{
    long i , j , x , y , z , p , b , a[3] , min , s , c ;
    scanf("%ld",&j) ;
    for(i=1 ; i<=j ; i++)
    {
       scanf("%ld%ld%ld%ld",&x,&y,&z,&p) ;
       for(b=0 ; b<3 ; b++)
       scanf("%ld",&a[b]) ;
       min=a[0] ;
       for(c=0 ; c<3 ; c++)
       if(a[c]<min) min=a[c] ;
       s=(a[0]+a[1]+a[2]-min)/2 ;
       s=s+x+y+z+p ;
       if(s>=90) printf("Case %ld: A\n",i) ;
       else if(s<90 && s>=80) printf("Case %ld: B\n",i) ;
       else if(s<80 && s>=70) printf("Case %ld: C\n",i) ;
       else if(s<70 && s>=60) printf("Case %ld: D\n",i) ;
       else if(s<60) printf("Case %ld: F\n",i) ;
    }
    return 0 ;
}
