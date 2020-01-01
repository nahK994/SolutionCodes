#include<stdio.h>

int main ()

{
    int n ;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0) break ;
        int count=0 , c ;
        while(n>=3)
        {
            c=n/3 ;
            count=count+c ;
            n=c+n%3 ;
        }
        if(n==2) printf("%d\n",count+1) ;
        else printf("%d\n",count) ;
    }
    return 0 ;
}

