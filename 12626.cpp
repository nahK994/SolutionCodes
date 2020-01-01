#include<stdio.h>
#include<string.h>

int main()
{
    long m , a , r , g , i , t , p , q , o , w ;
    char ch[1000] , v ;
    scanf("%ld ",&q) ;
    for(p=1 ; p<=q ; p++)
    {
        gets(ch) ;
      //  puts(ch) ;
       m=0 ;
       a=0 ;
       r=0 ;
       g=0 ;
       i=0 ;
       t=0 ;
       for(o=0 ; o<strlen(ch) ; o++)
       {
           v=ch[o] ;
           if(v=='M') m++ ;
           else if(v=='A') a++ ;
           else if(v=='R') r++ ;
           else if(v=='G') g++ ;
           else if(v=='I') i++ ;
           else if(v=='T') t++ ;
       }
       w=m ;
       if(w>(a/3))
       {
           w=a/3 ;
           //printf("T\n") ;
       }
       if(w>r/2) w=r/2 ;
       if(w>g) w=g ;
       if(w>i) w=i ;
       if(w>t) w=t ;
       printf("%ld\n",w) ;
    }
    return 0 ;
}
