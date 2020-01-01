#include<stdio.h>

int main ()

{
    long unsigned i , j ;
    while(scanf("%lu%lu",&i,&j)!=EOF)
    {
        if(i==0 && j==0) break ;
        long unsigned a , b , c=0 , count=0 ;
        while(i!=0 || j!=0)
        {
            a=i%10 ;
            b=j%10 ;
            if(a+b+c>=10)
            {
                count++ ;
                c=1 ;
            }
            else c=0 ;
            i=i/10 ;
            j=j/10 ;
        }
        if(count!=0 &&count!=1) printf("%lu carry operations.\n",count) ;
        else if(count==1) printf("1 carry operation.\n") ;
        else printf("No carry operation.\n") ;
    }
    return 0 ;
}
