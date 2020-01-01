#include<bits/stdc++.h>
using namespace std ;

int main()
{
    long loop , test , a , b , c ;
    char ch[500] ;
    scanf("%ld",&test) ;
    for(loop=1 ; loop<=test ; loop++)
    {
        c=0 ;
        scanf("%ld",&b) ;
        scanf("%s",ch) ;
        for(a=0 ; a<b ; a++)
            if(ch[a] == '.')
            {
                //printf("a = %ld\n",a) ;
                c++ ;
                a+=2 ;
            }
            printf("Case %ld: %ld\n",loop,c) ;
    }
    return 0 ;
}
