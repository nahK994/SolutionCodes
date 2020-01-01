#include<stdio.h>
#include<string.h>

int main()
{
    long i , j , z , a , ara[26] , b , c , max , d , e ;
    char ch[1000] ;
     for(i=0 ; i<26 ; i++)
            ara[i]=0 ;
    scanf("%ld",&j) ;
    for(d=0 ; d<=j ; d++)
    {
        gets(ch) ;
        for(a=0 ; a<strlen(ch) ; a++)
        {
            if(ch[a]>=65 && ch[a]<=90)
            {
                z=ch[a]-64 ;
                ara[z-1]++ ;
            }
            else if(ch[a]>=97 && ch[a]<=122)
            {
                z=ch[a]-96 ;
                ara[z-1]++ ;
            }
        }
    }
        for(b=0 ; b<26 ; b++)
        {
            max=0 ;
            for(c=0 ; c<26 ; c++)
                if(max<ara[c])
                {
                    max=ara[c] ;
                    d=c ;
                }
            if(max!=0) printf("%c %ld\n",d+65,max) ;
            else break ;
            ara[d]=0 ;
        }
    return 0 ;
}
