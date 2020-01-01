#include<stdio.h>

int main ()

{
    int n ;
    while(scanf("%d",&n)!=EOF)
    {
        int count=0 , c , a=n ;
        while(n>=3)
        {
            c=n/3 ;
            count=count+c ;
            n=c+n%3 ;
        }
        if(n==2) printf("%d\n",count+1+a) ;
        else printf("%d\n",count+a) ;
    }
    return 0 ;
}


