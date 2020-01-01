#include<stdio.h>

int main()
{
    long i , j , h , m , k , ans , p , q , h1 , m1 , r ;
    char c ;
    scanf("%ld",&j) ;
    for(i=1 ; i<=j ; i++)
    {
        scanf("%ld%ld%c%ld",&k,&h,&c,&m) ;
        scanf("%ld%c%ld%ld",&h1,&c,&m1,&q) ;
        if(h1>h || (h==h1 && m1>=m))
        ans=(60*h1+m1+q)-(60*h+m) ;
        else if(h1<h || ((h1-h)==0 && m1<m))
        ans=24*60+((60*h1+m1)-(60*h+m))+q ;
        //printf("%ld\n",ans) ;
        for(p=1 ; p<k ; p++)
        {
            scanf("%ld%c%ld%ld",&h1,&c,&m1,&q) ;
            if(h1>h || (h==h1 && m1>=m))
            r=(60*h1+m1+q)-(60*h+m) ;
            else if(h1<h || ((h1-h)==0 && m1<m))
            r=24*60+((60*h1+m1)-(60*h+m))+q ;
            if(ans>r)
            ans=r ;
        }
        printf("Case %ld: %ld\n",i,ans) ;
    }
    return 0 ;
}
